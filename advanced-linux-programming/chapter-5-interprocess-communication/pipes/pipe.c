#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void writer(const char* message, int count, FILE* stream)
{
    for(; count > 0; --count) {
        fprintf(stream, "%s\n", message);
        fflush(stream);
        sleep(1);
    }
}

void reader(FILE* stream)
{
    char buffer[1024];
    while(!feof(stream)
            && !ferror(stream)
            && fgets(buffer, sizeof(buffer), stream) != NULL) {
        fputs(buffer, stdout);
    }
}

int main()
{
    int fds[2];
    pid_t pid;

    pipe(fds);

    pid = fork();

    if(pid == (pid_t)0) {
        FILE* stream;
        close(fds[1]);

        stream = fdopen(fds[0], "r");

        reader(stream);

        close(fds[0]);
    }
    else {
        FILE* stream;
        close(fds[0]);

        stream = fdopen(fds[1], "w");

        writer("Hello pipe.", 5, stream);

        close(fds[1]);
    }

    return 0;
}

