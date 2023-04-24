#include "../inc/client.h"

//                          REQUESTS

// TODO: Don't forget about json_object_put() for free() memory!!

// Creating request 'login' 
// return - 'request' in string format
char *client_request_login(char *login, char *password) {
    json_object *request = json_object_new_object();
    json_object_object_add(request, "method", json_object_new_string("login"));
    json_object_object_add(request, "username", json_object_new_string(login));
    json_object_object_add(request, "password", json_object_new_string(password));

    return strdup(json_object_to_json_string(request));
}

// Creating request 'registration'
// return - 'request' in string format
char *client_request_registration(char *login, char *username, char *password) {
    json_object *request = json_object_new_object();
    json_object_object_add(request, "method", json_object_new_string("registration"));
    json_object_object_add(request, "login", json_object_new_string(login));
    json_object_object_add(request, "username", json_object_new_string(username));
    json_object_object_add(request, "password", json_object_new_string(password));

    return strdup(json_object_to_json_string(request));
}

// Creating request 'user_init'
// return - 'request' in string format
char *client_request_user_init(char *login) {
    json_object *request = json_object_new_object();
    json_object_object_add(request, "method", json_object_new_string("user_init"));
    json_object_object_add(request, "login", json_object_new_string(login));

    return strdup(json_object_to_json_string(request));
}

// Creating request 'chat_init'
// return - 'request' in string format
char *client_request_chat_init(int chat_type, char *user_id1, char *user_id2) {
    json_object *request = json_object_new_object();
    json_object_object_add(request, "method", json_object_new_string("chat_init"));
    json_object_object_add(request, "chat_type", json_object_new_int(chat_type));
    json_object_object_add(request, "user_id1", json_object_new_string(user_id1));
    json_object_object_add(request, "user_id2", json_object_new_string(user_id2));

    return strdup(json_object_to_json_string(request));
}

// Creating request 'message'
// return - 'request' in string format
char *client_request_message(int message_type, char *user_id, char *chat_id, char *message_text, int message_form) {
    json_object *request = json_object_new_object();
    json_object_object_add(request, "method", json_object_new_string("message"));
    json_object_object_add(request, "message_type", json_object_new_int(message_type));
    json_object_object_add(request, "user_id", json_object_new_string(user_id));
    json_object_object_add(request, "chat_id", json_object_new_string(chat_id));
    json_object_object_add(request, "message_text", json_object_new_string(message_text));
    json_object_object_add(request, "message_form", json_object_new_int(message_form));

    return strdup(json_object_to_json_string(request));
}

// TODO: 1) client_request_del_chat;        done (?)
//       2) client_request_load_chat;       in proccess
//       2) client_request_del_message;     done (?)
//       3) client_request_edit_message;    done (?)
//       4) client_request_load_profile;    in proccess
//       5) client_request_***

// Creating request 'edit_message'
// return - 'request' in string format
char *client_request_edit_message(int chat_id, int message_id, char *edited_text) { //maybe need to change params??
    json_object *request = json_object_new_object();
    json_object_object_add(request, "method", json_object_new_string("edit_message"));
    json_object_object_add(request, "chat_id", json_object_new_int(chat_id));
    json_object_object_add(request, "message_id", json_object_new_int(message_id));
    json_object_object_add(request, "edited_text", json_object_new_string(edited_text));

    return strdup(json_object_to_json_string(request));
}

// Creating request 'delete_message'
// return - 'request' in string format
char *client_request_del_message(int chat_id, int message_id) {
    json_object *request = json_object_new_object();
    json_object_object_add(request, "method", json_object_new_string("delete_message"));
    json_object_object_add(request, "chat_id", json_object_new_int(chat_id));
    json_object_object_add(request, "message_id", json_object_new_int(message_id));
    //json_object_object_add(request, "new_message", json_object_new_string(new_message));  //need this field?

    return strdup(json_object_to_json_string(request));
}

// Creating request 'load_chat'
// return - 'request' in string format
char *client_request_load_chat(int chat_id) {
    json_object *request = json_object_new_object();
    json_object_object_add(request, "method", json_object_new_string("load_chat"));
    json_object_object_add(request, "chat_id", json_object_new_int(chat_id));

    //maybe need more fields

    return strdup(json_object_to_json_string(request));
}

// Creating request 'chat_delete'
// return - 'request' in string format
char *client_request_del_chat(int chat_id) {
    json_object *request = json_object_new_object();
    json_object_object_add(request, "method", json_object_new_string("chat_delete"));
    json_object_object_add(request, "chat_id", json_obkect_new_int(chat_id));

    return strdup(json_object_to_json_string(request));
}

// Creating request 'del_chat'
// return - 'request' in string format
char *client_request_load_profile(int user_id) {
    json_object *request = json_object_new_object();
    json_object_object_add(request, "method", json_object_new_string("del_chat"));
    json_object_object_add(request, "user_id", json_object_new_int(user_id));
    
    // maybe need more fields (?)
    
    return strdup(json_object_to_json_string(request));
}

// To be continued..

