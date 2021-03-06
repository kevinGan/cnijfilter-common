/*  Canon Bubble Jet Print Filter.
 *  Copyright CANON INC. 2001-2003
 *  All Rights Reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * NOTE:
 *  - As a special exception, this program is permissible to link with the
 *    libraries released as the binary modules.
 *  - If you write modifications of your own for these programs, it is your
 *    choice whether to permit this exception to apply to your modifications.
 *    If you do not wish that, delete this exception.
 */


#include "dialog.h"

typedef struct
{
	UIDialog dialog;

	GList* media_list;

	gboolean apply;
	short selected_media;

} UIMediaBorderDialog;


UIMediaBorderDialog* CreateMediaBorderDialog(UIDialog* parent);
void DisposeMediaBorderDialog(UIMediaBorderDialog* dialog);
int ShowMediaBorderDialog(UIMediaBorderDialog* dialog, short media_type);
void HideMediaBorderDialog(UIMediaBorderDialog* dialog, gboolean apply);
gboolean IsAvailableMediaBorder(UIMediaBorderDialog* dialog, short media_type);

gboolean
on_mediaborder_dialog_delete_event     (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_mediaborder_dialog_entry_changed    (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_mediaborder_dialog_ok_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_mediaborder_dialog_cancel_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

