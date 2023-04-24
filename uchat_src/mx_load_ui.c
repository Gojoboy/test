#include "../inc/ui.h"

static t_sign_page* mx_load_sign_up( /*t_settings* sets,*/ GtkBuilder* builder );
static t_sign_page* mx_load_sign_in( /*t_settings* sets,*/ GtkBuilder* builder );
static t_chats_list_page* mx_load_chats_list( /*t_settings* sets,*/ GtkBuilder* builder );
static t_chat_page* mx_load_chat_page( /*t_settings* sets,*/ GtkBuilder* builder );
static void mx_load_overlays( /*t_settings* sets,*/ GtkBuilder* builder );
gboolean destroy( /*GtkWidget *widget, gpointer data*/ ) {
    gtk_main_quit();
    return true;
}

t_application* mx_load_ui( int* argc, char*** argv ) {
    // main structure 
    t_application* tapp = (t_application*)malloc( sizeof(t_application*) );
    //struct t_application* tapp;

//write(1, " 1t1 \n", 7);
    gtk_init(argc, argv);
//write(1, " 1t2 \n", 7);

    tapp->builder = gtk_builder_new();
    gtk_builder_add_from_file( tapp->builder, "resources/uchat.glade", NULL);
    g_object_ref(tapp->builder);
    //gtk_builder_connect_signals(builder, NULL);
//gtk_main();
    //tapp->application = app;
    GObject* window = /*GTK_WINDOW(*/gtk_builder_get_object(tapp->builder, "main_window") ;
    //tapp->overlay = gtk_builder_get_object(builder, "main_overlay");
            // GObject* stack = /*GTK_STACK(*/gtk_builder_get_object(tapp->builder, "main_stack") ;
                //g_signal_connect( GTK_WIDGET(tapp->window), "destroy", G_CALLBACK(destroy), NULL );
    g_signal_connect( /*GTK_WIDGET(*/window, "destroy", G_CALLBACK(destroy), NULL );


    GdkDisplay* disp = gdk_display_get_default();
    GdkScreen* scr = gdk_display_get_default_screen(disp);
    GtkCssProvider* css_provider;
    css_provider = gtk_css_provider_new();
    if (true) {
        gtk_css_provider_load_from_path(css_provider, "./resources/uchat.css", NULL);
    }
    else if (false) {
        gtk_css_provider_load_from_path(css_provider, "./resources/uchat2.css", NULL);
    }
    //gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(provider),"styles.css",NULL);
    gtk_style_context_add_provider_for_screen(scr, GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_USER);


write(1, " 1t ", 5);
    // 1 load sign in page 
    tapp->sign_in_page = mx_load_sign_in(/*tapp->settings,*/ tapp->builder);
write(1, "1 ", 3);
    // 2 load sign up page 
    tapp->sign_up_page = mx_load_sign_up(/*tapp->settings,*/ tapp->builder);
write(1, "2 ", 3);
    // 3 load chats list page 
    tapp->chats_list_page = mx_load_chats_list(/*tapp->settings,*/ tapp->builder);
write(1, "3 ", 3);
    // 4 load chat page 
    tapp->chat_page = mx_load_chat_page(/*tapp->settings,*/ tapp->builder);
write(1, "4 ", 3);

    mx_load_overlays(/*tapp->settings,*/ tapp->builder);
write(1, " 1t7 \n", 7);
    //g_object_unref( G_OBJECT(builder) );
    //gtk_overlay_add_overlay(tapp->overlay, tapp->sign_up_page->page);
                    //gtk_stack_set_visible_child_name( GTK_STACK(tapp->stack), "chat_page" );
    //gtk_overla

    // load overlay pages
    //
    /*t_profile_overlay_page* tpop = (t_profile_overlay_page*)malloc( sizeof(t_profile_overlay_page*) );
    tpop->page = GTK_WIDGET(gtk_builder_get_object(builder, "profile_overlay_page"));
    tapp->profile_overlay_page = tpop;


    //tapp->chat_profile_overlay_page = GTK_WIDGET(gtk_builder_get_object(builder, "chat_page"));
    //tapp->group_profile_overlay_page = GTK_WIDGET(gtk_builder_get_object(builder, "group_profile_overlay_page"));
    //tapp->chanel_profile_overlay_page = GTK_WIDGET(gtk_builder_get_object(builder, "chanel_profile_overlay_page"));

    tapp->settings_overlay = GTK_WIDGET(gtk_builder_get_object(builder, "settings_overlay"));

    tapp->contacts_overlay = GTK_WIDGET(gtk_builder_get_object(builder, "contacts_overlay"));

    tapp->create_chat_overlay = GTK_WIDGET(gtk_builder_get_object(builder, "create_chat_overlay"));

    // load message template 

    tapp->chat_page = GTK_WIDGET(gtk_builder_get_object(builder, "chat_page"));*/
    // chats list item template 


    //GtkWidget *button;

write(1, " 1t11 \n", 8);

    

    //gtk_window_set_title(GTK_WINDOW(tapp->window), "uChat");
    //gtk_window_set_default_size(GTK_WINDOW(tapp->window), 200, 200);
write(1, " 1t12 \n", 8);

                //GtkStyleContext *context;
//enter_button = gtk_button_new_with_label("Print");
//gtk_style_context_add_provider_for_screen();
                /*context = gtk_widget_get_style_context(wx);

                gtk_style_context_add_class(context,"BorderColor1");

                GtkWidget* wx2 = GTK_WIDGET(gtk_builder_get_object(builder, "change_button_2"));
                context = gtk_widget_get_style_context(wx2);
                gtk_style_context_add_class(context,"BorderColor2");*/

//gtk_stack_set_visible_child_name( GTK_STACK(tapp->stack), "sign_up_page" );
//gtk_stack_get_child_by_name( GTK_STACK(tapp->stack), "sign_up_page" );
                    //gtk_stack_set_visible_child( GTK_STACK(tapp->stack), "sign_in_page" );
    //gtk_stack_set_transition_duration( GTK_STACK(tapp->stack), 300 );
write(1, " 1t13 \n", 8);
    //gtk_stack_set_visible_child_full( GTK_STACK(tapp->stack), "sign_in_page", GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT );
write(1, " 1t14 \n", 8);
    //gtk_stack_set_visible_child_name( GTK_STACK(tapp->stack), "sign_up_page");
write(1, " 1t15 \n", 8);

    //gtk_widget_show( GTK_WIDGET(tapp->stack) );
    //gtk_main();
    //gtk_button_set_image(button, null);
    return tapp;
    
}

