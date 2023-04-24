#include "../inc/ui.h"


// entrys` signals


// buttons signals 
gboolean mx_change_b_2_signal( GtkWidget *widget, gpointer data ) {
    if (widget == NULL ||data == NULL) {}
    // 
    const gchar* text1 = gtk_entry_get_text( 
        GTK_ENTRY(gtk_builder_get_object(app->builder, "login_entry_2")) );
    if (text1 != NULL) {
        
    }
    const gchar* text2 = gtk_entry_get_text( 
        GTK_ENTRY(gtk_builder_get_object(app->builder, "password_entry_2")) );
    if (text2 != NULL) {
        
    }
    // request (return t_user or null)

    // 
    gtk_stack_set_visible_child_full( 
        GTK_STACK(gtk_builder_get_object(app->builder, "main_stack")), 
        "sign_up_page", GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT );
    return true;
}
gboolean mx_enter_b_2_signal( GtkWidget *widget, gpointer data ) {
    if (widget == NULL ||data == NULL) {}
    //  check entrys


    // request 


    gtk_stack_set_visible_child_full( 
        GTK_STACK(gtk_builder_get_object(app->builder, "main_stack")), 
        "chat_list_page", GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT );
    return true;
}





