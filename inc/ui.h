#pragma once

// ui 
#include <gtk/gtk.h>
#include <glib.h>
#include <gio/gio.h>
#include <stdbool.h>

#include "../inc/uchat.h"

//
typedef struct s_theme{
    int theme_id;
    char *theme_file;
}               t_theme;
//
/*typedef struct s_settings{
    int window_x;
    int window_y;
    int window_width;
    int window_height;

}               t_settings;*/



typedef struct s_sign_page {
    int type;
    GtkWidget *page;

    GtkWidget *login_entry;
    char *login_prev;
    GtkWidget *name_entry;
    char *name_prev;
    GtkWidget *password_entry;
    char *password_prev;
    GtkWidget *repeat_password_entry;
    char *repeat_password_prev;

    GtkWidget *change_button;
    GtkWidget *enter_button;

}               t_sign_page;
//
typedef struct s_chats_list_overlay{
    int type;
    GtkWidget *overlay_background;
    GtkWidget *overlay_main;

    GtkWidget *overlay_name_label;

    GtkWidget *overlay_type_check_box;


}               t_chats_list_overlay;
// 
typedef struct s_chat_widget {
    GtkWidget *list_item;
    t_chat *chat;
    GtkWidget *main_button;
    GtkWidget *main_box;
    GtkWidget *profile_image;
    GtkWidget *name_count_box;
    GtkWidget *name_label;
    GtkWidget *count_label;
    bool filter;
    int sort; // time of last update
}               t_chat_widget;
// 
typedef struct s_chats_list_page{
    int type;
    GtkWidget *page;

    t_chats_list_overlay *profile_overlay;
    t_chats_list_overlay *add_chat_overlay;
    //t_chats_list_overlay *theme_overlay;

    GtkWidget *search_revealer;
    //GtkWidget *search_box;
    GtkWidget *close_search_button; // (image?)
    GtkWidget *search_entry;
    char *search_prev;
    GtkWidget *search_button;

    //GtkWidget *bottom_box;
    //GtkWidget *contacts_button;
    GtkWidget *add_chat_button;
    GtkWidget *profile_button;
    GtkWidget *find_button;
    //GtkWidget *settings_button;

    GtkWidget *main_box; // (listbox)
    t_chat_widget **chatarr;
    int chatarr_count;
    int chatarr_size;

    GtkWidget *search_scroller;
    GtkWidget *search_list; // (listbox)
    t_chat_widget **searcharr;
    int searcharr_count;
    int searcharr_size;
}               t_chats_list_page;
//
typedef struct s_chat_overlay{
    int type;
    GtkWidget *overlay_background;
    GtkWidget *overlay_main;


}               t_chat_overlay;
//
typedef struct s_message_widget_attachment{
    int type;
    GtkWidget *main_image;
    GtkWidget *name_label;
    GtkWidget *message_label;
}               t_message_widget_attachment;
//
typedef struct s_message_widget{
    GtkWidget *list_item;
    t_message *message;
    GtkWidget *main_button;
    GtkWidget *main_box;
    GtkWidget *name_date_box;
    GtkWidget *message_box;
    GtkWidget *message_label;
    bool filter;
    int sort; // date of send 

    t_message_widget_attachment **message_attachment_boxes;
    int chat_count;
    int chat_size;
}               t_message_widget;
// 
typedef struct s_chat_page {
    int type;
    GtkWidget *page;

    t_chat_overlay *profile_overlay;
    //GtkWidget *top_box;
    GtkWidget *exit_chat_button;
    GtkWidget *profile_button;
    //GtkWidget *chat_box;
    //GtkWidget *chat_profile_image;
    GtkWidget *name_label;
    GtkWidget *online_label;
    //GtkWidget *chat_search_button;

    /*GtkWidget *search_revealer;
    GtkWidget *search_box;
    GtkWidget *close_search_button; // (image?)
    GtkWidget *search_entry;
    GtkWidget *search_button;*/

    GtkWidget *repfor_revealer;
    GtkWidget *repfor_label;

    GtkWidget *attachment_revealer;
    GtkWidget *attachment_label;

    //GtkWidget *bottom_box;
    GtkWidget *attach_button;
    GtkWidget *main_entry;
    GtkWidget *send_button;
    //GtkWidget *emoji_button;

    GtkWidget *main_box; // (listbox)
    t_message_widget **messagearr;
    int messagearr_count;
    int messagearr_size;

}               t_chat_page;
// main app structure
typedef struct s_application {
    // t_settings *settings;
    int type;
    int themeid;
    t_theme **themes;

    GtkApplication *application;
    GObject *window;
    GObject *stack;

    t_sign_page *sign_in_page;
    t_sign_page *sign_up_page;
    t_chats_list_page *chats_list_page;
    t_chat_page *chat_page;

    int menu_type;
    GtkWidget* menu_row;
    

}               t_application;
// 
// 
extern t_application *app;

