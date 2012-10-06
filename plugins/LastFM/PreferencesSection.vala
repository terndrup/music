// -*- Mode: vala; indent-tabs-mode: nil; tab-width: 4 -*-
/*-
 * Copyright (c) 2012 Noise Developers (http://launchpad.net/noise)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * The Noise authors hereby grant permission for non-GPL compatible
 * GStreamer plugins to be used and distributed together with GStreamer
 * and Noise. This permission is above and beyond the permissions granted
 * by the GPL license by which Noise is covered. If you modify this code
 * you may extend this exception to your version of the code, but you are not
 * obligated to do so. If you do not wish to do so, delete this exception
 * statement from your version.
 */

private class LastFM.PreferencesSection : Noise.PreferencesWindow.Section {
    static string ENABLE_SCROBBLING = _("Give Noise Permission");
    static string LOGIN_UNSUCCESSFUL = _("Unsuccessful. Click To Try Again.");
    static string SCROBBLING_ENABLED = _("Scrobbling Already Enabled");
    static string LOGIN_SUCCESSFUL = _("Success!");
    static string COMPLETE_LOGIN = _("Complete Login");

    private Core core;
    private string lastfm_token = "";

    public PreferencesSection (Core core) {
        base (_("Last.fm"));

        this.core = core;

        var container = new Gtk.Grid ();
        container.row_spacing = 12;
        container.column_spacing = 12;

        var login_button = new Gtk.Button ();

        if (core.lastfm_settings.session_key == null || core.lastfm_settings.session_key == "") {
            login_button.label = ENABLE_SCROBBLING;
        } else {
            login_button.label = SCROBBLING_ENABLED;
            login_button.set_tooltip_text(_("Click to redo the Last.fm login process"));
        }
 
        var label = new Gtk.Label (_("To allow for Last.fm integration, you must give permission to Noise. You only need to do this once."));
        label.xalign = 0.0f;
        label.halign = Gtk.Align.START;
        label.set_line_wrap (true);

        container.attach (label, 0, 0, 1, 1);
        container.attach (login_button, 0, 1, 1, 1);
        container.show_all ();

        login_button.clicked.connect (lastfmLoginClick);

        add_subsection (_("Last.fm Integration"), container);
    }

    public void lastfmLoginClick (Gtk.Button login_button) {
        if (login_button.label == ENABLE_SCROBBLING || login_button.label == LOGIN_UNSUCCESSFUL) {
            lastfm_token = core.getToken ();

            if (lastfm_token == null) {
                login_button.set_label (LOGIN_UNSUCCESSFUL);
                warning ("Could not get a token. check internet connection");
            }
            else {
                string auth_uri = "http://www.last.fm/api/auth/?api_key=" + LastFM.API
                                  + "&token=" + lastfm_token;
                try {
                    AppInfo.launch_default_for_uri (auth_uri, null);
                }
                catch(GLib.Error err) {
                    warning ("Could not open Last FM website to authorize: %s\n", err.message);
                }

                //set button text. we are done this time around. next time we get session key
                login_button.set_label(COMPLETE_LOGIN);
            }
        }
        else {
            if(lastfm_token == null) {
                login_button.set_label(LOGIN_UNSUCCESSFUL);
                message ("Invalid token. Cannot continue");
            }
            else {
                var sk = core.getSessionKey(lastfm_token);
                if(sk == null) {
                    login_button.set_label(LOGIN_UNSUCCESSFUL);
                    message ("Could not get Last.fm session key");
                }
                else {
                    core.logged_in();
                    message ("Successfully obtained a sessionkey");
                    debug (sk);
                    core.lastfm_settings.session_key = sk;
                    login_button.set_sensitive(false);
                    login_button.set_label(LOGIN_SUCCESSFUL);
                }
            }
        }
    }
}
