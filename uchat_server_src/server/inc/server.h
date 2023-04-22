#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <json-c/json.h>
#include <signal.h>
#include <netinet/in.h>
#include <sqlite3.h>

#define LIST_SIZE 100
//structs

struct list_node {
    int user_id;
    int socket_fd;
    struct list_node *next;
};


//list
int list_function(int user_id);
void add_to_list(int user_id, int socket_fd);
void remove_from_list(int user_id);
int get_socket_fd_from_list(int user_id);
//
void sigint_handler(int sig);
void init_user(int socket_fd, json_object *json_received_obj);
void init_chat(int socket_fd, json_object *json_received_obj);
void private_chat(int socket_fd, json_object *json_received_obj);
void group_chat(int socket_fd, json_object *json_received_obj);
void *client_handler(void *arg);
void message_handler(int client_socket, json_object *json_received_obj);
void broadcast_connection(struct json_object *json_received_obj, int sender_socket_fd, struct json_object *json_message);

// errors
void login_error(int client_socket, int mtd);
void password_error(int client_socket, int mtd);
void server_error(int client_socket);
void unknown_method_error(int client_socket);
void plain_error(int client_socket);
//db
int get_user_id_from_db(char *login);
//time
char* format_time(long int timestamp);
long int get_current_time();
