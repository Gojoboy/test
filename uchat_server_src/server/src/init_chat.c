#include "../inc/server.h"

void init_chat(int socket_fd, json_object *json_received_obj) {
    struct json_object *chat_type_obj;
    json_object_object_get_ex(json_received_obj, "chat_type", &chat_type_obj);
    int chat_type = json_object_get_int(chat_type_obj);
    if (chat_type == 1) {
        private_chat(socket_fd, json_received_obj);
    }
    else if (chat_type == 2) {
        group_chat(socket_fd, json_received_obj);
    }
}

void private_chat(int socket_fd, json_object *json_received_obj) {
    // Extract necessary data from the received JSON object
    struct json_object *user1_id_obj, *user2_id_obj;
    json_object_object_get_ex(json_received_obj, "user1_id", &user1_id_obj);
    json_object_object_get_ex(json_received_obj, "user2_id", &user2_id_obj);
    int user1_id = json_object_get_int(user1_id_obj);
    int user2_id = json_object_get_int(user2_id_obj);
    
    // Insert chat into the database
    int chat_type = 1; // Private chat
    int join_type = 2; // Always 2 for private chats
    sqlite3 *db;
    int rc = sqlite3_open("src/uchatdb.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }
    char sql[1024];
    snprintf(sql, sizeof(sql), "INSERT INTO Chat (c_name, jt_id, ct_id) VALUES ('', %d, %d);", join_type, chat_type);
    char *err_msg;
    rc = sqlite3_exec(db, sql, NULL, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error inserting chat: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return;
    }
    printf("chat inserted");
    long long chat_id = sqlite3_last_insert_rowid(db);
    
    // Insert users into the ChatUser table
    snprintf(sql, sizeof(sql), "INSERT INTO ChatUser (u_id, c_id, cus_id) VALUES (%d, %lld, 3);", user1_id, chat_id);
    rc = sqlite3_exec(db, sql, NULL, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error inserting user1 into ChatUser: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return;
    }
    snprintf(sql, sizeof(sql), "INSERT INTO ChatUser (u_id, c_id, cus_id) VALUES (%d, %lld, 3);", user2_id, chat_id);
    rc = sqlite3_exec(db, sql, NULL, 0, &err_msg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error inserting user2 into ChatUser: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return;
    }
    
    // Construct the JSON chat object
    struct json_object *json_chat_obj = json_object_new_object();
    json_object_object_add(json_chat_obj, "method", json_object_new_string("init_chat"));
    json_object_object_add(json_chat_obj, "chat_type", json_object_new_int(chat_type));
    json_object_object_add(json_chat_obj, "chat_id", json_object_new_int((int)chat_id));
    json_object_object_add(json_chat_obj, "user1_id", json_object_new_int(user1_id));
    json_object_object_add(json_chat_obj, "user2_id", json_object_new_int(user2_id));
    json_object_object_add(json_chat_obj, "join_type", json_object_new_int(join_type));
    
    broadcast_connection(json_received_obj, socket_fd, json_chat_obj);
}

void group_chat(int socket_fd, json_object *json_received_obj) {
    
}