static t_sign_page* mx_load_sign_up( /*t_settings* sets,*/ GtkBuilder* builder ) { 

    t_sign_page* tpage = (t_sign_page*)malloc( sizeof(t_sign_page*) );
    //GtkBuilder* builder = gtk_builder_new_from_file("uchat.glade");
    //gtk_builder_add_from_file( builder, "uchat.glade", NULL);
    tpage->type = 1;
    // 2 load sign up page 
    //t_sign_page* tsup = (t_sign_page*)malloc( sizeof(t_sign_page*) );
    GtkWidget* page = GTK_WIDGET(gtk_builder_get_object(builder, "sign_up_page"));

    //GtkWidget* sign_box = GTK_WIDGET(gtk_builder_get_object(builder, "sign_box_1"));
    GtkWidget* sign_label = GTK_WIDGET(gtk_builder_get_object(builder, "sign_label_1"));

    //tpage->change_button 
    GtkWidget* change_button = GTK_WIDGET(gtk_builder_get_object(builder, "change_button_1"));
    g_signal_connect( change_button, "clicked", G_CALLBACK(mx_change_b_1_signal), NULL );
    GtkWidget* enter_button = GTK_WIDGET(gtk_builder_get_object(builder, "enter_button_1"));
    g_signal_connect( enter_button, "clicked", G_CALLBACK(mx_enter_b_1_signal), NULL );

    GtkWidget* login_entry = GTK_WIDGET(gtk_builder_get_object(builder, "login_entry_1"));
    GtkWidget* login_label = GTK_WIDGET(gtk_builder_get_object(builder, "login_label_1"));
    GtkWidget* name_entry = GTK_WIDGET(gtk_builder_get_object(builder, "name_entry_1"));
    GtkWidget* name_label = GTK_WIDGET(gtk_builder_get_object(builder, "name_label_1"));
    GtkWidget* password_entry = GTK_WIDGET(gtk_builder_get_object(builder, "password_entry_1"));
    GtkWidget* password_label = GTK_WIDGET(gtk_builder_get_object(builder, "password_label_1"));
    GtkWidget* repeat_password_entry = GTK_WIDGET(gtk_builder_get_object(builder, "repeat_password_entry_1"));
    GtkWidget* repeat_password_label = GTK_WIDGET(gtk_builder_get_object(builder, "repeat_password_label_1"));
    //tapp->sign_up_page = tsup;

    //GtkWidget *button;
    GtkStyleContext *context;
    context = gtk_widget_get_style_context( page);
    gtk_style_context_add_class(context,"SignPage");
    context = gtk_widget_get_style_context(sign_label);
    gtk_style_context_add_class(context,"SignMainLabel");

    context = gtk_widget_get_style_context(login_label);
    gtk_style_context_add_class(context,"SignLabel");
    context = gtk_widget_get_style_context( login_entry);
    gtk_style_context_add_class(context,"SignEntry");

    context = gtk_widget_get_style_context(name_label);
    gtk_style_context_add_class(context,"SignLabel");
    context = gtk_widget_get_style_context( name_entry);
    gtk_style_context_add_class(context,"SignEntry");

    context = gtk_widget_get_style_context(password_label);
    gtk_style_context_add_class(context,"SignLabel");
    context = gtk_widget_get_style_context( password_entry);
    gtk_style_context_add_class(context,"SignEntry");

    context = gtk_widget_get_style_context(repeat_password_label);
    gtk_style_context_add_class(context,"SignLabel");
    context = gtk_widget_get_style_context( repeat_password_entry);
    gtk_style_context_add_class(context,"SignEntry");

    context = gtk_widget_get_style_context( change_button);
    gtk_style_context_add_class(context,"SignChange");
    context = gtk_widget_get_style_context( enter_button);
    gtk_style_context_add_class(context,"SignEnter");
    //gtk_overlay_add_overlay(GTK_GRID(grid), button, 0, 0, 1, 1);

    /*GtkCssProvider* css_provider;
    css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(css_provider, "uchat.css", NULL);*/

    //css_set();

    
    //gtk_button_set_image(button, null);
    return tpage;
}

