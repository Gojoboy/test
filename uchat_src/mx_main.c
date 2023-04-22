#include "../inc/uchat.h"
#include "../inc/ui.h"

t_application* app = NULL;
t_user* user = NULL;

int main(int argc, char const *argv[]) {
    if (false) { // if unused par
        argc = 0;
        argv = NULL;
    }
    app = mx_load_ui(&argc, (char***)&argv);

//sleep(1);
write(1, " user create \n", 15);
    if ( true ) { // test case 1
        user = (t_user*)malloc( sizeof(t_user*) );
        user->u_id = 2;
        user->u_name = "User 2";
        user->u_profile_image = NULL;
        user->u_bio = "user \n2 \nbio";
        user->u_online_date = 0;

        user->u_chatarr_size = 6;
        user->u_chatarr = (t_chat**)malloc( sizeof(t_chat*) * user->u_chatarr_size );;
        user->u_chatarr_count = 0;

        t_chat* c1 = (t_chat*)malloc( sizeof(t_chat*) );
        {
            c1->c_id = 11;
            c1->c_name = "Chat 1";
            c1->c_profile_image = NULL;
            c1->c_description = "chat 1 description";
            c1->ct_type = 1;
            c1->jt_type = 1;
            c1->cus_type = 1;

            c1->c_messagearr_size = 11;
            c1->c_messagearr = (t_message**)malloc( sizeof(t_message*) * c1->c_messagearr_size );;
            c1->c_messagearr_count = 0;
            {
                t_message* m1 = (t_message*)malloc( sizeof(t_message*) );
                m1->m_id = 21;
                m1->u_id = 1;
                m1->m_text = " chat 1 message 1";
                m1->m_is_edited = false;
                m1->m_date = time(NULL) - 1;
                m1->m_type = 1;
                m1->m_form = 1;
                m1->m_m_id = 0;
                c1->c_messagearr[c1->c_messagearr_count] = m1;
                c1->c_messagearr_count++;
                t_message* m2 = (t_message*)malloc( sizeof(t_message*) );
                m2->m_id = 22;
                m2->u_id = 2;
                m2->m_text = " chat 1 message 2";
                m2->m_is_edited = false;
                m2->m_date = time(NULL) - 2;
                m2->m_type = 1;
                m2->m_form = 1;
                m2->m_m_id = 0;
                c1->c_messagearr[c1->c_messagearr_count] = m2;
                c1->c_messagearr_count++;
                t_message* m3 = (t_message*)malloc( sizeof(t_message*) );
                m3->m_id = 23;
                m3->u_id = 1;
                m3->m_text = " chat 1 message 3";
                m3->m_is_edited = false;
                m3->m_date = time(NULL) - 3;
                m3->m_type = 1;
                m3->m_form = 1;
                m3->m_m_id = 0;
                c1->c_messagearr[c1->c_messagearr_count] = m3;
                c1->c_messagearr_count++;
            }
            user->u_chatarr[user->u_chatarr_count] = c1;
            user->u_chatarr_count++;
        }
        t_chat* c2 = (t_chat*)malloc( sizeof(t_chat*) );
        {
            c2->c_id = 12;
            c2->c_name = "Chat 2";
            c2->c_profile_image = NULL;
            c2->c_description = "chat 2 description";
            c2->ct_type = 2;
            c2->jt_type = 1;
            c2->cus_type = 2;

            c2->c_messagearr_size = 11;
            c2->c_messagearr = (t_message**)malloc( sizeof(t_message*) * c2->c_messagearr_size );;
            c2->c_messagearr_count = 0;
            {
                t_message* m1 = (t_message*)malloc( sizeof(t_message*) );
                m1->m_id = 31;
                m1->u_id = 1;
                m1->m_text = " chat 2 message 1";
                m1->m_is_edited = false;
                m1->m_date = time(NULL) - 1;
                m1->m_type = 1;
                m1->m_form = 1;
                m1->m_m_id = 0;
                c2->c_messagearr[c1->c_messagearr_count] = m1;
                c2->c_messagearr_count++;
                t_message* m2 = (t_message*)malloc( sizeof(t_message*) );
                m2->m_id = 32;
                m2->u_id = 3;
                m2->m_text = " chat 2 message 2";
                m2->m_is_edited = false;
                m2->m_date = time(NULL) - 3;
                m2->m_type = 1;
                m2->m_form = 1;
                m2->m_m_id = 0;
                c2->c_messagearr[c1->c_messagearr_count] = m2;
                c2->c_messagearr_count++;
                t_message* m3 = (t_message*)malloc( sizeof(t_message*) );
                m3->m_id = 33;
                m3->u_id = 2;
                m3->m_text = " chat 2 message 3";
                m3->m_is_edited = false;
                m3->m_date = time(NULL) - 4;
                m3->m_type = 1;
                m3->m_form = 1;
                m3->m_m_id = 0;
                c2->c_messagearr[c1->c_messagearr_count] = m3;
                c2->c_messagearr_count++;
                t_message* m4 = (t_message*)malloc( sizeof(t_message*) );
                m4->m_id = 34;
                m4->u_id = 1;
                m4->m_text = " chat 2 message 4";
                m4->m_is_edited = false;
                m4->m_date = time(NULL) - 2;
                m4->m_type = 1;
                m4->m_form = 1;
                m4->m_m_id = 0;
                c2->c_messagearr[c1->c_messagearr_count] = m4;
                c2->c_messagearr_count++;
            }
            user->u_chatarr[user->u_chatarr_count] = c2;
            user->u_chatarr_count++;
        }
        t_chat* c3 = (t_chat*)malloc( sizeof(t_chat*) );
        {
            c3->c_id = 13;
            c3->c_name = "Chat 3";
            c3->c_profile_image = NULL;
            c3->c_description = "chat 2 description";
            c3->ct_type = 2;
            c3->jt_type = 1;
            c3->cus_type = 2;

            c3->c_messagearr_size = 11;
            c3->c_messagearr = (t_message**)malloc( sizeof(t_message*) * user->u_chatarr_size );;
            c3->c_messagearr_count = 0;
            {

            }
            user->u_chatarr[user->u_chatarr_count] = c3;
            user->u_chatarr_count++;
        }
    }
    else if ( false ) { // test case 2

    }
    else { // test db request 

    }
    /*t_chat* c1 = (t_chat*)malloc( sizeof(t_chat*) );
    c1->c_name = "Chat 1";
    t_chat* c2 = (t_chat*)malloc( sizeof(t_chat*) );
    c2->c_name = "Chat 2";
    t_chat* c3 = (t_chat*)malloc( sizeof(t_chat*) );
    c3->c_name = "Chat 3";*/

write(1, " chat add \n", 12);

    /*mx_add_chat( user->u_chatarr[0], 1);
    mx_add_chat( user->u_chatarr[1], 2);
    mx_add_chat( user->u_chatarr[2], 3);*/
//sleep(1);

    //mx_del_chat( , 1);


write(1, " main show\n", 12);
    gtk_widget_show_all( GTK_WIDGET(app->window) );
    //gtk_widget_show( GTK_WIDGET(app->window) );
write(1, " 1 ", 4);

    gtk_widget_hide(app->chats_list_page->profile_overlay->overlay_background); // chat list overlay (profile)
write(1, " 2 ", 4);
    gtk_widget_hide(app->chats_list_page->profile_overlay->overlay_main); // chat list overlay (profile)
write(1, " 3 ", 4);

    gtk_widget_hide(app->chats_list_page->add_chat_overlay->overlay_background); // chat list overlay (add chat)
write(1, " 4 ", 4);
    gtk_widget_hide(app->chats_list_page->add_chat_overlay->overlay_main); // chat list overlay (add chat)
write(1, " 5 ", 4);

    gtk_widget_hide(app->chats_list_page->search_scroller); // chat list search overlay
write(1, " 6 ", 4);

    gtk_widget_hide(app->chat_page->profile_overlay->overlay_background); // chat overlay (profile)
write(1, " 7 ", 4);
    gtk_widget_hide(app->chat_page->profile_overlay->overlay_main); // chat overlay (profile)
write(1, " main hide\n", 12);

    // timeout / idge
            /*gdk_threads_add_idle();
            gdk_threads_add_timeout();
            gdk_threads_add_timeout_full();*/
    gtk_main();

    return 0;
}


