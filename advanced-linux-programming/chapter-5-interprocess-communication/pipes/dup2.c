#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int fds[2];
    pid_t pid;

    pipe(fds);

    pid = fork();

    if(pid == (pid_t)0) {

        close(fds[1]);

        dup2(fds[0], STDIN_FILENO);

        execlp("sort", "sort", 0);
    }
    else {
        FILE* stream;
        close(fds[0]);

        stream = fdopen(fds[1], "w");
        fprintf(stream, "Hello pipe and dup.\n");
        fprintf(stream, "Advanded Linux Programming is good.\n");
        fprintf(stream, "Is APUE better?\n");
        fflush(stream);

        close(fds[1]);

        /* wait for the child process to finish */
        waitpid(pid, NULL, 0);
    }

    return 0;
}