static t_sign_page* mx_load_sign_in( /*t_settings* sets,*/ GtkBuilder* builder ) {

    t_sign_page* tpage = (t_sign_page*)malloc( sizeof(t_sign_page*) );
    //GtkBuilder* builder = gtk_builder_new_from_file("uchat.glade");

    tpage->type = 2;

    GtkWidget* page = GTK_WIDGET(gtk_builder_get_object(builder, "sign_in_page"));
    //GtkWidget* sign_box = GTK_WIDGET(gtk_builder_get_object(builder, "sign_box_2"));
    GtkWidget* sign_label = GTK_WIDGET(gtk_builder_get_object(builder, "sign_label_2"));

    GtkWidget* change_button = GTK_WIDGET(gtk_builder_get_object(builder, "change_button_2"));
    g_signal_connect( change_button, "clicked", G_CALLBACK(mx_change_b_2_signal), NULL );
    GtkWidget* enter_button = GTK_WIDGET(gtk_builder_get_object(builder, "enter_button_2"));
    g_signal_connect( enter_button, "clicked", G_CALLBACK(mx_enter_b_2_signal), NULL );

    GtkWidget* login_entry = GTK_WIDGET(gtk_builder_get_object(builder, "login_entry_2"));
    GtkWidget* login_label = GTK_WIDGET(gtk_builder_get_object(builder, "login_label_2"));
    GtkWidget* password_entry = GTK_WIDGET(gtk_builder_get_object(builder, "password_entry_2"));
    GtkWidget* password_label = GTK_WIDGET(gtk_builder_get_object(builder, "password_label_2"));

    /*GtkCssProvider* css_provider;
    css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(css_provider, "uchat.css", NULL);*/
    GtkStyleContext *context;
    context = gtk_widget_get_style_context( page);
    gtk_style_context_add_class(context,"SignPage");
    context = gtk_widget_get_style_context(sign_label);
    gtk_style_context_add_class(context,"SignMainLabel");

    context = gtk_widget_get_style_context(login_label);
    gtk_style_context_add_class(context,"SignLabel");
    context = gtk_widget_get_style_context( login_entry);
    gtk_style_context_add_class(context,"SignEntry");

    context = gtk_widget_get_style_context(password_label);
    gtk_style_context_add_class(context,"SignLabel");
    context = gtk_widget_get_style_context( password_entry);
    gtk_style_context_add_class(context,"SignEntry");

    context = gtk_widget_get_style_context( change_button);
    gtk_style_context_add_class(context,"SignChange");
    context = gtk_widget_get_style_context( enter_button);
    gtk_style_context_add_class(context,"SignEnter");
    //css_set();

    
    //gtk_button_set_image(button, null);
    return tpage;
}

