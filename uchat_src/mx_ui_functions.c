#include "../inc/uchat.h"
#include "../inc/ui.h"

// chat
int mx_load_chat(/* chat_t *chat, gpointer data,*/t_chat* chat, int ltype ) {
    if (ltype == 0) {}
    
    // 

    
    return 0;
}
int mx_add_chat_message( t_message *message, t_user *user, int type ) {
    if (message == NULL) {}
    // 
    GtkWidget *newitem = gtk_list_box_row_new();
    GtkWidget *main_box = NULL;
    GtkWidget *message_button = NULL;
    GtkWidget *profile_button = NULL;
    GtkWidget *profile_image = NULL;
    GtkWidget *name_label = NULL;
    GtkWidget *date_label = NULL;
    GtkWidget *message_box = NULL;
    GtkWidget *name_date_box = NULL;
    // GtkWidget *message_list_box = NULL;
    GtkWidget *message_text_label = NULL;
    if ( type == 1 ) { // right message
        gtk_widget_set_margin_top(newitem, 5);
        gtk_widget_set_margin_bottom(newitem, 5);
        gtk_widget_set_margin_start(newitem, 60);
        gtk_widget_set_margin_end(newitem, 10);
        message_button = gtk_button_new(  );
        message_box = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0 );
        name_date_box = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0 );
        
        message_text_label = gtk_label_new( message->m_text );
        gtk_label_set_xalign( GTK_LABEL(message_text_label), 0.05 );
        gtk_label_set_yalign( GTK_LABEL(message_text_label), 0.05 );
        gtk_label_set_selectable( GTK_LABEL(message_text_label), TRUE );
        gtk_label_set_line_wrap_mode( GTK_LABEL(message_text_label), PANGO_WRAP_WORD_CHAR );

        name_label = gtk_label_new( ctime( (const time_t*)(&(message->m_date)) ) );
        date_label = gtk_label_new( "1" );
        gtk_widget_set_margin_start(date_label, 5);
        gtk_widget_set_margin_end(name_label, 5);
        gtk_widget_set_valign(name_label, GTK_ALIGN_END);
        gtk_widget_set_valign(date_label, GTK_ALIGN_START);

        gtk_box_pack_end( GTK_BOX(name_date_box), name_label, FALSE, FALSE, 0 ); // date, name to box
        gtk_box_pack_start( GTK_BOX(name_date_box), date_label, FALSE, FALSE, 0 );

        gtk_box_pack_end( GTK_BOX(message_box), name_date_box, FALSE, TRUE, 0 ); // date/name box, message to box
        gtk_box_pack_end( GTK_BOX(message_box), message_text_label, TRUE, TRUE, 0 );

        gtk_container_add( GTK_CONTAINER(message_button), message_box );
        // 
        g_signal_connect( G_OBJECT(message_button), "button-press-event", G_CALLBACK(mx_message_button_4_signal), NULL );
        gtk_container_add( GTK_CONTAINER(newitem), message_button );
    }
    else if ( type == 2 ) { // left message 
        gtk_widget_set_margin_top(newitem, 5);
        gtk_widget_set_margin_bottom(newitem, 5);
        gtk_widget_set_margin_start(newitem, 5);
        gtk_widget_set_margin_end(newitem, 20);
        main_box = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0 );
        profile_button = gtk_button_new(  );
        message_button = gtk_button_new(  );

        message_box = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0 );
        name_date_box = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0 );
        
        message_text_label = gtk_label_new( message->m_text );

        name_label = gtk_label_new( "" );
        date_label = gtk_label_new( ctime((time_t*)(&message->m_date)) );
        gtk_widget_set_margin_start(name_label, 5);
        gtk_widget_set_margin_end(date_label, 5);
        gtk_widget_set_valign(name_label, GTK_ALIGN_START);
        gtk_widget_set_valign(date_label, GTK_ALIGN_END);

        gtk_box_pack_start( GTK_BOX(name_date_box), name_label, FALSE, FALSE, 0 ); // date, name to box
        gtk_box_pack_end( GTK_BOX(name_date_box), date_label, FALSE, FALSE, 0 );

        gtk_widget_set_halign(profile_button, GTK_ALIGN_START);
        gtk_widget_set_valign(profile_button, GTK_ALIGN_END);
        profile_image = gtk_image_new_from_file( "./resources/profile_icon_40.png" );

        gtk_container_add( GTK_CONTAINER(profile_button), profile_image );
        gtk_container_add( GTK_CONTAINER(message_button), message_box );

        gtk_box_pack_start( GTK_BOX(main_box), profile_button, FALSE, FALSE, 0 ); // date, name to box
        gtk_box_pack_end( GTK_BOX(main_box), message_button, TRUE, TRUE, 0 );

        g_signal_connect( G_OBJECT(message_button), "button-press-event", G_CALLBACK(mx_message_button_4_signal), NULL );
        g_signal_connect( G_OBJECT(profile_button), "clicked", G_CALLBACK(mx_profile_button_4_signal), user );
        gtk_container_add( GTK_CONTAINER(newitem), main_box );
    }
    /*for (; ; ) { // add attacments

        gtk_box_pack_start( GTK_BOX(message_box), , TRUE, TRUE, 0 );
    }*/
    t_message_widget* mes_widget = (t_message_widget*)malloc( sizeof(t_message_widget) );
    mes_widget->list_item = newitem;
    //g_object_ref(chat_widget->list_item);
    mes_widget->type = type;
    mes_widget->message = message;
    mes_widget->main_box = main_box;
    mes_widget->profile_button = profile_button;
    mes_widget->message_button = message_button;
    mes_widget->message_box = message_button;
    mes_widget->message_button = message_button;
    //g_object_ref(chat_widget->count_label);
    mes_widget->filter = TRUE;
    mes_widget->sort = message->m_date;

    if ( app->chat_page->messagearr == NULL ) { // add chat to arr
        app->chat_page->messagearr_size = 51;
        app->chat_page->messagearr_count = 0;
        app->chat_page->messagearr = (t_message_widget **)malloc( sizeof(t_message_widget*) * app->chat_page->messagearr_size );
        app->chat_page->messagearr[app->chat_page->messagearr_count] = mes_widget;
        app->chat_page->messagearr_count++;
    }
    else if ( app->chat_page->messagearr_count < app->chat_page->messagearr_size  ) {

        app->chat_page->messagearr[app->chat_page->messagearr_count] = mes_widget;
        app->chat_page->messagearr_count++;
    }
    else {
        app->chat_page->messagearr_size += 50;
        t_message_widget ** newmessagearr = (t_message_widget **)malloc( sizeof(t_message_widget*) * app->chat_page->messagearr_size );
        for (; false ; ) { // copy all items to new arr
            newmessagearr = NULL;
        }
        app->chat_page->messagearr[app->chat_page->messagearr_count] = mes_widget;
        app->chat_page->messagearr_count++;
    }
    gtk_list_box_prepend( 
        GTK_LIST_BOX(gtk_builder_get_object(app->builder, "main_box_4")), 
        newitem);
    gtk_widget_show_all( GTK_WIDGET(gtk_builder_get_object(app->builder, "main_box_4")) );
    return 0;
}
int mx_del_chat_message( GtkListBox *lbox, GtkWidget *item, int mid ) { // only gtk struct 
if ( lbox == NULL || item == NULL || mid == 0) {}
    
    // gtk_builder_get_object(app->builder, "o_overlay")
    // 
    //gtk_list_box_

    // gtk_container_remove( GTK_CONTAINER(lbox), item );
    gtk_widget_destroy( item );
    return 0;
}
int mx_change_chat_message( GtkListBox *lbox, GtkWidget *item, int mid ) { // only gtk struct
if ( item == NULL || lbox == NULL || mid == 0) {}
    
    // 


    
    return 0;
}