//extern t_application app;



t_application* mx_load_ui( int* argc, char*** argv );
int ui_test(int argc, char** argv);



gboolean mx_change_b_1_signal( GtkWidget *widget, gpointer data );
gboolean mx_enter_b_1_signal( GtkWidget *widget, gpointer data );



gboolean mx_change_b_2_signal( GtkWidget *widget, gpointer data );
gboolean mx_enter_b_2_signal( GtkWidget *widget, gpointer data );



// search signals
gboolean mx_close_search_3_signal( GtkWidget *widget, gpointer data );
gboolean mx_search_3_signal( GtkWidget *widget, gpointer data );
// chat selection signal
gboolean mx_chat_button_3_signal( GtkWidget *widget, GdkEventButton *event, gpointer data );

gboolean mx_pmenu_1_3_signal( GtkWidget *widget, gpointer data );
// chats list menu buttons
gboolean mx_add_chat_3_signal( GtkWidget *widget, gpointer data );
gboolean mx_chat_list_filter_3( GtkListBoxRow *row, gpointer data );
gint mx_chat_list_sort_3( GtkListBoxRow *row1, GtkListBoxRow *row2, gpointer data );
gboolean mx_search_list_filter_3( GtkListBoxRow *row, gpointer data );
gint mx_search_list_sort_3( GtkListBoxRow *row1, GtkListBoxRow *row2, gpointer data );
// 1
gboolean mx_add_chat_3_signal( GtkWidget *widget, gpointer data );
gboolean mx_show_profile_3_signal( GtkWidget *widget, gpointer data );
gboolean mx_show_search_3_signal( GtkWidget *widget, gpointer data );
// 



// top box signals
gboolean mx_exit_chat_4_signal( GtkWidget *widget, gpointer data );
gboolean mx_show_profile_4_signal( GtkWidget *widget, gpointer data );
// message selection signal
gboolean mx_message_button_4_signal( GtkWidget *widget, GdkEventButton *event, gpointer data );
gboolean mx_pmenu_1_4_signal( GtkWidget *widget, gpointer data );
gboolean mx_pmenu_2_4_signal( GtkWidget *widget, gpointer data );
gboolean mx_message_list_filter_4( GtkListBoxRow *row, gpointer data );
gint mx_message_list_sort_4( GtkListBoxRow *row1, GtkListBoxRow *row2, gpointer data );
// bottom box signals
gboolean mx_attach_4_signal( GtkWidget *widget, gpointer data );
gboolean mx_send_4_signal( GtkWidget *widget, gpointer data );






int mx_load_chat(/* chat_t *chat, gpointer data,*/ int ltype );
int mx_add_chat_message( t_message *message, int position, int type ); // +
int mx_del_chat_message( GtkContainer *lbox, GtkWidget *item );
int mx_change_chat_message(/* message_t *message, gpointer data,*/ int ltype );
int mx_change_chat_info(/* message_t *message, gpointer data,*/ int ltype );

// chats list 
int mx_load_chat_list( /*GtkWidget *widget, gpointer data*/ );
int mx_add_chat( t_chat *chat, gint position ); // + 
int mx_del_chat( GtkListBox *lbox, GtkWidget *item );
int mx_change_chat( GtkListBox *lbox, GtkWidget *item );

// notifications
int mx_show_notification( /*GtkWidget *widget, gpointer data*/ );





