#include "../inc/uchat.h"
#include "../inc/ui.h"

// chat
int mx_load_chat(/* chat_t *chat, gpointer data,*/ int ltype ) {
    if (ltype == 0) {}
    
    // 

    
    return 0;
}
int mx_add_chat_message( t_message *message, int position, int type ) {
    if (message == NULL) {}
    // 
    GtkWidget *newitem = gtk_list_box_row_new();

    GtkWidget *main_box = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0 );

    GtkWidget *message_box = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0 );
    GtkWidget *name_date_box = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0 );

    gtk_box_pack_start( GTK_BOX(main_box), message_box, TRUE, TRUE, 0 );
    gtk_box_pack_start( GTK_BOX(main_box), name_date_box, TRUE, TRUE, 0 );

    GtkWidget *name_label = NULL;
    GtkWidget *date_label = NULL;
    if ( type == 1 ) { // right message

        gtk_widget_set_margin_bottom(newitem, 5);
        gtk_widget_set_margin_top(newitem, 5);
        gtk_widget_set_margin_start(newitem, 50);
        gtk_widget_set_margin_end(newitem, 5);

        name_label = gtk_label_new( "date" );
        date_label = gtk_label_new( "" );

        // gtk_widget_set_margin_top(name_label, 5);
        // gtk_widget_set_margin_bottom(date_label, 5);
        // gtk_widget_set_halign(name_label, GTK_ALIGN_START);
        // gtk_widget_set_halign(date_label, GTK_ALIGN_END);
    }
    else if ( type == 2 ) { // left message 

        gtk_widget_set_margin_bottom(newitem, 5);
        gtk_widget_set_margin_top(newitem, 5);
        gtk_widget_set_margin_start(newitem, 10);
        gtk_widget_set_margin_end(newitem, 45);

        name_label = gtk_label_new( "name" );
        date_label = gtk_label_new( "date" );

    } 
    gtk_widget_set_margin_top(name_label, 5);
    gtk_widget_set_margin_bottom(date_label, 5);
    gtk_widget_set_halign(name_label, GTK_ALIGN_START);
    gtk_widget_set_halign(date_label, GTK_ALIGN_END);

    gtk_box_pack_start( GTK_BOX(name_date_box), name_label, TRUE, TRUE, 0 );
    gtk_box_pack_start( GTK_BOX(name_date_box), date_label, TRUE, TRUE, 0 );
    //gtk_box_set
    g_signal_connect( G_OBJECT(newitem), "button-press-event", G_CALLBACK(mx_chat_button_3_signal), NULL );

    gtk_container_add( GTK_CONTAINER(newitem), main_box );
    gtk_list_box_insert( GTK_LIST_BOX(app->chat_page->main_box), newitem, position);
    
    return 0;
}
int mx_del_chat_message( GtkContainer *lbox, GtkWidget *item ) {
    
    
    // 
    //gtk_list_box_
    gtk_container_remove( lbox, item );

    
    return 0;
}
int mx_change_chat_message(/* message_t *message, gpointer data,*/ int ltype ) {
    if (ltype == 0) {}
    
    // 


    
    return 0;
}
int mx_change_chat_info(/* message_t *message, gpointer data,*/ int ltype ) {
    if (ltype == 0) {}
    
    // 


    
    return 0;
}