// chats list 
int mx_load_chat_list( t_user *user  ) {        
if (user == NULL) {}
    // 


    
    return 0;
}
int mx_add_chat( t_chat *chat ) {
if ( chat == NULL) {}
    // create 
write(1, " add 00  ", 10);
    GtkWidget *newitem = gtk_list_box_row_new();
if (newitem == NULL) { write(1, " row nl \n", 10); sleep(1); }
    //GtkWidget *newitem = gtk_list_box_row_new();

write(1, " add 01  ", 10);
    GtkWidget *main_button = gtk_button_new(  );
    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

write(1, " add 02  ", 10);
    GtkWidget *profile_image = gtk_image_new_from_file( "./resources/chat_icon_50.png" );
        // gtk_image_get_pixbuf();
        // gdk_pixbuf_from
    //GtkWidget *profile_image = gtk_image_new(  );
    GtkWidget *name_count_box = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
write(1, " add 03  ", 10);

    gtk_box_pack_start( GTK_BOX(main_box), GTK_WIDGET(profile_image), FALSE, TRUE, 0 );
    gtk_box_pack_start( GTK_BOX(main_box), GTK_WIDGET(name_count_box), TRUE, TRUE, 0 );

    gtk_widget_set_margin_bottom( GTK_WIDGET(profile_image), 5);
    gtk_widget_set_margin_top( GTK_WIDGET(profile_image), 5);
    gtk_widget_set_margin_start( GTK_WIDGET(profile_image), 5);
    gtk_widget_set_margin_end( GTK_WIDGET(profile_image), 5);
write(1, " add 05  ", 10);
    GtkWidget *name_label = gtk_label_new( chat->c_name ) ;
    GtkWidget *count_label = gtk_label_new( "" ) ; // non read count

    gtk_widget_set_margin_top( GTK_WIDGET(name_label), 5);
    gtk_widget_set_margin_bottom( GTK_WIDGET(count_label), 5);

    gtk_widget_set_halign( GTK_WIDGET(name_label), GTK_ALIGN_START);
    gtk_widget_set_halign( GTK_WIDGET(count_label), GTK_ALIGN_END);

write(1, " add 07  ", 10);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_button) );
    gtk_style_context_add_class(context,"ClearButton");
    context = gtk_widget_get_style_context( GTK_WIDGET(main_box) );
    gtk_style_context_add_class(context,"ClearButton");
    context = gtk_widget_get_style_context( GTK_WIDGET(name_label) );
    gtk_style_context_add_class(context,"ChatsListItemLabel");
    context = gtk_widget_get_style_context( GTK_WIDGET(count_label) );
    gtk_style_context_add_class(context,"ChatsListItemCountLabel");

    gtk_box_pack_start( GTK_BOX(name_count_box), GTK_WIDGET(name_label), TRUE, TRUE, 0 );
    gtk_box_pack_start( GTK_BOX(name_count_box), GTK_WIDGET(count_label), TRUE, TRUE, 0 );
    //gtk_box_set
    g_signal_connect( G_OBJECT(main_button), "button-press-event", G_CALLBACK(mx_chat_button_3_signal), NULL );

