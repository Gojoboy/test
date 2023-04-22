#include "../inc/client.h"

void init_private_chat(int client_socket) {
    int chat_type = 1;
    struct json_object* json_obj = json_object_new_object();
       json_object_object_add(json_obj, "method", json_object_new_string("chat_init"));
       json_object_object_add(json_obj, "chat_type", json_object_new_int(chat_type));
       json_object_object_add(json_obj, "user1_id", json_object_new_int(current_user.user_id));
    json_object_object_add(json_obj, "user2_id", json_object_new_int(3));//for test take second user id 3

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
