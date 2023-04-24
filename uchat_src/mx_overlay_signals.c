#include "../inc/ui.h"



// ======================================================================================= chat list overlay signals
gboolean mx_overlay_1_exit_signal( void/*GtkWidget *widget, gpointer data*/ ) { // profile 
write(1, " over 1 ex \n", 13);
//if (widget == NULL && data == NULL) {}
    // clear data 

    // hide overlay 
    gtk_widget_hide( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_overlay")) ); 

    return true;
}
gboolean mx_overlay_1_edit_signal( void/*GtkWidget *widget, gpointer data*/ ) { 
write(1, " over 1 ed \n", 13);
//if (widget == NULL && data == NULL) {}
    // set data 

    // show overlay 
    gtk_widget_show( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_overlay")) ); 
    // change overlay
    gtk_stack_set_visible_child_full( 
        GTK_STACK(gtk_builder_get_object(app->builder, "o_overlay")), 
        "edit_profile_3", GTK_STACK_TRANSITION_TYPE_NONE );
    return true;
}
gboolean mx_overlay_1_sign_out_signal( void/*GtkWidget *widget, gpointer data*/ ) { 
write(1, " over 1 so \n", 13);
//if (widget == NULL && data == NULL) {}
    // 
    // clear data 

    // hide overlay 
    gtk_widget_hide( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_overlay")) ); 
    // change to sign up 
    gtk_stack_set_visible_child_full( 
        GTK_STACK(gtk_builder_get_object(app->builder, "main_stack")), 
        "sign_up_page", GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT );
    return true;
}
gboolean mx_overlay_1_del_account_signal( void/*GtkWidget *widget, gpointer data*/ ) { 
write(1, " over 1 da \n", 13);
//if (widget == NULL && data == NULL) {}
    // clear data ? 
    // del account request 

    // exit 

    gtk_main_quit();
    return true;
}



gboolean mx_overlay_2_exit_signal( void/*GtkWidget *widget, gpointer data*/ ) { // edit profile 
write(1, " over 2 ex \n", 13);
//if (widget == NULL && data == NULL) {}
    // (back to profile)
    gtk_stack_set_visible_child_full( 
        GTK_STACK(gtk_builder_get_object(app->builder, "o_overlay")), 
        "profile_3", GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT );
    return true;
}
gboolean mx_overlay_2_save_changes_signal( void/*GtkWidget *widget, gpointer data*/ ) {
write(1, " over 2 sv \n", 13);
//if (widget == NULL && data == NULL) {}
    // hide overlay 
    gtk_widget_hide( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_overlay")) ); 
    // 
    const gchar* text = gtk_entry_get_text( 
        GTK_ENTRY(gtk_builder_get_object(app->builder, "send_entry_4")) );
    if (text != NULL) {
        
    }
    return true;
}



gboolean mx_overlay_3_exit_signal( void/*GtkWidget *widget, gpointer data*/ ) { // add chat
write(1, " over 3 ex \n", 13);
//if (widget == NULL && data == NULL) {}
    // 
    // 
    // hide overlay 
    gtk_widget_hide( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_overlay")) ); 
    
    return true;
}
gboolean mx_overlay_3_add_chat_signal( void/*GtkWidget *widget, gpointer data*/ ) {
write(1, " over 3 ac \n", 13);
//if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}



/* ============================================================================================================ */
gboolean mx_overlay_4_exit_signal( void/*GtkWidget *widget, gpointer data*/ ) { // chat profile 
write(1, " over 4 ex \n", 13);
//if (widget == NULL && data == NULL) {}
    // 
    gtk_widget_hide( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_overlay")) ); 
    return true;
}
gboolean mx_overlay_4_edit_signal( void/*GtkWidget *widget, gpointer data*/ ) { 
write(1, " over 4 ed \n", 13);
//if (widget == NULL && data == NULL) {}
    // 
    gtk_stack_set_visible_child_full( 
        GTK_STACK(gtk_builder_get_object(app->builder, "o_overlay")), 
        "edit_chat_4", GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT );
    return true;
}
gboolean mx_overlay_4_leave_signal( void/*GtkWidget *widget, gpointer data*/ ) { 
write(1, " over 4 lv \n", 13);
//if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}
gboolean mx_overlay_4_delete_signal( void/*GtkWidget *widget, gpointer data*/ ) { 
write(1, " over 4 del\n", 13);
//if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}



gboolean mx_overlay_5_exit_signal( void/*GtkWidget *widget, gpointer data*/ ) { // edit chat 
write(1, " over 5 ex \n", 13);
// if (widget == NULL && data == NULL) {}
    // 
    gtk_stack_set_visible_child_full( 
        GTK_STACK(gtk_builder_get_object(app->builder, "o_overlay")), 
        "chat_profile_4", GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT );
    return true;
}
gboolean mx_overlay_5_save_changes_signal( void/*GtkWidget *widget, gpointer data*/ ) {
write(1, " over 5 sv \n", 13);
// if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}



gboolean mx_overlay_6_exit_signal( void/*GtkWidget *widget, gpointer data*/ ) { // user profile 
write(1, " over 6 ex \n", 13);
// if (widget == NULL && data == NULL) {}
    // 
    gtk_widget_hide( GTK_WIDGET(gtk_builder_get_object(app->builder, "o_overlay")) ); 
    return true;
}
gboolean mx_overlay_6_send_message_signal( void/*GtkWidget *widget, gpointer data*/ ) {
write(1, " over 6 s m\n", 13);
// if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}
gboolean mx_overlay_6_ban_signal( void/*GtkWidget *widget, gpointer data*/ ) { 
write(1, " over 6 bn \n", 13);
// if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}
gboolean mx_overlay_6_promote_signal( void/*GtkWidget *widget, gpointer data*/ ) { 
write(1, " over 6 pr \n", 13);
// if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}
gboolean mx_overlay_6_del_signal( void/*GtkWidget *widget, gpointer data*/ ) { 
write(1, " over 6 bl \n", 13);
// if (widget == NULL && data == NULL) {}
    // 
    
    return true;
}