static t_chats_list_page* mx_load_chats_list( /*t_settings* sets,*/ GtkBuilder* builder ) {

    t_chats_list_page* tpage = (t_chats_list_page*)malloc( sizeof(t_chats_list_page*) );
    // tpage->type = 3;

    GObject* page = gtk_builder_get_object(builder, "chat_list_page") ;

    GObject* search_revealer = gtk_builder_get_object(builder, "search_revealer_3") ;
    GObject* search_box = gtk_builder_get_object(builder, "search_box_3") ;
    GObject* close_search_button = gtk_builder_get_object(builder, "close_search_button_3") ;
    GObject* search_entry = gtk_builder_get_object(builder, "search_entry_3") ;
    GObject* search_button = gtk_builder_get_object(builder, "search_button_3") ;
    //tpage->close_search_button = gtk_builder_get_object(builder, "close_search_button_3");
    //tpage->search_entry = gtk_builder_get_object(builder, "search_entry_3");
    //tpage->search_button = gtk_builder_get_object(builder, "search_button_3");

    GObject* bottom_box = gtk_builder_get_object(builder, "bottom_box_3") ;
    GObject* add_chat_button = gtk_builder_get_object(builder, "add_chat_b_3") ;
    //GtkWidget* im2 = GTK_WIDGET( gtk_builder_get_object(builder, "add_chat_b_im_3") );
    GObject* profile_button = gtk_builder_get_object(builder, "profile_b_3") ;
    //GtkWidget* im3 = GTK_WIDGET( gtk_builder_get_object(builder, "profile_b_im_3") );
    GObject* find_button = gtk_builder_get_object(builder, "find_b_3") ;
    //GtkWidget* im4 = GTK_WIDGET( gtk_builder_get_object(builder, "find_b_im_3") );

    // GObject* search_scroller = gtk_builder_get_object(builder, "search_scroller_3") ;
    GObject* search_list = gtk_builder_get_object(builder, "search_list_3") ;
    // GObject* searcharr = NULL;

    GObject* main_box = gtk_builder_get_object(builder, "chat_list_box_3") ;
    tpage->chatarr = NULL;

    /*t_overlay* profile_o = (t_overlay*)malloc( sizeof(t_overlay*) );
    GObject* overlay_background = gtk_builder_get_object(builder, "overlay_background_3") ;
    GObject* overlay_main = gtk_builder_get_object(builder, "profile_3") ;
    // profile_o->overlay_main = GTK_WIDGET(gtk_builder_get_object(builder, "main_box_3") );
    tpage->profile_overlay = profile_o;*/

    /*t_overlay* add_chat_o = (t_overlay*)malloc( sizeof(t_overlay*) );
    GObject* overlay_background = gtk_builder_get_object(builder, "overlay_background_3") ;
    GObject* overlay_main = gtk_builder_get_object(builder, "add_chat_3") ;
    // add_chat_o->overlay_main = GTK_WIDGET(gtk_builder_get_object(builder, "main_box_3") );
    tpage->add_chat_overlay = add_chat_o;*/

    g_signal_connect(  close_search_button, "clicked", G_CALLBACK( mx_close_search_3_signal ), NULL );
    g_signal_connect(  search_button, "clicked", G_CALLBACK( mx_search_3_signal ), NULL );

    g_signal_connect(  add_chat_button, "clicked", G_CALLBACK( mx_add_chat_3_signal ), NULL );
    g_signal_connect(  profile_button, "clicked", G_CALLBACK( mx_show_profile_3_signal ), NULL );
    g_signal_connect( /*tpage->*/find_button, "clicked", G_CALLBACK( mx_show_search_3_signal ), NULL );

    //g_signal_connect( im3, "clicked", G_CALLBACK( mx_show_search_3_signal ), NULL );
    // gtk_list_box_set_filter_func( GTK_LIST_BOX(tpage->main_box), ( mx_chat_list_filter_3 ), NULL, NULL);
    // gtk_list_box_set_sort_func( GTK_LIST_BOX(tpage->main_box), ( mx_chat_list_sort_3 ), NULL, NULL);

    // gtk_list_box_set_filter_func( GTK_LIST_BOX(tpage->search_list), ( mx_search_list_filter_3 ), NULL, NULL);
    // gtk_list_box_set_sort_func( GTK_LIST_BOX(tpage->search_list), ( mx_search_list_sort_3 ), NULL, NULL);
    gtk_list_box_set_filter_func( 
        GTK_LIST_BOX(main_box/*gtk_builder_get_object(app->builder, "chat_list_box_3")*/), 
        ( mx_chat_list_filter_3 ), NULL, NULL);
    gtk_list_box_set_sort_func( 
        GTK_LIST_BOX(main_box/*gtk_builder_get_object(app->builder, "chat_list_box_3")*/), 
        ( mx_chat_list_sort_3 ), NULL, NULL);

    gtk_list_box_set_filter_func( 
        GTK_LIST_BOX(search_list/*gtk_builder_get_object(app->builder, "chat_list_box_3")*/), 
        ( mx_search_list_filter_3 ), NULL, NULL);
    gtk_list_box_set_sort_func( 
        GTK_LIST_BOX(search_list/*gtk_builder_get_object(app->builder, "chat_list_box_3")*/), 
        ( mx_search_list_sort_3 ), NULL, NULL);



    gtk_widget_show_all( GTK_WIDGET( main_box) );
    gtk_widget_show_all( GTK_WIDGET( search_list) );
write(1, "\n context ", 11);
    GtkStyleContext *context;
    context = gtk_widget_get_style_context( GTK_WIDGET( page) );
    gtk_style_context_add_class(context,"ChatsListPage");
write(1, " 1 ", 4);

    context = gtk_widget_get_style_context( GTK_WIDGET( search_revealer) );
    gtk_style_context_add_class(context,"");
write(1, " 2 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET(search_box) );
    gtk_style_context_add_class(context,"ChatsListBox");
write(1, " 3 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET( close_search_button) );
    gtk_style_context_add_class(context,"CLCButton");
write(1, " 4 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET( search_entry) );
    gtk_style_context_add_class(context,"ChatsListItemCountLabel");
write(1, " 5 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET( search_button) );
    gtk_style_context_add_class(context,"ClearButton");
write(1, " 6 ", 4);

    context = gtk_widget_get_style_context( GTK_WIDGET(bottom_box) );
    gtk_style_context_add_class(context,"ChatsListBox");
write(1, " 7 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET( add_chat_button) );
    gtk_style_context_add_class(context,"CLCButton");
write(1, " 8 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET( profile_button) );
    gtk_style_context_add_class(context,"CLCButton");
write(1, " 9 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET( find_button) );
    gtk_style_context_add_class(context,"CLCButton");
write(1, "10 ", 4);

    context = gtk_widget_get_style_context( GTK_WIDGET( main_box) );
    gtk_style_context_add_class(context,"ChatsListMainBox");
write(1, "11 ", 4);

    context = gtk_widget_get_style_context( GTK_WIDGET( search_list) ); // search overlay
    gtk_style_context_add_class(context,"ChatsListMainBox");
write(1, "12 ", 4);

//     context = gtk_widget_get_style_context( tpage->profile_overlay->overlay_background );
//     gtk_style_context_add_class(context,"");
// write(1, "13 ", 4);
//     context = gtk_widget_get_style_context( tpage->profile_overlay->overlay_main );
//     gtk_style_context_add_class(context,"");
// write(1, "14 ", 4);
//     /*context = gtk_widget_get_style_context( tpage-> );
//     gtk_style_context_add_class(context,"");*/
//     context = gtk_widget_get_style_context( tpage->add_chat_overlay->overlay_background );
//     gtk_style_context_add_class(context,"");
// write(1, "15 ", 4);
//     context = gtk_widget_get_style_context( tpage->add_chat_overlay->overlay_main );
//     gtk_style_context_add_class(context,"");
write(1, "16 ", 4);
    /*context = gtk_widget_get_style_context( tpage-> );
    gtk_style_context_add_class(context,"");*/
    
    //gtk_image_new_from_pixbuf();
    //gtk_button_set_image(button, null);
    

    /*GdkPixbuf* pix1 = NULL;
    //GtkImage* im1 = NULL;
    GError** error = NULL;*/
    /*pix1 = gdk_pixbuf_new_from_file_at_scale("resources/arrow_left_1.png", 50, 50, 0, NULL);
    gtk_image_set_from_pixbuf( NULL, pix1);
    pix1 = gdk_pixbuf_new_from_file_at_scale("resources/search_icon_1.png", 50, 50, 0, NULL);
    gtk_image_set_from_pixbuf( NULL, pix1);*/
    /*//pix1 = gdk_pixbuf_new_from_file_at_scale("resources/arrow_left_1.png", 50, 50, false, NULL);
write(1, " load clp 41 \n", 14);    
    pix1 = gdk_pixbuf_new_from_resource_at_scale("resources/arrow_left_1.png", 50, 50, false, error);
write(1, " load clp 412\n", 14);
    //gtk_image_set_from_pixbuf( GTK_IMAGE(im2), pix1);
    GtkWidget* im2 = gtk_image_new_from_pixbuf( pix1 );
write(1, " load clp 42 \n", 14);
            //g_object_unref(G_OBJECT(pix1) );
    pix1 = gdk_pixbuf_new_from_resource_at_scale("resources/arrow_left_1.png", 50, 50, true, error);
    //gtk_image_set_from_pixbuf( GTK_IMAGE(im3), pix1);
    GtkWidget* im3 = gtk_image_new_from_pixbuf( pix1 );
            //g_object_unref(G_OBJECT(pix1) );
write(1, " load clp 43 \n", 14);
    pix1 = gdk_pixbuf_new_from_resource_at_scale("resources/search_icon_1.png", 50, 50, false, error);
    //gtk_image_set_from_pixbuf( GTK_IMAGE(im4), pix1);
    GtkWidget* im4 = gtk_image_new_from_pixbuf( pix1 );
    //gtk_container_add(GTK_CONTAINER(tpage->find_button), im4);*/
/*write(1, " load clp 440\n", 14);
    GtkWidget* im2 = gtk_image_new_from_file( "/resources/search_icon_1.png" );
write(1, " load clp 441\n", 14);
    GtkWidget* im3 = gtk_image_new_from_file( "/home/rtw/uchat/rmedvid/resources/search_icon_1.png" );
write(1, " load clp 442\n", 14);
    GtkWidget* im4 = gtk_image_new_from_file( "/home/rtw/uchat/rmedvid/resources/search_icon_1.png" );
write(1, " load clp 443\n", 14);

            //g_object_unref(G_OBJECT(pix1) );
    //GtkWidget* im5 = gtk_image_new_from_file("resources/pin_icon_1.png");
    gtk_button_set_always_show_image(GTK_BUTTON(tpage->add_chat_button), TRUE);
    gtk_button_set_always_show_image(GTK_BUTTON(tpage->profile_button), TRUE);
    gtk_button_set_always_show_image(GTK_BUTTON(tpage->find_button), TRUE);

    gtk_button_set_image(GTK_BUTTON(tpage->add_chat_button), im2);
    gtk_button_set_image(GTK_BUTTON(tpage->profile_button), im3);
    gtk_button_set_image(GTK_BUTTON(tpage->find_button), im4);
write(1, " load clp 449\n", 14);*/
    


    return tpage;
}

static t_chat_page* mx_load_chat_page( /*t_settings* sets,*/ GtkBuilder* builder ) {

    t_chat_page* tpage = (t_chat_page*)malloc( sizeof(t_chat_page*) );
    // tpage->type = 4;

    GObject* page = gtk_builder_get_object(builder, "chat_page");

    //tpage->search_revealer = GTK_WIDGET(gtk_builder_get_object(builder, "search_revealer_3") );
    GObject* top_box = gtk_builder_get_object(builder, "top_box_4") ;
    GObject* profile_button = gtk_builder_get_object(builder, "profile_button_4") ;
    GObject* exit_chat_button = gtk_builder_get_object(builder, "exit_chat_button_4") ;
    //tpage->close_search_button = gtk_builder_get_object(builder, "close_search_button_3");
    GObject* label_box = gtk_builder_get_object(builder, "label_box_4") ;
    GObject* name_label = gtk_builder_get_object(builder, "chat_name_l_4") ;
    GObject* online_label = gtk_builder_get_object(builder, "chat_status_l_4") ;
    //tpage->close_search_button = gtk_builder_get_object(builder, "close_search_button_3");

    GObject* bottom_box = gtk_builder_get_object(builder, "send_box_4") ;
    GObject* attach_button = gtk_builder_get_object(builder, "send_attach_button_4") ;
    //GtkWidget* im2 = GTK_WIDGET( gtk_builder_get_object(builder, "add_chat_b_im_3") );
    GObject* main_entry = gtk_builder_get_object(builder, "send_entry_4") ;
    GObject* send_button = gtk_builder_get_object(builder, "send_send_button_4") ;
    //GtkWidget* im4 = GTK_WIDGET( gtk_builder_get_object(builder, "find_b_im_3") );

    //tpage->search_scroller = GTK_WIDGET(gtk_builder_get_object(builder, "search_scroller_3") );
    //tpage->search_list = GTK_WIDGET(gtk_builder_get_object(builder, "search_list_3") );

    GObject* main_box = gtk_builder_get_object(builder, "main_box_4") ;
    tpage->messagearr = NULL;

    /*t_overlay* profile_o = (t_overlay*)malloc( sizeof(t_overlay*) );
    GObject* overlay_background = gtk_builder_get_object(builder, "overlay_background_4") ;
    GObject* overlay_main = gtk_builder_get_object(builder, "profile_4") ;
    // profile_o->overlay_main = GTK_WIDGET(gtk_builder_get_object(builder, "main_box_3") ;
    tpage->profile_overlay = profile_o;*/

    /*g_signal_connect( GTK_WIDGET(tpage->close_search_button), "clicked", G_CALLBACK( mx_close_search_3_signal ), NULL );
    g_signal_connect( GTK_WIDGET(tpage->search_button), "clicked", G_CALLBACK( mx_search_3_signal ), NULL );*/
    gtk_list_box_set_filter_func( 
        GTK_LIST_BOX(main_box/*gtk_builder_get_object(app->builder, "main_box_4")*/), 
        ( mx_message_list_filter_4 ), NULL, NULL);
    gtk_list_box_set_sort_func( 
        GTK_LIST_BOX(main_box/*gtk_builder_get_object(app->builder, "main_box_4")*/), 
        ( mx_message_list_sort_4 ), NULL, NULL);


    g_signal_connect( exit_chat_button, "clicked", G_CALLBACK( mx_exit_chat_4_signal ), NULL );
    g_signal_connect( profile_button, "clicked", G_CALLBACK( mx_show_chat_profile_4_signal ), NULL );
    //g_signal_connect( tpage->profile_button, "clicked", G_CALLBACK( mx_show_profile_4_signal ), NULL );
    g_signal_connect( attach_button, "clicked", G_CALLBACK( mx_attach_4_signal ), NULL );
    g_signal_connect( send_button, "clicked", G_CALLBACK( mx_send_4_signal ), NULL );

    //g_signal_connect( im3, "clicked", G_CALLBACK( mx_show_search_3_signal ), NULL );
    gtk_list_box_set_filter_func( GTK_LIST_BOX( main_box), ( mx_message_list_filter_4 ), NULL, NULL);
    gtk_list_box_set_sort_func( GTK_LIST_BOX( main_box), ( mx_message_list_sort_4 ), NULL, NULL);

    GtkStyleContext *context;
write(1, "\n context ", 11);
    context = gtk_widget_get_style_context( GTK_WIDGET( page) );
    gtk_style_context_add_class(context,"ChatsListPage");
write(1, " 1 ", 4);

    context = gtk_widget_get_style_context( GTK_WIDGET(top_box) );
    gtk_style_context_add_class(context,"ChatsListBox");
write(1, " 2 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET( exit_chat_button) );
    gtk_style_context_add_class(context,"CLCButton");
write(1, " 3 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET( profile_button) );
    gtk_style_context_add_class(context,"ClearButton");
write(1, " 4 ", 4);

    context = gtk_widget_get_style_context( GTK_WIDGET(label_box) );
    gtk_style_context_add_class(context,"ChatsListBox");
write(1, " 5 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET(name_label) );
    gtk_style_context_add_class(context,"ChatNameLabel");
write(1, " 6 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET(online_label) );
    gtk_style_context_add_class(context,"ChatStatusLabel");
write(1, " 7 ", 4);
    // ... 

    context = gtk_widget_get_style_context( GTK_WIDGET(bottom_box) );
    gtk_style_context_add_class(context,"ChatsListBox");
write(1, " 8 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET( attach_button) );
    gtk_style_context_add_class(context,"CLCButton");
write(1, " 9 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET( main_entry) );
    gtk_style_context_add_class(context,"ChatMessageEntry");
write(1, "10 ", 4);
    context = gtk_widget_get_style_context( GTK_WIDGET( send_button) );
    gtk_style_context_add_class(context,"CLCButton");
write(1, "11 ", 4);

    context = gtk_widget_get_style_context( GTK_WIDGET( main_box) );
    gtk_style_context_add_class(context,"ChatsListMainBox");
    
    return tpage;
}

static void mx_load_overlays( /*t_settings* sets,*/ GtkBuilder* builder ) {

write(1, "\n context ", 11);
    GObject* main_stack = gtk_builder_get_object(builder, "o_overlay");
    GtkStyleContext *context;
    context = gtk_widget_get_style_context( GTK_WIDGET( main_stack) );
    gtk_style_context_add_class(context,"OverlayStack");
// ============================================================================ o1 + 
write(1, " 1 ", 4);
    GObject* main_box_1 = gtk_builder_get_object(builder, "profile_3") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_box_1) );
    gtk_style_context_add_class(context,"OverlayMainBox");
write(1, " 2 ", 4);
    GObject* main_label_1 = gtk_builder_get_object(builder, "o_main_label_1") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_label_1) );
    gtk_style_context_add_class(context,"OverlayName");
write(1, " 3 ", 4);
    GObject* edit_button_1 = gtk_builder_get_object(builder, "o_edit_button_1") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(edit_button_1) );
    gtk_style_context_add_class(context,"CLCButton");
    g_signal_connect( edit_button_1, "clicked", G_CALLBACK( mx_overlay_1_edit_signal ), NULL );
write(1, " 4 ", 4);
    GObject* close_button_1 = gtk_builder_get_object(builder, "o_exit_button_1") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(close_button_1) );
    gtk_style_context_add_class(context,"CLCButton");
    g_signal_connect( close_button_1, "clicked", G_CALLBACK( mx_overlay_1_exit_signal ), NULL );
write(1, " 5 ", 4);
    GObject* name_label_1 = gtk_builder_get_object(builder, "o_profile_name_1") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(name_label_1) );
    gtk_style_context_add_class(context,"OverlayNameLabel");
write(1, " 6 ", 4);
    GObject* status_label_1 = gtk_builder_get_object(builder, "o_profile_status_1") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(status_label_1) );
    gtk_style_context_add_class(context,"OverlayStatusLabel");
write(1, " 7 ", 4);
    GObject* description_label_1 = gtk_builder_get_object(builder, "o_profile_bio_1") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(description_label_1) );
    gtk_style_context_add_class(context,"OverlayBioLabel");
write(1, " 8 ", 4);
    GObject* sign_out_button_1 = gtk_builder_get_object(builder, "o_sign_out_button_1") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(sign_out_button_1) );
    gtk_style_context_add_class(context,"OverlayButton");
    g_signal_connect( sign_out_button_1, "clicked", G_CALLBACK( mx_overlay_1_sign_out_signal ), NULL );
write(1, " 9 ", 4);
    GObject* del_acc_button_1 = gtk_builder_get_object(builder, "o_del_acc_button_1") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(del_acc_button_1) );
    gtk_style_context_add_class(context,"OverlayRedButton");
    g_signal_connect( del_acc_button_1, "clicked", G_CALLBACK( mx_overlay_1_del_account_signal ), NULL );
// ========================================================================================================= o2 + 
write(1, "11 ", 4);
    GObject* main_box_2 = gtk_builder_get_object(builder, "edit_profile_3") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_box_2) );
    gtk_style_context_add_class(context,"OverlayMainBox");
write(1, "12 ", 4);
    GObject* main_label_2 = gtk_builder_get_object(builder, "o_main_label_2") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_label_2) );
    gtk_style_context_add_class(context,"OverlayName");
