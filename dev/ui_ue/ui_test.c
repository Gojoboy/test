#include "../inc/ui.h"

t_application* tapp;

int ui_test(int argc, char** argv) {

write(1, " t1 \n", 6);

    //g_thread_init(NULL);
    //gdk_threads_init();
    //gtk_init(&argc, &argv);


    tapp = mx_load_ui(&argc, &argv);
    if (tapp ) {}
write(1, " t2 \n", 6);

    /*GtkBuilder* builder = gtk_builder_new();
    gtk_builder_add_from_file( builder, "uchat.glade", NULL);

    //gdk_pixbuf_new_from_file_at_size();
    //gtk_image_set_from_pixbuf(gtk_image_new_from_file(), );
    GtkButton *b1 = GTK_BUTTON(gtk_builder_get_object(builder, "b1"));
    GtkWidget *im1 =  gtk_image_new_from_pixbuf( gdk_pixbuf_new_from_file_at_size("", 50, 50, NULL) );

    gtk_button_set_image(b1, im1);*/
write(1, " t3 \n", 6);
    //window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //g_signal_connect( window, "destroy", G_CALLBACK(destroy), NULL );
    //gtk_container_set_border_width(GTK_CONTAINER(window), 0);

    //w2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //gtk_container_set_border_width(GTK_CONTAINER(window), 0);

    /*button = gtk_button_new_with_label("Click Me!");
    g_signal_connect( button, "clicked", G_CALLBACK(greet), "button" );
    gtk_container_add(GTK_CONTAINER (window), button);*/

    //GtkCssProvider* css_provider;
    //css_provider = gtk_css_provider_new();
    //gtk_css_provider_load_from_file(css_provider, "uchat.css", NULL);

    //css_set();
    //GtkBuilder* builder = gtk_builder_new();
    //gtk_builder_add_from_file( builder, "uchat_src/uchat.glade", NULL);
    //GtkWidget *w2 = GTK_WIDGET(gtk_builder_get_object(builder, "w2"));
    //GtkWidget *w2 = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    //gtk_stack_set_visible_child_name();

    

    gtk_widget_show_all( GTK_WIDGET(tapp->window) );
write(1, " t4 \n", 6);
    if (tapp->stack != NULL) {
write(1, " st-\n", 6);
    }
    if (tapp->window != NULL) {
write(1, " wd-\n", 6);
    }
                //gtk_stack_set_visible_child_full( GTK_STACK(tapp->stack), "sign_up_page", GTK_STACK_TRANSITION_TYPE_NONE );

    
  

    //window = create_window();
    //gtk_widget_show(window);
                //gdk_threads_add_idle();

    gtk_main();
    //gdk_threads_leave();
write(1, " t5 \n", 6);
    
    //gtk_button_set_image(button, null);
    return 0;
}





