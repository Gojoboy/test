#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <json-c/json.h>
#include <time.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

//Structs

// Message file
typedef struct s_message_file {
    int mf_id;
    void *mf_file;
    char *mf_name;
    int mf_size;
}               t_message_file;

// Messgae text
typedef struct s_message {
    int m_id;
    int u_id;
    char *m_text;
    int m_date;
    bool m_is_edited;

    int m_type;

    int m_form;
    int m_m_id; // reply?

    t_message_file **message_files;
    int count;
    int size;
}               t_message;

// Chat
typedef struct s_chat {
    int c_id;
    char *c_name;
    void *c_profile_image;
    char *c_description;

    int jt_type;
    int ct_type;
    int cus_type;

    t_message **messages;
    int count;
    int size;
}               t_chat;

// User
typedef struct s_user {
    int u_id;
    char *u_login;
    char *u_name;
    void *u_profile_image;
    char *u_bio;
    int u_online_date;

    t_chat **chats;
    int count;
    int size;
}               t_user;

//extern t_user localUser;
extern bool logged_in;

// temp UserInfo for testing
typedef struct {
    int user_id;
    char* login;
} UserInfo;

extern UserInfo current_user;

//Requests

char *client_request_login(char *login, char *password);
char *client_request_registration(char *login, char *username, char *password);
char *client_request_user_init(char *login);
char *client_request_chat_init(int chat_type, char *user_id1, char *user_id2);
char *client_request_message(int message_type, char *user_id, char *chat_id, char *message_text, int message_form);

// Parses

void client_parse_login(char *buffer);
void client_parse_registration(char *buffer);
void client_parse_user_init(char *buffer);
void client_parse_chat_init(char *buffer); // not done (need to fill struct 'chat'?)
void client_parse_message(char *buffer);   // not done (need to fill struct 'message'?)

//Cryptographys


//Handle client errors


//Reconnection


//Functions

int make_login(int client_socket);
int make_registration(int client_socket);
int make_user_init(int client_socket);

//Utils

int check_password(char *password);
int check_login(char *login);
char *get_method(char *buffer);

//JSON

//int send_json_object(int client_socket, struct json_object* json_obj);
int send_json_object(int client_socket, char *buffer);
int receive_json_object(int client_socket, struct json_object** json_obj);
//void parse_message(char* buffer);

