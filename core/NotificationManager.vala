// -*- Mode: vala; indent-tabs-mode: nil; tab-width: 4 -*-
/*-
 * Copyright (c) 2012-2013 Noise Developers (http://launchpad.net/noise)
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
 *
 * Authored by: Corentin Noël <tintou@mailoo.org>
 */

public class Noise.NotificationManager : Object {

    public signal void alertNotification (string title, string message);
    public signal void progressNotification (string? message, double progress);
    public signal void progress_canceled ();
    public signal void songNotification (string message);
    public signal void searchCover (Media m);

    string current_title_string;
    double progress;
    string current_action_string;

    public NotificationManager () {
    
    }

    public virtual void doProgressNotification (string? message, double progress) {
        current_action_string = message;
        this.progress = progress;
        progressNotification (message, progress);
    }

    public virtual void doSongNotification (string? message) {
        current_title_string = message;
        songNotification (message);
    }

    public virtual void doAlertNotification (string title, string message) {
        alertNotification (title, message);
    }

    public virtual void showProgressNotification () {
        progressNotification (current_action_string, progress);
    }

    public virtual void showSongNotification () {
        songNotification (current_title_string);
    }

}