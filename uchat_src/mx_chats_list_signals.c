#include "../inc/ui.h"

// search signals
gboolean mx_close_search_3_signal( GtkWidget *widget, gpointer data ) {
    write(1, "cls cs s \n", 10);
    if (widget == NULL && data == NULL) {}
    // clear entry

    
    //gtk_widget_hide( GTK_WIDGET(gtk_builder_get_object(app->builder, "search_scroller_3")) );
    gtk_stack_set_visible_child_full( 
        GTK_STACK( gtk_builder_get_object(app->builder, "chat_list_stack") ), 
        "chat_list", GTK_STACK_TRANSITION_TYPE_SLIDE_UP );
    // ? load chats / hide overlay
    
    // close revealer
    gtk_revealer_set_reveal_child( GTK_REVEALER(gtk_builder_get_object(app->builder, "search_revealer_3")), false ); 
    return true;
}
gboolean mx_search_3_signal( GtkWidget *widget, gpointer data ) {
    write(1, "cls cs s \n", 10);
    if (widget == NULL && data == NULL) {}
    // search (request returns t_chat** arr & *count)
    const gchar* text2 = gtk_entry_get_text( 
        GTK_ENTRY(gtk_builder_get_object(app->builder, "search_entry_3")) );
    if (text2 != NULL) { // request 
        
    }
    // show show overlay search results
    gtk_stack_set_visible_child_full( 
        GTK_STACK( gtk_builder_get_object(app->builder, "chat_list_stack") ), 
        "search_list", GTK_STACK_TRANSITION_TYPE_SLIDE_DOWN );
    // add items 
    
    return true;
}



// chat selection signal
gboolean mx_chat_button_3_signal( GtkWidget *widget, GdkEventButton *event, gpointer data ) {
if (widget == NULL && data == NULL) {}
write(1, "cls cs s ", 10);
    if (event->type == GDK_BUTTON_PRESS  &&  event->button == 3) { // 3 is right mouse btn
write(1, "rmb \n", 10);
        //
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
        // GtkWidget *item1 = gtk_menu_item_new_with_label( " Delete chat " );

        // GtkWidget *menu_box = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
        // GtkWidget *del_button = gtk_button_new_with_label( "Long chat name" );
        // gtk_box_pack_start( GTK_BOX(menu_box), del_button, TRUE, TRUE, 0 );
        // gtk_container_add( GTK_CONTAINER(menu), menu_box );
        //gtk_container_add( GTK_CONTAINER(menu), item1 );
        //GdkEventButton *bevent = (GdkEventButton *) event;

        g_signal_connect( item1, "activate", G_CALLBACK(mx_pmenu_1_3_signal), NULL );
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
        // find attached chat
        //app.chats_list_page.

        // load chat
            // gtk_

        // change page
            /*GtkWidget *p1 = gtk_widget_get_parent(widget);
            GtkWidget *p2 = gtk_widget_get_parent(p1);*/
        gtk_stack_set_visible_child_full( 
            GTK_STACK(gtk_builder_get_object(app->builder, "main_stack")), 
            "chat_page", GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT );

        //gtk_widget_set_name();

    }
    return true;
}
gboolean mx_pmenu_1_3_signal( GtkWidget *widget, gpointer data ) {
write(1, " menu del \n", 12);
if (widget == NULL && data == NULL) {}
    // leave
    return true;
}
gboolean mx_chat_list_filter_3( GtkListBoxRow *row, gpointer data ) {
write(1, "cl row filter \n", 16);
if (row == NULL && data == NULL) {}
    // find struct
    for (int i = 0; i < app->chats_list_page->chatarr_count; i++) {
        // if 
        if ( (GtkListBoxRow*)(app->chats_list_page->chatarr[i]->list_item) == row) {
            return app->chats_list_page->chatarr[i]->filter;
            break;
        }
    }
    return false;
}
gint mx_chat_list_sort_3( GtkListBoxRow *row1, GtkListBoxRow *row2, gpointer data ) {
    write(1, "cl row sort \n", 14);
    if (row1 == NULL && row2 == NULL && data == NULL) {}
    // find struct
    // return 0;
    int sort1 = 0;
    int sort2 = 0;
    for (int i = 0; i < app->chats_list_page->chatarr_count; i++) {
        // if del 
        if ( GTK_LIST_BOX_ROW(app->chats_list_page->chatarr[i]->list_item) == row1) {
            sort1 = app->chats_list_page->chatarr[i]->sort;
        }
        if ( GTK_LIST_BOX_ROW(app->chats_list_page->chatarr[i]->list_item) == row2) {
            sort2 = app->chats_list_page->chatarr[i]->sort;
        }
    }
    // if () {

    // }
    return sort1 - sort2 * -1;
}
gboolean mx_search_list_filter_3( GtkListBoxRow *row, gpointer data ) {
    write(1, "s row filter \n", 15);
    if (row == NULL && data == NULL) {}
    // find struct

    // if del 
    if ( false ) {
        return false;
    }
    return true;
}
gint mx_search_list_sort_3( GtkListBoxRow *row1, GtkListBoxRow *row2, gpointer data ) {
    write(1, "s row sort \n", 13);
    if (row1 == NULL && row2 == NULL && data == NULL) {}
    
    return 0;
}


// chats list menu buttons
gboolean mx_add_chat_3_signal( GtkWidget *widget, gpointer data ) {
    write(1, "cls ac s \n", 11);
    if (widget == NULL && data == NULL) {}
    // 
    gtk_widget_show( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_overlay")) ); 
    // set stack 
    gtk_stack_set_visible_child_full( 
        GTK_STACK(gtk_builder_get_object(app->builder, "o_overlay")), 
        "add_chat_3", GTK_STACK_TRANSITION_TYPE_SLIDE_DOWN );


    // gtk_widget_show( GTK_WIDGET(app->chats_list_page->add_chat_overlay->overlay_background) ); // show overlay stack
    // gtk_widget_show( GTK_WIDGET(app->chats_list_page->add_chat_overlay->overlay_main) ); // set overlay stack page
    return true;
}
gboolean mx_show_profile_3_signal( GtkWidget *widget, gpointer data ) {
    write(1, "cls sp s \n", 11);
    if (widget == NULL && data == NULL) {}
    // 

    // show 
    gtk_widget_show( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_overlay")) ); 
    // set stack 
    gtk_stack_set_visible_child_full( 
        GTK_STACK(gtk_builder_get_object(app->builder, "o_overlay")), 
        "profile_3", GTK_STACK_TRANSITION_TYPE_SLIDE_DOWN );
    // gtk_widget_show( GTK_WIDGET(app->chats_list_page->profile_overlay->overlay_background) ); // show overlay stack
    // gtk_widget_show( GTK_WIDGET(app->chats_list_page->profile_overlay->overlay_main) ); // set overlay stack page
    return true;
}
gboolean mx_show_search_3_signal( GtkWidget *widget, gpointer data ) {
    write(1, "cls ss s \n", 10);
    if (widget == NULL && data == NULL) {}
    // clear entry 
    
    // show search box 
    gtk_revealer_set_reveal_child( 
        GTK_REVEALER(gtk_builder_get_object(app->builder, "search_revealer_3")), true );
    return true;
}


