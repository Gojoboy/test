#include "../inc/client.h"

//                          PARSE RESPONSES

// TODO: Don't forget about json_object_put() for free() memory!!

// Parse response 'login'
void client_parse_login(char *buffer) {
    struct json_object *parsed_json;
    enum json_tokener_error err_json = json_tokener_success;
    parsed_json = json_tokener_parse_verbose(buffer, &err_json);
    
    struct json_object *method;
    struct json_object *status;
    struct json_object *message;

    enum json_type jtype = json_object_get_type(parsed_json);
    if (jtype != json_type_object) {
        fprintf(stderr, "Expected JSON object, received %s\n", json_type_to_name(jtype));
        return;
    }

    //Status
    if (!json_object_object_get_ex(parsed_json, "status", &status)) {
        fprintf(stderr, "Error: missing 'status' field in JSON object.\n");
        return;
    }

    printf("Received login-confirmation status: %s \n", json_object_get_string(status));
    if (strcmp(json_object_get_string(status), "FAIL") == 0) {
        //Message
        if (!json_object_object_get_ex(parsed_json, "message", &message)) {
            fprintf(stderr, "Error: missing 'status' field in JSON object.\n");
            return;
        }

        printf("Received status-message: %s \n", json_object_get_string(message));
    }

    if(strcmp(json_object_get_string(status), "OK") == 0) {
        logged_in = true;
    }
}

// Parse response 'registration'
void client_parse_registration(char *buffer) {
    struct json_object *parsed_json;
    enum json_tokener_error err_json = json_tokener_success;
    parsed_json = json_tokener_parse_verbose(buffer, &err_json);

    struct json_object *method;
    struct json_object *status;
    struct json_object *message;

    enum json_type jtype = json_object_get_type(parsed_json);
    if (jtype != json_type_object) {
        fprintf(stderr, "Expected JSON object, received %s\n", json_type_to_name(jtype));
        return;
    }

    //Status
    if (!json_object_object_get_ex(parsed_json, "status", &status)) {
        fprintf(stderr, "Error: missing 'status' field in JSON object.\n");
        return;
    }

    printf("Received registration-confirmation status: %s \n", json_object_get_string(status));
    if (strcmp(json_object_get_string(status), "FAIL") == 0) {
        //Message
        if (!json_object_object_get_ex(parsed_json, "message", &message)) {
            fprintf(stderr, "Error: missing 'status' field in JSON object.\n");
            return;
        }

        printf("Received status-message: %s \n", json_object_get_string(message));
    }
}

// Parse response 'user_init'
// Client should save users 'login' and 'id'.
void client_parse_user_init(char *buffer) {
    struct json_object *parsed_json;
    enum json_tokener_error err_json = json_tokener_success;
    parsed_json = json_tokener_parse_verbose(buffer, &err_json);

    struct json_object *method;
    struct json_object *login;
    struct json_object *user_id;


    enum json_type jtype = json_object_get_type(parsed_json);
    if (jtype != json_type_object) {
        fprintf(stderr, "Expected JSON object, received %s\n", json_type_to_name(jtype));
        return;
    }

    //Login
    if (!json_object_object_get_ex(parsed_json, "login", &login)) {
        fprintf(stderr, "Error: missing 'login' field in JSON object.\n");
        return;
    }
    
    //User_id
    if (!json_object_object_get_ex(parsed_json, "user_id", &user_id)) {
        fprintf(stderr, "Error: missing 'user_id' field in JSON object.\n");
        return;
    }

    //Saving 'user_id' and 'login' to extern localUser (client.h)
    current_user.user_id = json_object_get_string(atoi(user_id));
    current_user.login = json_object_get_string(login);

    //
    printf("Parsing: user_id - '%i'\n", current_user.user_id);
    printf("Parsing: login - '%s'\n", current_user.login);
}

// TODO: Fix parsing for 'chat_init' and 'message'

// Parse response 'chat_init'
void client_parse_chat_init(char *buffer) {
    struct json_object *parsed_json;
    enum json_tokener_error err_json = json_tokener_success;
    parsed_json = json_tokener_parse_verbose(buffer, &err_json);

    struct json_object *chat_type;
    struct json_object *chat_id;
    struct json_object *user1_id;
    struct json_object *user2_id;
    struct json_object *join_type;

    enum json_type jtype = json_object_get_type(parsed_json);
    if (jtype != json_type_object) {
        fprintf(stderr, "Expected JSON object, received %s\n", json_type_to_name(jtype));
        return;
    }

    //Chat_type
    if (!json_object_object_get_ex(parsed_json, "chat_type", &chat_type)) {
        fprintf(stderr, "Error: missing 'chat_type' field in JSON object.\n");
        return;
    }
    
    //Chat_id
    if (!json_object_object_get_ex(parsed_json, "chat_id", &chat_id)) {
        fprintf(stderr, "Error: missing 'chat_id' field in JSON object.\n");
        return;
    }

    //User1_id
    if (!json_object_object_get_ex(parsed_json, "user1_id", &user1_id)) {
        fprintf(stderr, "Error: missing 'user1_id' field in JSON object.\n");
        return;
    }

    //User2_id
    if (!json_object_object_get_ex(parsed_json, "user2_id", &user2_id)) {
        fprintf(stderr, "Error: missing 'user2_id' field in JSON object.\n");
        return;
    }

    //Join_type
    if (!json_object_object_get_ex(parsed_json, "join_type", &join_type)) {
        fprintf(stderr, "Error: missing 'join_type' field in JSON object.\n");
        return;
    }

    //Fill struct 'chat' ?

}