write(1, "13 ", 4);
    GObject* save_button_2 = gtk_builder_get_object(builder, "o_save_button_2") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(save_button_2) );
    gtk_style_context_add_class(context,"CLCButton");
    g_signal_connect( save_button_2, "clicked", G_CALLBACK( mx_overlay_2_save_changes_signal ), NULL );
write(1, "14 ", 4);
    GObject* close_button_2 = gtk_builder_get_object(builder, "o_exit_button_2") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(close_button_2) );
    gtk_style_context_add_class(context,"CLCButton");
    g_signal_connect( close_button_2, "clicked", G_CALLBACK( mx_overlay_2_exit_signal ), NULL );
write(1, "15 ", 4);
    GObject* name_label_2 = gtk_builder_get_object(builder, "o_uname_label_2") ; // name 
    context = gtk_widget_get_style_context( GTK_WIDGET(name_label_2) );
    gtk_style_context_add_class(context,"OverlayEntryLabel");
write(1, "15 ", 4);
    GObject* name_entry_2 = gtk_builder_get_object(builder, "o_uname_entry_2") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(name_entry_2) );
    gtk_style_context_add_class(context,"OverlayEntry");
write(1, "17 ", 4);
    GObject* bio_label_2 = gtk_builder_get_object(builder, "o_ubio_label_2") ; // bio 
    context = gtk_widget_get_style_context( GTK_WIDGET(bio_label_2) );
    gtk_style_context_add_class(context,"OverlayEntryLabel");