// chats list 
int mx_load_chat_list( /*GtkWidget *widget, gpointer data*/ ) {        
    
    // 


    
    return 0;
}
int mx_add_chat( t_chat *chat, gint position ) {
    if ( chat == NULL) {}
    // create 
write(1, " add 00 \n", 10);
    GtkWidget *newitem = gtk_list_box_row_new();
if (newitem == NULL) { write(1, " row nl \n", 10); sleep(1); }
    //GtkWidget *newitem = gtk_list_box_row_new();

write(1, " add 01 \n", 10);
    GtkWidget *main_button = gtk_button_new(  );
    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

write(1, " add 02 \n", 10);
    GtkWidget *profile_image = gtk_image_new_from_file( "./resources/chat_icon.png" );
    //GtkWidget *profile_image = gtk_image_new(  );
    GtkWidget *name_count_box = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
write(1, " add 03 \n", 10);

    gtk_box_pack_start( GTK_BOX(main_box), profile_image, FALSE, TRUE, 0 );
    gtk_box_pack_start( GTK_BOX(main_box), name_count_box, TRUE, TRUE, 0 );

    gtk_widget_set_margin_bottom(profile_image, 5);
    gtk_widget_set_margin_top(profile_image, 5);
    gtk_widget_set_margin_start(profile_image, 5);
    gtk_widget_set_margin_end(profile_image, 5);
write(1, " add 05 \n", 10);
    GtkWidget *name_label = gtk_label_new( chat->c_name  );
    GtkWidget *count_label = gtk_label_new( "" ); // non read count

    gtk_widget_set_margin_top(name_label, 5);
    gtk_widget_set_margin_bottom(count_label, 5);

    gtk_widget_set_halign(name_label, GTK_ALIGN_START);
    gtk_widget_set_halign(count_label, GTK_ALIGN_END);

write(1, " add 07 \n", 10);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context( main_button );
    gtk_style_context_add_class(context,"ClearButton");
    context = gtk_widget_get_style_context( main_box );
    gtk_style_context_add_class(context,"ClearButton");
    context = gtk_widget_get_style_context( name_label );
    gtk_style_context_add_class(context,"ChatsListItemLabel");
    context = gtk_widget_get_style_context( count_label );
    gtk_style_context_add_class(context,"ChatsListItemCountLabel");

    gtk_box_pack_start( GTK_BOX(name_count_box), name_label, TRUE, TRUE, 0 );
    gtk_box_pack_start( GTK_BOX(name_count_box), count_label, TRUE, TRUE, 0 );
    //gtk_box_set
    g_signal_connect( G_OBJECT(main_button), "button-press-event", G_CALLBACK(mx_chat_button_3_signal), NULL );

//write(1, " list item\n", 12);
    gtk_container_add( GTK_CONTAINER(main_button), main_box );
    gtk_container_add( GTK_CONTAINER(newitem), main_button );
    gtk_list_box_row_set_header( GTK_LIST_BOX_ROW(newitem), main_button );
    //GtkWidget *newitem2 = gtk_list_box_row_new();
    //gtk_list_box_insert( (GtkListBox*)(app->chats_list_page->main_box), newitem2, position);
//sleep(1);
    gtk_list_box_insert( GTK_LIST_BOX(app->chats_list_page->main_box), newitem, position);

    
    

     // show
    // add style

    // add to struct
    t_chat_widget* chat_widget = (t_chat_widget*)malloc( sizeof(t_chat_widget*) );
    chat_widget->list_item = newitem;
    chat_widget->chat = chat;
    chat_widget->main_button = main_button;
    chat_widget->main_box = main_box;
    chat_widget->profile_image = profile_image;
    chat_widget->name_count_box = name_count_box;
    chat_widget->name_label = name_label;
    chat_widget->count_label = count_label;
    chat_widget->filter = TRUE;
    chat_widget->sort = 0;
    if ( app->chats_list_page->chatarr == NULL ) {
        app->chats_list_page->chatarr_size = 21;
        app->chats_list_page->chatarr_count = 0;
        app->chats_list_page->chatarr = (t_chat_widget **)malloc( sizeof(t_chat_widget*) * app->chats_list_page->chatarr_size );
        app->chats_list_page->chatarr[app->chats_list_page->chatarr_count-1] = chat_widget;
        app->chats_list_page->chatarr_count++;
    }
    else if ( app->chats_list_page->chatarr_count < app->chats_list_page->chatarr_size - 1 ) {

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
    return 0;
}
int mx_del_chat( GtkListBox *lbox, GtkWidget *item ) {
    if (item == NULL) {}
    //gtk_container_remove( lbox, item );

    gtk_list_box_invalidate_filter(lbox);
    return 0;
}
int mx_change_chat( GtkListBox *lbox, GtkWidget *item ) {
    if (item == NULL) {}

    //gtk_container_remove( lbox, item );
    
    //gtk_box_set_child_packing();
    //gtk_box_query_child_packing();

    gtk_list_box_invalidate_sort(lbox);
    return 0;
}

// notifications
int mx_show_notification( /*GtkWidget *widget, gpointer data*/ ) {
    
    //  check entrys


    // request 


    return 0;
}