//write(1, " list item\n", 12);
    gtk_container_add( GTK_CONTAINER(main_button), GTK_WIDGET(main_box) );
    gtk_container_add( GTK_CONTAINER(newitem), GTK_WIDGET(main_button) );
    //gtk_list_box_row_set_header( GTK_LIST_BOX_ROW(newitem), main_button );
    //GtkWidget *newitem2 = gtk_list_box_row_new();
    //gtk_list_box_insert( (GtkListBox*)(app->chats_list_page->main_box), newitem2, position);
//sleep(1);

    gtk_list_box_row_changed( GTK_LIST_BOX_ROW(newitem) );

    

     // show
    // add style

    // add to struct
    t_chat_widget* chat_widget = (t_chat_widget*)malloc( sizeof(t_chat_widget) );
    chat_widget->list_item = newitem;
    //g_object_ref(chat_widget->list_item);
    chat_widget->chat = chat;
    chat_widget->main_button = main_button;
    //g_object_ref(chat_widget->main_button);
    chat_widget->main_box = main_box;
    //g_object_ref(chat_widget->main_box);
    chat_widget->profile_image = profile_image;
    //g_object_ref(chat_widget->profile_image);
    chat_widget->name_count_box = name_count_box;
    //g_object_ref(chat_widget->name_count_box);
    chat_widget->name_label = name_label;
    //g_object_ref(chat_widget->name_label);
    chat_widget->count_label = count_label;
    //g_object_ref(chat_widget->count_label);
    chat_widget->filter = TRUE;
    chat_widget->sort = 0;
    if ( app->chats_list_page->chatarr == NULL ) { // add chat to arr
        app->chats_list_page->chatarr_size = 21;
        app->chats_list_page->chatarr_count = 0;
        app->chats_list_page->chatarr = (t_chat_widget **)malloc( sizeof(t_chat_widget*) * app->chats_list_page->chatarr_size );
        app->chats_list_page->chatarr[app->chats_list_page->chatarr_count] = chat_widget;
        app->chats_list_page->chatarr_count++;
    }
    else if ( app->chats_list_page->chatarr_count < app->chats_list_page->chatarr_size  ) {

        app->chats_list_page->chatarr[app->chats_list_page->chatarr_count] = chat_widget;
        app->chats_list_page->chatarr_count++;
    }
    else {
        app->chats_list_page->chatarr_size += 20;
        t_chat_widget ** newchatarr = (t_chat_widget **)malloc( sizeof(t_chat_widget*) * app->chats_list_page->chatarr_size );
        for (; false ; ) { // copy all items to new arr
            newchatarr = NULL;
        }
        app->chats_list_page->chatarr[app->chats_list_page->chatarr_count] = chat_widget;
        app->chats_list_page->chatarr_count++;
    }
    gtk_list_box_prepend( 
        GTK_LIST_BOX(gtk_builder_get_object(app->builder, "chat_list_box_3")), 
        GTK_WIDGET(newitem));
    gtk_widget_show_all( GTK_WIDGET(gtk_builder_get_object(app->builder, "chat_list_box_3")) );
    return 0;
}
int mx_del_chat( GtkListBox *lbox, GtkListBoxRow *item, int cid ) { // only gtk struct 
    // find item 
    if (item == NULL) {
        for (int i = 0; i < app->chats_list_page->chatarr_count; i++) {
            if ( cid == app->chats_list_page->chatarr[i]->chat->c_id ) {
                item = GTK_LIST_BOX_ROW(app->chats_list_page->chatarr[i]->list_item);
            }
        }
    }
    // del 
    for (int i = 0; i < app->chats_list_page->chatarr_count; i++) {

        if ( item == GTK_LIST_BOX_ROW(app->chats_list_page->chatarr[i]->list_item) ) {
            
            gtk_container_remove( GTK_CONTAINER(lbox), GTK_WIDGET(item) );
            for (int j = i; j < app->chats_list_page->chatarr_count - 1; j++) { 

                app->chats_list_page->chatarr[i] = app->chats_list_page->chatarr[i+1];
            }
            app->chats_list_page->chatarr_count--;
        }
    }
    gtk_list_box_invalidate_filter(lbox);
    return 0;
}
int mx_change_chat( GtkListBox *lbox, GtkListBoxRow *item, int cid ) { // only gtk struct 
    // find item 
    if (item == NULL) {
        for (int i = 0; i < app->chats_list_page->chatarr_count; i++) {
            if ( cid == app->chats_list_page->chatarr[i]->chat->c_id ) {
                item = GTK_LIST_BOX_ROW(app->chats_list_page->chatarr[i]->list_item);
            }
        }
    }
    // change
    for (int i = 0; i < app->chats_list_page->chatarr_count; i++) {

        if ( item == GTK_LIST_BOX_ROW(app->chats_list_page->chatarr[i]->list_item) ) {
            // 

            // hide count 

        }
    }
    gtk_list_box_invalidate_sort(lbox);
    return 0;
}

// notifications
int mx_show_notification( char* notificationstr, int seconds ) {
    if (seconds != 0) {
        // timeout? 

    }
    //  check entrys
    gtk_widget_show( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_notification_box")) ); 
    // request 
    gtk_label_set_label( GTK_LABEL(gtk_builder_get_object(app->builder, "o_notification")), (const gchar*)notificationstr );

    return 0;
}
int mx_hide_notification(  ) {
    
    gtk_widget_hide( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_notification_box")) ); 
    //  check entrys


    // request 


    return 0;
}



