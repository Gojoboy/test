#include "../inc/server.h"

void *client_handler(void *arg) {
    printf("\n CLIENT HANDLER \n");
    int client_socket = *(int*)arg;
    char buffer[4096];
    memset(buffer, 0, sizeof(buffer));
    int mtd = 0;
    
    while(1) {
        int bytes_received = read(client_socket, buffer, sizeof(buffer));
        if (bytes_received <= 0) {
            perror("Error receiving message from client");
            break;
        }else if (bytes_received == 0) {
            printf("Connection closed by client\n");
            close(client_socket);
        }

        printf("Received message from client (raw): %s\n", buffer);
        
        // Parse JSON message
        json_object *json_received_obj = json_tokener_parse(buffer);
        json_object *method_obj;
        json_object_object_get_ex(json_received_obj, "method", &method_obj);
        char *method = (char*)json_object_get_string(method_obj);
        
        //Add user to users list
        if (strcmp(method, "delete_message") == 0) {
            delete_message(client_socket, json_received_obj);
        }
        if (strcmp(method, "edit_message") == 0) {
            edit_message(client_socket, json_received_obj);
        }
        //Delete chat
        if (strcmp(method, "chat_delete") == 0) {
            chat_delete(client_socket, json_received_obj);
        }
        //Init chat
        if (strcmp(method, "chat_init") == 0) {
            init_chat(client_socket, json_received_obj);
        }
        // Handle login method
        if (strcmp(json_object_get_string(method_obj), "login") == 0) {
            // Check if username and password fields exist
            int logged = 0;
            json_object *username_obj, *password_obj;
            if (json_object_object_get_ex(json_received_obj, "username", &username_obj) && json_object_object_get_ex(json_received_obj, "password", &password_obj)) {
                const char *username = json_object_get_string(username_obj);
                const char *password = json_object_get_string(password_obj);
                
                sqlite3 *db;
                sqlite3_stmt *stmt;
                const char *query = "SELECT * FROM User WHERE u_login = ?;";
                int rc = sqlite3_open("src/uchatdb.db", &db);
                rc = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
                rc = sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
                if (rc != SQLITE_OK) {
                    server_error(client_socket);
                }
                rc = sqlite3_step(stmt);
                if (rc == SQLITE_ROW) {
                    // The user exists in the database
                    printf("\n Check users login (inside loop).");
                    const char *stored_password = (const char *) sqlite3_column_text(stmt, 2);
                    printf("\n Stored password: %s .", stored_password);
                    if (strcmp(stored_password, password) == 0) {
                        // The password is correct
                        json_object *response = json_object_new_object();
                        json_object_object_add(response, "method", json_object_new_string("login"));
                        json_object_object_add(response, "status", json_object_new_string("OK"));
                        logged = 1;
                        printf("\n Login success.");
                        const char *response_str = json_object_to_json_string(response);
                        int send_status = send(client_socket, response_str, strlen(response_str), 0);
                        if (send_status == -1) {
                            printf("\n Error sending response to client (Login success response).");
                        } else if (send_status < strlen(response_str)) {
                            printf("Warning: not all bytes sent\n");
                        } else {
                            printf("\n Login success response is successfuly sent.");
                        }
                    } else if(logged == 0){
                        // The password is incorrect
                        password_error(client_socket, mtd);
                    }
                } else if (logged == 0){
                    // The user does not exist in the database
                    login_error(client_socket, mtd);
                }
                sqlite3_finalize(stmt);
                sqlite3_close(db);
            }
        }

        //Handle registration method
        if (strcmp(json_object_get_string(method_obj), "registration") == 0) {
          json_object *login_obj = json_object_object_get(json_received_obj, "login");
          json_object *name_obj = json_object_object_get(json_received_obj, "name");
          json_object *password_obj = json_object_object_get(json_received_obj, "password");
        
          const char *login = json_object_get_string(login_obj);
          const char *name = json_object_get_string(name_obj);
          const char *password = json_object_get_string(password_obj);
          mtd = 1;
          bool err = false;
          bool already_exist = false;
          // Open the database connection
          sqlite3 *db;
          int rc = sqlite3_open("src/uchatdb.db", &db);
          if (rc != SQLITE_OK) {
              // Error opening the database
              server_error(client_socket);
              err = true;
          }
          sqlite3_stmt *stmt;
          char *sql = "SELECT u_login FROM User WHERE u_login = ?";
          rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
          if (rc != SQLITE_OK) {
            // Error preparing the SQL statement
            server_error(client_socket);
            sqlite3_close(db);
              err = true;
          }
          rc = sqlite3_bind_text(stmt, 1, login, -1, SQLITE_TRANSIENT);
          if (rc != SQLITE_OK) {
            server_error(client_socket);
            sqlite3_finalize(stmt);
            sqlite3_close(db);
              err = true;
          }
          rc = sqlite3_step(stmt);
          if (rc == SQLITE_ROW) {
            // User already exists in the database
            err = true;
            already_exist = true;
          }
          sqlite3_finalize(stmt);


          // Prepare the SQL statement to insert the new user
            if (!already_exist) {
                sql = "INSERT INTO User (u_login, u_name, u_password) VALUES (?, ?, ?)";
                err = false;
                rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
                if (rc != SQLITE_OK) {
                    // Error preparing the SQL statement
                    server_error(client_socket);
                    sqlite3_close(db);
                    err = true;
                }
                
                // Bind the values to the parameters in the SQL statement
                rc = sqlite3_bind_text(stmt, 1, login, -1, SQLITE_TRANSIENT);
                if (rc != SQLITE_OK) {
                    server_error(client_socket);
                    sqlite3_finalize(stmt);
                    sqlite3_close(db);
                    err = true;
                }
                rc = sqlite3_bind_text(stmt, 2, name, -1, SQLITE_TRANSIENT);
                if (rc != SQLITE_OK) {
                    err = true;
                    server_error(client_socket);
                    sqlite3_finalize(stmt);
                    sqlite3_close(db);
                }
                rc = sqlite3_bind_text(stmt, 3, password, -1, SQLITE_TRANSIENT);
                if (rc != SQLITE_OK) {
                    err = true;
                    server_error(client_socket);
                    sqlite3_finalize(stmt);
                    sqlite3_close(db);
                }
                
                // Execute the SQL statement
                rc = sqlite3_step(stmt);
                if (rc != SQLITE_DONE) {
                    server_error(client_socket);
                    sqlite3_finalize(stmt);
                    sqlite3_close(db);
                    err = true;
                }
                
                sqlite3_finalize(stmt);
                sqlite3_close(db);
                if(!err) {
                    json_object *response = json_object_new_object();
                    json_object_object_add(response, "method", json_object_new_string("registration"));
                    json_object_object_add(response, "status", json_object_new_string("OK"));
                    const char *response_str = json_object_to_json_string(response);
                    int send_status = send(client_socket, response_str, strlen(response_str), 0);
                    if (send_status == -1) {
                        printf("\n Error sending response to client (Register success response).");
                    } else if (send_status < strlen(response_str)) {
                        printf("Warning: not all bytes sent (register) \n");
                    } else {
                        printf("\n Registration success response is successfuly sent.");
                    }
                }
            } else if (err){
                login_error(client_socket, mtd);
            }
          
        }
        //Handle message method (text/file/img...)
        if (strcmp(json_object_get_string(method_obj), "message") == 0) {
            message_handler(client_socket, json_received_obj);
        }
        json_object_put(json_received_obj);
        memset(buffer, 0, sizeof(buffer));
    }

    close(client_socket);
    pthread_detach(pthread_self());
    return NULL;
}