write(1, "18 ", 4);
    GObject* bio_entry_2 = gtk_builder_get_object(builder, "o_ubio_entry_2") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(bio_entry_2) );
    gtk_style_context_add_class(context,"OverlayEntry");
// ========================================================================================================= o3 + 
write(1, "21 ", 4);
    GObject* main_box_3 = gtk_builder_get_object(builder, "add_chat_3") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_box_3) );
    gtk_style_context_add_class(context,"OverlayMainBox");
write(1, "22 ", 4);
    GObject* main_label_3 = gtk_builder_get_object(builder, "o_main_label_3") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_label_3) );
    gtk_style_context_add_class(context,"OverlayName");
write(1, "23 ", 4);
    GObject* add_button_3 = gtk_builder_get_object(builder, "o_add_button_3") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(add_button_3) );
    gtk_style_context_add_class(context,"CLCButton");
    g_signal_connect( add_button_3, "clicked", G_CALLBACK( mx_overlay_3_add_chat_signal ), NULL );
write(1, "24 ", 4);
    GObject* close_button_3 = gtk_builder_get_object(builder, "o_exit_button_3") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(close_button_3) );
    gtk_style_context_add_class(context,"CLCButton");
    g_signal_connect( close_button_3, "clicked", G_CALLBACK( mx_overlay_3_exit_signal ), NULL );
