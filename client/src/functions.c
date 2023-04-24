#include "../inc/client.h"

// TODO: Don't forget about json_object_put() for free() memory!!

// Login logic
int make_login(int client_socket) {
    //send json request
    if (send_json_object(client_socket, client_request_login("TestLogin1", "qwerty123")) == -1) {
        //exit(EXIT_FAILURE);
        return -1;
    }

    //receive response from server
    struct json_object *json_received;
    if (receive_json_object(client_socket, json_received) == -1) {
        fprintf(stderr, "Failed to receive JSON message from server\n");
        //exit(EXIT_FAILURE);
        return -2;
    }

    char *buffer = (char *)json_object_to_json_string(json_received);
    if (strcmp(get_method(json_object_to_json_string(json_received)), "login") == 0) {
        client_parse_login(buffer);
    }

    printf("Parsing: 'login' method is parsed SUCCESSFUL.\n");
    return 0;
}

// Registration logic 
int make_registration(int client_socket) {
    //send json request
    if (send_json_object(client_socket, client_request_registration("TestLogin1", "Antonio", "qwerty123")) == -1) {
        //exit(EXIT_FAILURE);
        return -1;
    }

    //receive response from server
    struct json_object *json_received;
    if (receive_json_object(client_socket, &json_received) == -1) {
        fprintf(stderr, "Failed to receive JSON message from server\n");
        //exit(EXIT_FAILURE);
        return -2;
    }

    char *buffer = (char *)json_object_to_json_string(json_received);

    //parse
    if (strcmp(get_method(json_object_to_json_string(json_received)), "registration") == 0) {
        client_parse_registration(buffer); 
    }
    
    printf("Parsing: 'registration' method is parsed SUCCESSFUL.\n");
    return 0;
}

// User_init logic
int make_user_init(int client_socket) {
    //send json request
    if (send_json_object(client_socket, client_request_user_init("TestLogin1")) == -1) {
        //exit(EXIT_FAILURE);
        return -1;
    }

    //receive response from server
    struct json_object *json_received;
    if (receive_json_object(client_socket, &json_received) == -1) {
        fprintf(stderr, "Failed to receive JSON message from server\n");
        //exit(EXIT_FAILURE);
        return -2;
    }

    char *buffer = (char *)json_object_to_json_string(json_received);

    //parse
    if (strcmp(get_method(json_object_to_json_string(json_received)), "user_init") == 0) {
        client_parse_user_init(buffer); 
    }
    
    printf("Parsing: 'user_init' method is parsed SUCCESSFUL.\n");
    return 0;
}

// Sending message
int make_send_common_message(int client_socket){
    int message_type = 1; // text message (?)
    char *message = "message for testing. 142134588 WMWMWMW AAAOAOAOAO.";

    if (send_json_object(client_socket, client_request_message(message_type, current_user.user_id, 1 /*chat.c_id*/, message, 1)) == -1) {
        //exit(EXIT_FAILURE);
        return -1;
    }

    //receive response from server
    struct json_object *json_received;
    if (receive_json_object(client_socket, &json_received) == -1) {
        fprintf(stderr, "Failed to receive JSON message from server\n");
        //exit(EXIT_FAILURE);
        return -2;
    }

    char *buffer = (char *)json_object_to_json_string(json_received);

    //parse
    if (strcmp(get_method(json_object_to_json_string(json_received)), "message") == 0) {
        client_parse_message(buffer); 
    }

    return 0;

    /*
    int message_type = 1;
    char *message = "message for testing. 142134588 WMWMWMW AAAOAOAOAO.";
    struct json_object* json_obj = json_object_new_object();
    json_object_object_add(json_obj, "method", json_object_new_string("message"));
    json_object_object_add(json_obj, "message_type", json_object_new_int(message_type));
    json_object_object_add(json_obj, "user_id", json_object_new_int(current_user.user_id));
    json_object_object_add(json_obj, "chat_id", json_object_new_int(1)); //we need to throw here chat id, that we have saved from chat_init response
    json_object_object_add(json_obj, "message_text", json_object_new_string(message));
    json_object_object_add(json_obj, "message_form", json_object_new_int(1)); //1 for common
    
    // Send JSON object to server
    if (send_json_object(client_socket, json_obj) == -1) {
        exit(EXIT_FAILURE);
    }
    json_object_put(json_obj);
    */
}

