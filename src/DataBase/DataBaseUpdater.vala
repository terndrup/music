// -*- Mode: vala; indent-tabs-mode: nil; tab-width: 4 -*-
/*-
 * Copyright (c) 2012 Noise Developers (http://launchpad.net/noise)
 *
 * This software is licensed under the GNU General Public License
 * (version 2 or later). See the COPYING file in this distribution.
 *
 * The Noise authors hereby grant permission for non-GPL compatible
 * GStreamer plugins to be used and distributed together with GStreamer
 * and Noise. This permission is above and beyond the permissions granted
 * by the GPL license by which Noise is covered. If you modify this code
 * you may extend this exception to your version of the code, but you are not
 * obligated to do so. If you do not wish to do so, delete this exception
 * statement from your version.
 *
 * Authored by: Scott Ringwelski <sgringwe@mtu.edu>,
 *              Victor Eduardo <victoreduardm@gmail.com>
 */

public class Noise.DataBaseUpdater : Object {

    private DataBaseManager dbm;

    private Gee.LinkedList<Media> media_updates;
    private Gee.LinkedList<Object> to_remove;

    private bool in_update_thread = false;

    public DataBaseUpdater (DataBaseManager databm) {
        dbm = databm;

        media_updates = new Gee.LinkedList<Media> ();
        to_remove = new Gee.LinkedList<Object> ();

        // Save on a regular basis and before exit
        App.instance.shutdown.connect_after (() => on_close_ui_save ());
        App.instance.shutdown.connect_after (update_db_sync);
    }

    public async void removeItem (Object item) {
        lock (to_remove) {
            if (!to_remove.contains (item))
                to_remove.offer (item);
        }

        yield update_db_async ();
    }

    public async void update_media (Media s) {
        lock (media_updates) {
            if (!media_updates.contains (s))
                media_updates.offer (s);
        }

        yield update_db_async ();
    }

    private async void update_db_async () {
        // If many updates are being queued, we want to delay this as much as
        // possible in order to use the same thread. For data safety reasons,
        // we also want the main loop to trigger the update instead of the same
        // thread which invoked the public method (remove_item, update_media, etc. )
        Idle.add (update_db_async.callback);
        yield;

        // If an update thread is already running, just return, as the update
        // will be handled there.
        if (in_update_thread)
            return;

        message ("-- Starting database update.");

        in_update_thread = true;

        Threads.add (() => {
            update_db_sync ();
            Idle.add (update_db_async.callback);
        });

        yield;

        in_update_thread = false;
        message ("-- Finished database update.");
    }

    private void update_db_sync () {
        bool operation_done = false;

        do {
            operation_done = false;

            lock (media_updates) {
                if (media_updates.size > 0) {
                    dbm.update_media (media_updates);
                    media_updates.clear ();
                    operation_done = true;
                }
            }

            lock (to_remove) {
                Object? next = to_remove.poll ();

                if (next != null) {
                    if (next is Gee.LinkedList) {
                        dbm.remove_media (next as Gee.LinkedList<string>);
                    } else if (next is StaticPlaylist) {
                        dbm.remove_playlist (next as StaticPlaylist);
                        dbm.remove_columns_state (next as StaticPlaylist, null);
                    } else if (next is SmartPlaylist) {
                        dbm.remove_smart_playlist (next as SmartPlaylist);
                        dbm.remove_columns_state (null, next as SmartPlaylist);
                    } else
                        assert_not_reached ();

                    operation_done = true;
                }
            }
        } while (operation_done);
    }

    private bool on_close_ui_save () {
        var playlists_and_queue = new Gee.LinkedList<StaticPlaylist> ();
        playlists_and_queue.add_all (libraries_manager.local_library.get_playlists ());

        playlists_and_queue.add (((LocalLibrary)libraries_manager.local_library).p_music);

        debug ("-- Saving columns state preferences DB.");

        dbm.save_playlist (((LocalLibrary)libraries_manager.local_library).p_music);
        dbm.save_columns_state (playlists_and_queue, libraries_manager.local_library.get_smart_playlists ());

        debug ("-- Finished columns state preferences DB.");

        return true;
    }
    // If the name of the playlist changed, it provides the old name to remove it from database
    public void save_device (DevicePreferences device) {
        dbm.save_device (device);
    }
    
    // If the name of the playlist changed, it provides the old name to remove it from database
    public void save_playlist (StaticPlaylist p, string? old_name = null) {
        dbm.save_playlist (p, old_name);
    }
    
    // If the name of the playlist changed, it provides the old name to remove it from database
    public void save_smart_playlist (SmartPlaylist p, string? old_name = null) {
        dbm.save_smart_playlist (p, old_name);
    }
}