write(1, "25 ", 4);
    GObject* cname_label_3 = gtk_builder_get_object(builder, "o_cname_label_3") ; // name 
    context = gtk_widget_get_style_context( GTK_WIDGET(cname_label_3) );
    gtk_style_context_add_class(context,"OverlayEntryLabel");
write(1, "26 ", 4);
    GObject* cname_entry_3 = gtk_builder_get_object(builder, "o_cname_entry_3") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(cname_entry_3) );
    gtk_style_context_add_class(context,"OverlayEntry");
write(1, "27 ", 4);
    GObject* cdesk_label_3 = gtk_builder_get_object(builder, "o_cdesc_label_3") ; // desk
    context = gtk_widget_get_style_context( GTK_WIDGET(cdesk_label_3) );
    gtk_style_context_add_class(context,"OverlayEntryLabel");
write(1, "28 ", 4);
    GObject* cdesc_entry_3 = gtk_builder_get_object(builder, "o_cdesc_entry_3") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(cdesc_entry_3) );
    gtk_style_context_add_class(context,"OverlayEntry");



// ========================================================================================================= o4 + 
write(1, "31 ", 4);
    GObject* main_box_4 = gtk_builder_get_object(builder, "chat_profile_4") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_box_4) );
    gtk_style_context_add_class(context,"OverlayMainBox");
write(1, "32 ", 4);
    GObject* main_label_4 = gtk_builder_get_object(builder, "o_main_label_4") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_label_4) );
    gtk_style_context_add_class(context,"OverlayName");
write(1, "33 ", 4);
    GObject* save_button_4 = gtk_builder_get_object(builder, "o_edit_button_4") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(save_button_4) );
    gtk_style_context_add_class(context,"CLCButton");
    g_signal_connect( save_button_4, "clicked", G_CALLBACK( mx_overlay_4_edit_signal ), NULL );
write(1, "34 ", 4);
    GObject* close_button_4 = gtk_builder_get_object(builder, "o_exit_button_4") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(close_button_4) );
    gtk_style_context_add_class(context,"CLCButton");
    g_signal_connect( close_button_4, "clicked", G_CALLBACK( mx_overlay_4_exit_signal ), NULL );
write(1, "35 ", 4);
    GObject* chat_name_label_4 = gtk_builder_get_object(builder, "o_chat_name_4") ; // name 
    context = gtk_widget_get_style_context( GTK_WIDGET(chat_name_label_4) );
    gtk_style_context_add_class(context,"OverlayNameLabel");
write(1, "36 ", 4);
    GObject* chat_status_label_4 = gtk_builder_get_object(builder, "o_chat_status_4") ; // desk
    context = gtk_widget_get_style_context( GTK_WIDGET(chat_status_label_4) );
    gtk_style_context_add_class(context,"OverlayStatusLabel");
write(1, "37 ", 4);
    GObject* chat_desk_4 = gtk_builder_get_object(builder, "o_chat_desk_4") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(chat_desk_4) );
    gtk_style_context_add_class(context,"OverlayBioLabel");
