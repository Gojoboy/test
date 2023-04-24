#include "../inc/ui.h"

// top box signals
gboolean mx_exit_chat_4_signal( GtkWidget *widget, gpointer data ) {
    write(1, "cls cs s \n", 10);
    if (widget == NULL && data == NULL) {}
    // clear main box
    GtkWidget *row = GTK_WIDGET(
        gtk_list_box_get_row_at_index( 
            GTK_LIST_BOX(gtk_builder_get_object(app->builder, "main_box_4")), 0 ) );
    while ( row != NULL) {
        while ( row != NULL ) {
            gtk_container_remove( 
                GTK_CONTAINER(gtk_builder_get_object(app->builder, "main_box_4")), row );

            row = GTK_WIDGET(gtk_list_box_get_row_at_index( 
                GTK_LIST_BOX(gtk_builder_get_object(app->builder, "main_box_4")), 0 ) );
        }
        row = GTK_WIDGET(
        gtk_list_box_get_row_at_index( 
            GTK_LIST_BOX(gtk_builder_get_object(app->builder, "main_box_4")), 0 ) );
    }
    sleep(5);
    // change page
    gtk_stack_set_visible_child_full( 
        GTK_STACK(gtk_builder_get_object(app->builder, "main_stack")), 
        "chat_list_page", GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT );
    return true;
}
gboolean mx_show_chat_profile_4_signal( GtkWidget *widget, gpointer data ) { // chat profile
write(1, "cls sp s \n", 10);
if (widget == NULL && data == NULL) {}
    // show overlay
    gtk_widget_show( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_overlay")) ); 
    // set stack 
    gtk_stack_set_visible_child_full( 
        GTK_STACK(gtk_builder_get_object(app->builder, "o_overlay")), 
        "chat_profile_4", GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT );
    // find struct 

    if ( false ) { // if chat type 1-1 
        gtk_widget_show( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_overlay")) ); 
        // set stack 
        gtk_stack_set_visible_child_full( 
            GTK_STACK(gtk_builder_get_object(app->builder, "o_overlay")), 
            "user_profile_4", GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT );
    }
    //gtk_widget_show( GTK_WIDGET(app->chat_page->profile_overlay->overlay_background) ); // chat overlay (profile)
    //gtk_widget_show( GTK_WIDGET(app->chat_page->profile_overlay->overlay_main) ); // chat overlay (profile)
    return true;
}



// message selection signal
gboolean mx_message_button_4_signal( GtkWidget *widget, GdkEventButton *event, gpointer data ) {
write(1, "cls cs s ", 10);
    if (widget == NULL && data == NULL) {}
    if (event->type == GDK_BUTTON_PRESS  &&  event->button == 3) { // 3 is right mouse btn
write(1, "rmb \n", 10);
        int i = 0;
        for ( ; i < app->chats_list_page->chatarr_count; i++) {
            if ( widget == app->chats_list_page->chatarr[i]->main_button ) {
                // 
                break;
            }
        }
        //
        GtkWidget *menu = gtk_menu_new();
        GtkWidget *item1 = gtk_menu_item_new_with_label( app->chats_list_page->chatarr[i]->chat->c_name );
        GtkWidget *item2 = gtk_menu_item_new_with_label( app->chats_list_page->chatarr[i]->chat->c_name );

        g_signal_connect( item1, "activate", G_CALLBACK(mx_pmenu_1_4_signal), NULL );
        g_signal_connect( item2, "activate", G_CALLBACK(mx_pmenu_2_4_signal), NULL );
        // g_signal_connect( G_OBJECT(item1), "activate", G_CALLBACK(mx_pmenu_1_3_signal), NULL );
        gtk_menu_attach( GTK_MENU(menu), item1, 0,1,0,1 );
        gtk_widget_show( menu );
        gtk_widget_show( item1 );
        app->menu_row = GTK_LIST_BOX_ROW( gtk_widget_get_parent(widget) );
        app->menu_type = 1;
        gtk_menu_popup_at_pointer( GTK_MENU(menu), (GdkEvent *)event );
    }
    if (event->type == GDK_BUTTON_PRESS  &&  event->button == 1) { // 1 is left mouse btn
write(1, "lmb \n", 10);
    }
    return true;
}
gboolean mx_profile_button_4_signal( GtkWidget *widget, gpointer data ) {
write(1, "cls cs s2", 10);
if (widget == NULL && data == NULL) {}
     
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
    const gchar* text = gtk_entry_get_text( 
        GTK_ENTRY(gtk_builder_get_object(app->builder, "send_entry_4")) );
    if (text != NULL) {
write(1, " !null \n", 9);
        printf(" 1main entry: %s", text);
        g_print(" 2main entry: %s", text);
        g_printerr(" 3main entry: %s", text);
        t_message* m1 = (t_message*)malloc( sizeof(t_message) );
            m1->m_id = 61;
            m1->u_id = 1;
            m1->m_text = (char*)text;
            m1->m_is_edited = false;
            m1->m_date = time(NULL) - 0;
            m1->m_type = 1;
            m1->m_form = 1;
            m1->m_m_id = 0;
        mx_add_chat_message( m1, NULL, 1 );
    }
    gtk_entry_set_text( 
        GTK_ENTRY(gtk_builder_get_object(app->builder, "send_entry_4")), "" );
    return true;
}


