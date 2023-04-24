#include "../inc/client.h"

// TODO: Don't forget about json_object_put() for free() memory!!

//Check simple validation of password.
// return 0 if correct!
// return -1 if incorrect lenth of password
// return -2 if password didn't contain ALPHABET characters
// return -3 if password didn't contain DIGITS characters
// return -4 if password didn't contain LOWERCASE characters
// return -5 if password didn't contain UPPERCASE characters
int check_password(char *password) {
    if (strlen(password) < 16 && strlen(password) > 24) {
        perror("Error: length of password must be > 16 but < 24 characters!");
        return -1;
    }

    int alpa_counter = 0;
    int dig_counter = 0;
    int lower_counter = 0;
    int upper_counter = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isalpha(password[i])) {
            alpa_counter++;
        }

        if (isdigit(password[i])) {
            dig_counter++;
        }

        if (isupper(password[i])) {
            upper_counter++;
        }

        if (islower(password[i])) {
            lower_counter++;
        }
    }

    if (alpa_counter < 1) {
        perror("Error: password must contain > 1 ALPHABETIC character!");
        return -2;
    }

    if (dig_counter < 1) {
        perror("Error: password must contain > 1 DIGIT character!");
        return -3;
    }

    if (lower_counter < 1) {
        perror("Error: password must contain > 1 LOWERCASE character!");
        return -4;
    }

    if (upper_counter < 1) {
        perror("Error: password must contain > 1 UPPERCASE character!");
        return -5;
    }

    return 0;
}

//Check simple validation of login.
// return 0 if correct!
// return -1 if incorrect length of login
// return -2 if login didn't contain alphabet, digits, '_' and '-' symbols
int check_login(char *login) {
    if (strlen(login) < 2) {
        perror("Error: the length of login must be longer than 2 symbols!");
        return -1;
    }

    for (int i = 0; i < strlen(login); i++) {
        if (isdigit(login[i] || isalpha(login[i])) || login[i] == '_' || login[i] == '-') {
            continue;
        }
        else {
            perror("Error: login must contain ALPHABETIC, DIGITS, '_' and '-' only!");
            return -2;
        }
    }

    return 0;
}

// Getting method from received buffer of json.
// return - 'method' in string
char *get_method(char *buffer) {
    struct json_object *parsed_json;
    enum json_tokener_error err_json = json_tokener_success;
    parsed_json = json_tokener_parse_verbose(buffer, &err_json);

    enum json_type jtype = json_object_get_type(parsed_json);
    if (jtype != json_type_object) {
        fprintf(stderr, "Expected JSON object, received %s\n", json_type_to_name(jtype));
        return "-1";
    }

    //Method
    struct json_object *method;
    if (!json_object_object_get_ex(parsed_json, "method", &method)) {
        fprintf(stderr, "Error: missing 'method' field in JSON object.\n");
        return "-2";
    }

    if (json_object_get_type(method) != json_type_string) {
        fprintf(stderr, "Error: expected 'method' field to be a string\n");
        return "-3";
    }

    printf("Received message with method: %s\n", json_object_get_string(method));
    return strdup(method);
}

// To be continued..

