/*
 * vinagre-ui.h
 * This file is part of vinagre
 *
 * Copyright (C) 2007,2008,2009 - Jonh Wendell <wendell@bani.com.br>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __VINAGRE_UI_H__
#define __VINAGRE_UI_H__

#include <gtk/gtk.h>

#include "vinagre-commands.h"

G_BEGIN_DECLS

static const GtkActionEntry vinagre_always_sensitive_entries[] =
{
  /* Toplevel */
  { "Remote", NULL, N_("_Remote") },
  { "Edit", NULL, N_("_Edit") },
  { "View", NULL, N_("_View") },
  { "Bookmarks", NULL, N_("_Bookmarks") },
  { "Help", NULL, N_("_Help") },

  /* Remote menu */
  { "RemoteConnect", GTK_STOCK_CONNECT, NULL, "<control>N",
    N_("Connect to a remote desktop"), G_CALLBACK (vinagre_cmd_remote_connect) },
  { "RemoteOpen", GTK_STOCK_OPEN, NULL, "<control>O",
    N_("Open a .VNC file"), G_CALLBACK (vinagre_cmd_remote_open) },
  { "RemoteQuit", GTK_STOCK_QUIT, NULL, "<control>Q",
    N_("Quit the program"), G_CALLBACK (vinagre_cmd_remote_quit) },

  /* Edit menu */
  { "EditPreferences", GTK_STOCK_PREFERENCES, NULL, NULL,
    N_("Edit the application preferences"), G_CALLBACK (vinagre_cmd_edit_preferences) },
  /* TODO: Use a more appropriate icon. Libpeas uses "libpeas-plugin".  */
  { "EditPlugins", GTK_STOCK_EXECUTE, N_("_Plugins"), NULL,
    N_("Select plugins"), G_CALLBACK (vinagre_cmd_edit_plugins) },

  /* Help menu */
  {"HelpContents", GTK_STOCK_HELP, N_("_Contents"), "F1",
    N_("Open the Vinagre manual"),  G_CALLBACK (vinagre_cmd_help_contents)},
  { "HelpAbout", GTK_STOCK_ABOUT, NULL, NULL,
    N_("About this application"), G_CALLBACK (vinagre_cmd_help_about) }
};

static const GtkToggleActionEntry vinagre_always_sensitive_toggle_entries[] =
{
  { "ViewToolbar", NULL, N_("_Toolbar"), NULL,
    N_("Show or hide the toolbar"),
    G_CALLBACK (vinagre_cmd_view_show_toolbar), FALSE },

  { "ViewStatusbar", NULL, N_("_Statusbar"), NULL,
    N_("Show or hide the statusbar"),
    G_CALLBACK (vinagre_cmd_view_show_statusbar), FALSE },

  { "ViewSidePanel", NULL, N_("Side _Panel"), "F9",
    N_("Show or hide the side panel"),
    G_CALLBACK (vinagre_cmd_view_show_fav_panel), FALSE }
};

static const GtkActionEntry vinagre_remote_connected_entries[] =
{
  /* Remote menu */
  { "RemoteDisconnect", GTK_STOCK_DISCONNECT, NULL, "<control>W",
    N_("Disconnect the current connection"), G_CALLBACK (vinagre_cmd_remote_disconnect) },
  { "RemoteDisconnectAll", GTK_STOCK_DISCONNECT, N_("Disconnect All"), "<control><shift>W",
    N_("Disconnect all connections"), G_CALLBACK (vinagre_cmd_remote_disconnect_all) },

  /* Bookmarks menu */
  { "BookmarksAdd", GTK_STOCK_ADD, N_("_Add to bookmarks"), "<control>D",
    N_("Add the current connection to your bookmarks"), G_CALLBACK (vinagre_cmd_bookmarks_add) }

};

static const GtkActionEntry vinagre_remote_initialized_entries[] =
{
  /* Remote menu */
  { "RemoteTakeScreenshot", "applets-screenshooter", N_("_Take screenshot"), NULL,
    N_("Take a screenshot of the active connection"), G_CALLBACK (vinagre_cmd_remote_take_screenshot) },

  /* View menu */
  { "ViewFullScreen", GTK_STOCK_FULLSCREEN, NULL, "F11",
    N_("View the current remote desktop in fullscreen mode"), G_CALLBACK (vinagre_cmd_view_fullscreen) }
};

static const GtkToggleActionEntry vinagre_remote_initialized_toggle_entries[] =
{
 {0,},
};

G_END_DECLS

#endif  /* __VINAGRE_UI_H__  */
/* vim: set ts=8: */