// Parse response 'delete_chat'
void client_parse_chat_delete(char *buffer) {
    struct json_object *parsed_json;
    enum json_tokener_error err_json = json_tokener_success;
    parsed_json = json_tokener_parse_verbose(buffer, &err_json);

    struct json_object *chat_id;

    enum json_type jtype = json_object_get_type(parsed_json);
    if (jtype != json_type_object) {
        fprintf(stderr, "Expected JSON object, received %s\n", json_type_to_name(jtype));
        return;
    }

    //Chat_id
    if (!json_object_object_get_ex(parsed_json, "chat_id", &chat_id)) {
        fprintf(stderr, "Error: missing 'chat_id' field in JSON object.\n");
        return;
    }

    //free() data in struct
}

// Parse response 'message'
void client_parse_message(char *buffer) {
    struct json_object *parsed_json;
    enum json_tokener_error err_json = json_tokener_success;
    parsed_json = json_tokener_parse_verbose(buffer, &err_json);

    struct json_object *message_type;
    struct json_object *message_id;
    struct json_object *user_id;
    struct json_object *chat_id;
    struct json_object *message_text;
    struct json_object *message_form;
    struct json_object *message_date;
    struct json_object *is_edited;

    enum json_type jtype = json_object_get_type(parsed_json);
    if (jtype != json_type_object) {
        fprintf(stderr, "Expected JSON object, received %s\n", json_type_to_name(jtype));
        return;
    }

    //Message_type
    if (!json_object_object_get_ex(parsed_json, "message_type", &message_type)) {
        fprintf(stderr, "Error: missing 'message_type' field in JSON object.\n");
        return;
    }
    
    //Message_id
    if (!json_object_object_get_ex(parsed_json, "message_id", &message_id)) {
        fprintf(stderr, "Error: missing 'message_id' field in JSON object.\n");
        return;
    }

    //User_id
    if (!json_object_object_get_ex(parsed_json, "user_id", &user_id)) {
        fprintf(stderr, "Error: missing 'user_id' field in JSON object.\n");
        return;
    }

    //Chat_id
    if (!json_object_object_get_ex(parsed_json, "chat_id", &chat_id)) {
        fprintf(stderr, "Error: missing 'chat_id' field in JSON object.\n");
        return;
    }

    //Message_text
    if (!json_object_object_get_ex(parsed_json, "message_text", &message_text)) {
        fprintf(stderr, "Error: missing 'message_text' field in JSON object.\n");
        return;
    }

    //Message_form
    if (!json_object_object_get_ex(parsed_json, "message_form", &message_form)) {
        fprintf(stderr, "Error: missing 'message_form' field in JSON object.\n");
        return;
    }

    //Message_date
    if (!json_object_object_get_ex(parsed_json, "message_date", &message_date)) {
        fprintf(stderr, "Error: missing 'message_date' field in JSON object.\n");
        return;
    }

    //Is_edited
    if (!json_object_object_get_ex(parsed_json, "is_edited", &is_edited)) {
        fprintf(stderr, "Error: missing 'is_edited' field in JSON object.\n");
        return;
    }

    //Fill struct 'message' ?

}

// Parse response 'edit_message'
void client_parse_edit_message(char *buffer) {
    struct json_object *parsed_json;
    enum json_tokener_error err_json = json_tokener_success;
    parsed_json = json_tokener_parse_verbose(buffer, &err_json);

    struct json_object *chat_id;
    struct json_object *message_id;
    struct json_object *edited_text;
    struct json_object *is_edited;

    enum json_type jtype = json_object_get_type(parsed_json);
    if (jtype != json_type_object) {
        fprintf(stderr, "Expected JSON object, received %s\n", json_type_to_name(jtype));
        return;
    }

    //Chat_id
    if (!json_object_object_get_ex(parsed_json, "chat_id", &chat_id)) {
        fprintf(stderr, "Error: missing 'chat_id' field in JSON object.\n");
        return;
    }

    //Message_id
    if (!json_object_object_get_ex(parsed_json, "message_id", &message_id)) {
        fprintf(stderr, "Error: missing 'message_id' field in JSON object.\n");
        return;
    }

    //Edited_text
    if (!json_object_object_get_ex(parsed_json, "edited_text", &edited_text)) {
        fprintf(stderr, "Error: missing 'edited_text' field in JSON object.\n");
        return;
    }

    //Is_edited
    if (!json_object_object_get_ex(parsed_json, "is_edited", &is_edited)) {
        fprintf(stderr, "Error: missing 'is_edited' field in JSON object.\n");
        return;
    }

    //Fill struct (?)
}

// Parse response 'delete_message'
void client_parse_delete_message(char *buffer) {
    struct json_object *parsed_json;
    enum json_tokener_error err_json = json_tokener_success;
    parsed_json = json_tokener_parse_verbose(buffer, &err_json);

    struct json_object *chat_id;
    struct json_object *message_id;

    enum json_type jtype = json_object_get_type(parsed_json);
    if (jtype != json_type_object) {
        fprintf(stderr, "Expected JSON object, received %s\n", json_type_to_name(jtype));
        return;
    }

    //Chat_id
    if (!json_object_object_get_ex(parsed_json, "chat_id", &chat_id)) {
        fprintf(stderr, "Error: missing 'chat_id' field in JSON object.\n");
        return;
    }

    //Message_id
    if (!json_object_object_get_ex(parsed_json, "message_id", &message_id)) {
        fprintf(stderr, "Error: missing 'message_id' field in JSON object.\n");
        return;
    }

    //Fill struct (?)
    
}



// To be continued..

