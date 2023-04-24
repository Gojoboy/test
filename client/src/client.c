#include "../inc/client.h"

UserInfo current_user = {0, NULL};
bool logged_in = false;

int main(int argc, char *argv[]) {
    if (argc != 3) {
		printf("Usage: ./uchat_client <ip> <port>\n");
		exit(EXIT_FAILURE);
	}

    char *ip = argv[1];       //ip = 192.168.0.106 - Roman
    char *port = argv[2];     //port = 8083 

    int client_socket;
    struct sockaddr_in server_addr;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error: failed creating socket.");
        exit(EXIT_FAILURE);
    }
    else {
        printf("Socket created SUCCESSFUL.\n");
    }

    printf("Setting connection...\n");
    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);    //192.168.0.106 - Roman
    server_addr.sin_port = htons(atoi(port));       //port = 8083
    
    printf("Connecting to <IP: %s> <PORT: %s>\n", ip, port);

    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        printf("Connection with server is SUCCESSFUL.\n");

        // (functions.c)
        // 1. Registration
        // 2. Login
        // 3. User_init

        if (make_registration(client_socket) == 0) {
            if (make_login(client_socket) == 0) {
                make_user_init(client_socket);
            }
        }
    }

    /*
    int reconection_counter = 0;
    // TODO: Auto-reconnecting
    while (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        // Connect to server
        if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
            printf("Connection with server is SUCCESSFUL.\n");

            // (functions.c)
            // 1. Registration
            // 2. Login
            // 3. User_init

            if (make_registration(client_socket) == 0) {
                if (make_login(client_socket) == 0) {
                    make_user_init(client_socket);
                }
            }
            
        }

        printf("Error: failed connecting to server. Reconnecting...\n");
        reconection_counter++;
        sleep(1);

        if (reconection_counter > 10) {
            perror("Error: failed connection with server after 10 attempt");
            exit(EXIT_FAILURE);
        }
    }
    */
    
    close(client_socket);
    return 0;
}

