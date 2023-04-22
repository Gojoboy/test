#include "../inc/ui.h"


// entrys` signals


// buttons signals 
gboolean mx_change_b_1_signal( GtkWidget *widget, gpointer data ) {
    if (widget == NULL ||data == NULL) {}
    // 
    


    gtk_stack_set_visible_child_full( GTK_STACK(app->stack), "sign_in_page", GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT );
    return true;
}
gboolean mx_enter_b_1_signal( GtkWidget *widget, gpointer data ) {
    if (widget == NULL ||data == NULL) {}
    //  check entrys


    // request 


    gtk_stack_set_visible_child_full( GTK_STACK(app->stack), "chat_list_overlay", GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT );
    return true;
}






