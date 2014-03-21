#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void print_process_arg_list(pid_t pid)
{
    int fd;
    char filename[24];
    char arg_list[1024];
    size_t length;
    char* next_arg;

    snprintf(filename, sizeof(filename), "/proc/%d/cmdline", (int)pid);

    fd = open(filename, O_RDONLY);

    length = read(fd, arg_list, sizeof(arg_list));

    close(fd);

    arg_list[length] = '\0';

    next_arg = arg_list;

    while(next_arg < arg_list + length) {
        printf("%s\n", next_arg);

        next_arg += strlen(next_arg) + 1;
    }
}

int main(int argc, char* argv[])
{
    pid_t pid = (pid_t)atoi(argv[1]);
    print_process_arg_list(pid);

    return 0;
}
