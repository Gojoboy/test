#include "../inc/ui.h"

// top box signals
gboolean mx_exit_chat_4_signal( GtkWidget *widget, gpointer data ) {
    write(1, "cls cs s \n", 10);
    if (widget == NULL && data == NULL) {}
    // clear main box
    GtkWidget *row = GTK_WIDGET(gtk_list_box_get_row_at_index( GTK_LIST_BOX(app->chat_page->main_box), 0 ) );
    while ( row != NULL ) {
        gtk_container_remove( GTK_CONTAINER(app->chat_page->main_box), row );
        row = GTK_WIDGET(gtk_list_box_get_row_at_index( GTK_LIST_BOX(app->chat_page->main_box), 0 ) );
    }
    sleep(5);
    // change page
    gtk_stack_set_visible_child_full( GTK_STACK(app->stack), "chat_list_overlay", GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT );
    return true;
}
gboolean mx_show_profile_4_signal( GtkWidget *widget, gpointer data ) {
    write(1, "cls sp s \n", 10);
    if (widget == NULL && data == NULL) {}
    // 
    gtk_widget_show(app->chat_page->profile_overlay->overlay_background); // chat overlay (profile)
    gtk_widget_show(app->chat_page->profile_overlay->overlay_main); // chat overlay (profile)
    return true;
}



// message selection signal
gboolean mx_message_button_4_signal( GtkWidget *widget, GdkEventButton *event, gpointer data ) {
write(1, "cls cs s ", 10);
    if (widget == NULL && data == NULL) {}
    if (event->type == GDK_BUTTON_PRESS  &&  event->button == 3) { // 3 is right mouse btn
write(1, "rmb \n", 10);
        GtkWidget *menu = gtk_menu_new();
        


        gtk_widget_show( menu );
        gtk_menu_popup_at_pointer( GTK_MENU(menu), (GdkEvent *)event );
    }
    if (event->type == GDK_BUTTON_PRESS  &&  event->button == 1) { // 1 is left mouse btn
write(1, "lmb \n", 10);
    }
    return true;
}
gboolean mx_pmenu_1_4_signal( GtkWidget *widget, gpointer data ) {
    write(1, "c menu s 1 \n", 13);
    if (widget == NULL && data == NULL) {}
    // leave
    return true;
}
gboolean mx_pmenu_2_4_signal( GtkWidget *widget, gpointer data ) {
    write(1, "c menu s 2 \n", 13);
    if (widget == NULL && data == NULL) {}
    // leave
    return true;
}
gboolean mx_message_list_filter_4( GtkListBoxRow *row, gpointer data ) {
    write(1, "mes row filter \n", 17);
    if (row == NULL && data == NULL) {}
    // find struct

    // if del 
    if ( false ) {
        return false;
    }
    return true;
}
gint mx_message_list_sort_4( GtkListBoxRow *row1, GtkListBoxRow *row2, gpointer data ) {
    write(1, "mes row sort \n", 15);
    if (row1 == NULL && row2 == NULL && data == NULL) {}
    
    return 0;
}


// bottom box signals
gboolean mx_attach_4_signal( GtkWidget *widget, gpointer data ) {
    write(1, "c attach s \n", 13);
    if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}
gboolean mx_send_4_signal( GtkWidget *widget, gpointer data ) {
    write(1, "c send s \n", 11);
    if (widget == NULL && data == NULL) {}
    // 
    const gchar* text = gtk_entry_get_text( GTK_ENTRY(app->chat_page->main_entry) );
    if (text != NULL) {
        printf(" main entry: %s", text);
    }
    return true;
}



// overlay signals
gboolean mx_overlay_3_exit_signal( GtkWidget *widget, gpointer data ) { // chat profile
    write(1, "c attach s \n", 13);
    if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}
gboolean mx_overlay_3_leave_signal( GtkWidget *widget, gpointer data ) {
    write(1, "c send s \n", 11);
    if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}

gboolean mx_overlay_4_exit_signal( GtkWidget *widget, gpointer data ) { // user profile
    write(1, "c attach s \n", 13);
    if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}
gboolean mx_overlay_4_send_message_signal( GtkWidget *widget, gpointer data ) {
    write(1, "c send s \n", 11);
    if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}