write(1, "38 ", 4);
    GObject* leave_del_button_4 = gtk_builder_get_object(builder, "o_del_acc_button_1") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(leave_del_button_4) );
    gtk_style_context_add_class(context,"OverlayRedButton");
    // in show 
    g_signal_connect( leave_del_button_4, "clicked", G_CALLBACK( mx_overlay_4_leave_signal ), NULL );
    g_signal_connect( leave_del_button_4, "clicked", G_CALLBACK( mx_overlay_4_delete_signal ), NULL );
// ========================================================================================================= o5
write(1, "41 ", 4);
    GObject* main_box_5 = gtk_builder_get_object(builder, "edit_chat_4") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_box_5) );
    gtk_style_context_add_class(context,"OverlayMainBox");
write(1, "42 ", 4);
    GObject* main_label_5 = gtk_builder_get_object(builder, "o_main_label_5") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_label_5) );
    gtk_style_context_add_class(context,"OverlayName");
write(1, "43 ", 4);
    GObject* save_button_5 = gtk_builder_get_object(builder, "o_save_button_5") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(save_button_5) );
    gtk_style_context_add_class(context,"CLCButton");
    g_signal_connect( save_button_5, "clicked", G_CALLBACK( mx_overlay_5_save_changes_signal ), NULL );
write(1, "44 ", 4);
    GObject* close_button_5 = gtk_builder_get_object(builder, "o_exit_button_5") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(close_button_5) );
    gtk_style_context_add_class(context,"CLCButton");
    g_signal_connect( close_button_5, "clicked", G_CALLBACK( mx_overlay_5_exit_signal ), NULL );
write(1, "45 ", 4);
    GObject* cname_entry_5 = gtk_builder_get_object(builder, "o_cname_entry_5") ; // name 
    context = gtk_widget_get_style_context( GTK_WIDGET(cname_entry_5) );
    gtk_style_context_add_class(context,"OverlayEntry");
write(1, "46 ", 4);
    GObject* cname_label_5 = gtk_builder_get_object(builder, "o_cname_label_5") ; // desk
    context = gtk_widget_get_style_context( GTK_WIDGET(cname_label_5) );
    gtk_style_context_add_class(context,"OverlayEntryLabel");
write(1, "47 ", 4);
    GObject* cdesk_entry_5 = gtk_builder_get_object(builder, "o_cdesk_entry_5") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(cdesk_entry_5) );
    gtk_style_context_add_class(context,"OverlayEntry");
write(1, "48 ", 4);
    GObject* cdesk_label_5 = gtk_builder_get_object(builder, "o_cdesk_label_5") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(cdesk_label_5) );
    gtk_style_context_add_class(context,"OverlayEntryLabel");
// ========================================================================================================= o6
write(1, "51 ", 4);
    GObject* main_box_6 = gtk_builder_get_object(builder, "user_profile_4") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_box_6) );
    gtk_style_context_add_class(context,"OverlayMainBox");
write(1, "52 ", 4);
    GObject* main_label_6 = gtk_builder_get_object(builder, "o_main_label_6") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(main_label_6) );
    gtk_style_context_add_class(context,"OverlayName");
write(1, "53 ", 4);
    GObject* close_button_6 = gtk_builder_get_object(builder, "o_exit_button_6") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(close_button_6) );
    gtk_style_context_add_class(context,"CLCButton");
    g_signal_connect( close_button_6, "clicked", G_CALLBACK( mx_overlay_6_exit_signal ), NULL );
write(1, "54 ", 4);
    GObject* user_name_label_6 = gtk_builder_get_object(builder, "o_user_name_6") ; // name 
    context = gtk_widget_get_style_context( GTK_WIDGET(user_name_label_6) );
    gtk_style_context_add_class(context,"OverlayNameLabel");
write(1, "55 ", 4);
    GObject* user_status_label_6 = gtk_builder_get_object(builder, "o_user_status_6") ; // bio 
    context = gtk_widget_get_style_context( GTK_WIDGET(user_status_label_6) );
    gtk_style_context_add_class(context,"OverlayStatusLabel");
write(1, "56 ", 4);
    GObject* user_bio_6 = gtk_builder_get_object(builder, "o_user_bio_6") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(user_bio_6) );
    gtk_style_context_add_class(context,"OverlayBioLabel");
write(1, "57 ", 4);
    GObject* send_mes_button_6 = gtk_builder_get_object(builder, "o_send_mes_button_6") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(send_mes_button_6) );
    gtk_style_context_add_class(context,"OverlayButton");
    g_signal_connect( send_mes_button_6, "clicked", G_CALLBACK( mx_overlay_6_send_message_signal ), NULL );
write(1, "58 ", 4);
    GObject* mod_button_6 = gtk_builder_get_object(builder, "o_mod_button_6") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(mod_button_6) );
    gtk_style_context_add_class(context,"OverlayButton");
    g_signal_connect( mod_button_6, "clicked", G_CALLBACK( mx_overlay_6_promote_signal ), NULL );
write(1, "59 ", 4);
    GObject* block_button_6 = gtk_builder_get_object(builder, "o_block_button_6") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(block_button_6) );
    gtk_style_context_add_class(context,"OverlayRedButton");
    g_signal_connect( block_button_6, "clicked", G_CALLBACK( mx_overlay_6_ban_signal ), NULL );
write(1, "60 ", 4);
    GObject* del_button_6 = gtk_builder_get_object(builder, "o_del_button_6") ;
    context = gtk_widget_get_style_context( GTK_WIDGET(del_button_6) );
    gtk_style_context_add_class(context,"OverlayRedButton");
    g_signal_connect( del_button_6, "clicked", G_CALLBACK( mx_overlay_6_del_signal ), NULL );
    // return;
}


