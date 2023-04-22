#include "../inc/client.h"


//make user registration
void registration(int client_socket) {
    //test registration request
    struct json_object* json_obj1 = json_object_new_object();
       json_object_object_add(json_obj1, "method", json_object_new_string("registration"));
       json_object_object_add(json_obj1, "login", json_object_new_string("kir12"));
       json_object_object_add(json_obj1, "name", json_object_new_string("Kirill"));
       json_object_object_add(json_obj1, "password", json_object_new_string("parol13"));       // Send JSON object to server
       if (send_json_object(client_socket, json_obj1) == -1) {
           exit(EXIT_FAILURE);
       }
    //receive response
    struct json_object* json_received_obj;
    if (receive_json_object(client_socket, &json_received_obj) == -1) {
        fprintf(stderr, "Failed to receive JSON message from server\n");
        exit(EXIT_FAILURE);
    }
    char *buffer = (char*)json_object_to_json_string(json_received_obj);
    parse_message(buffer); //func from json_handle.c file
    json_object_put(json_received_obj);
    json_object_put(json_obj1);

}

void login(int client_socket) {
    // sent login request on the server
    struct json_object* json_obj = json_object_new_object();
       json_object_object_add(json_obj, "method", json_object_new_string("login"));
       json_object_object_add(json_obj, "username", json_object_new_string("kir12"));
       json_object_object_add(json_obj, "password", json_object_new_string("parol13"));

       // Send JSON object to server
       if (send_json_object(client_socket, json_obj) == -1) {
           exit(EXIT_FAILURE);
       }
    struct json_object* json_received_obj;
    if (receive_json_object(client_socket, &json_received_obj) == -1) {
        fprintf(stderr, "Failed to receive JSON message from server\n");
        exit(EXIT_FAILURE);
    }
    char *buffer = (char*)json_object_to_json_string(json_received_obj);
    parse_message(buffer);
    json_object_put(json_obj);
    json_object_put(json_received_obj);
}

//initialize user on the server after successful login
void init_user(int client_socket) {
    struct json_object* json_obj = json_object_new_object();
       json_object_object_add(json_obj, "method", json_object_new_string("init_user"));
       json_object_object_add(json_obj, "login", json_object_new_string("kir12"));
    if (send_json_object(client_socket, json_obj) == -1) {
        exit(EXIT_FAILURE);
    }
    struct json_object* json_received_obj;
    if (receive_json_object(client_socket, &json_received_obj) == -1) {
        fprintf(stderr, "Failed to receive JSON message from server\n");
        exit(EXIT_FAILURE);
    }
    char *buffer = (char*)json_object_to_json_string(json_received_obj);
    parse_message(buffer);
    json_object_put(json_obj);
    json_object_put(json_received_obj);
}
