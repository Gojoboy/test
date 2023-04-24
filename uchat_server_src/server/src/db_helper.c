#include "../inc/server.h"

static int callback(void *data, int argc, char **argv, char **azColName){
    int *user_id = data;
    if (argc > 0) {
        *user_id = atoi(argv[0]);
    }
    return 0;
}

int get_user_id_from_db(char *login) {
    sqlite3 *db;
    char *err_msg = 0;
    int rc;
    int user_id = -1;

    rc = sqlite3_open("src/uchatdb.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }

    char sql[100];
    sprintf(sql, "SELECT u_id FROM User WHERE u_login='%s'", login);

    rc = sqlite3_exec(db, sql, callback, &user_id, &err_msg);

    if (rc != SQLITE_OK ) {
        fprintf(stderr, "Failed to select user: %s\n", sqlite3_errmsg(db));
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return -1;
    } else if (user_id == -1) {
        printf("No user found with login '%s'\n", login);
    }

    sqlite3_close(db);
    return user_id;
}

int delete_message_from_db(int message_id) {
    sqlite3 *db;
    int rc = sqlite3_open("src/uchatdb.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error opening database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }

    
    sqlite3_stmt *stmt;
    char *sql = "DELETE FROM Messages WHERE m_id = ?";
    rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error preparing statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return -1;
    }
    sqlite3_bind_int(stmt, 1, message_id);


    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error deleting message: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return -1;
    }

    // Cleanup
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}

