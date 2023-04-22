#pragma once

// all
#include <stdio.h>
#include <stdbool.h>

// ui
//#include "../inc/ui.h"

//
typedef struct s_message_file {
    int mf_id;
    void* mf_file;
    char* mf_name;
    int mf_size;
}               t_message_file;
// 
typedef struct s_message {
    int m_id;
    int u_id;
    char* m_text;
    bool m_is_edited;
    int m_date;

    int m_type;

    int m_form;
    int m_m_id;
    
    t_message_file **m_filearr;
    int m_filearr_count;
    int m_filearr_size;
}               t_message;
// 
typedef struct s_chat {
    int c_id;
    char *c_name;
    void* c_profile_image;
    char *c_description;

    int jt_type;
    int ct_type;
    int cus_type;

    t_message **c_messagearr;
    int c_messagearr_count;
    int c_messagearr_size;
}               t_chat;
// 
typedef struct s_user {
    int u_id;
    char *u_name;
    void* u_profile_image;
    char *u_bio;
    int u_online_date;

    t_chat **u_chatarr;
    int u_chatarr_count;
    int u_chatarr_size;
}               t_user;

extern t_user *user;

