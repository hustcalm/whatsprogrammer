#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int server(int client_socket)
{
    while(1) {
        int length;
        char* text;

        if(read(client_socket, &length, sizeof(length) == 0))
                return 0;

        text = (char*)malloc(length);
        read(client_socket, text, length);
        printf("%s\n", text);

        free(text);
        text = NULL;

        if(!strcmp(text, "quit"))
            return 1;
    }
}

int main(int argc, char* const argv[])
{
    const char* const socket_name =  argv[1];
    int socket_fd;
    struct sockaddr_un name;
    int client_sent_quit_message;

    /* Create the socket */
    socket_fd = socket(PF_LOCAL, SOCK_STREAM, 0);
    name.sun_family = AF_LOCAL;
    strcpy(name.sun_path, socket_name);
    bind(socket_fd, &name, SUN_LEN(&name));

    listen(socket_fd, 5);

    do {
        struct sockaddr_un client_name;
        socklen_t client_name_len;
        int client_socket_fd;

        client_socket_fd = accept(socket_fd, &client_name, &client_name_len);

        client_sent_quit_message = server(client_socket_fd);

        close(client_socket_fd);
    }while(!client_sent_quit_message);

    close(socket_fd);
    unlink(socket_name);

    return 0;
}
