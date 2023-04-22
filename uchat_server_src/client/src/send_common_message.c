#include "../inc/client.h"

void send_common_message(int client_socket){
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
