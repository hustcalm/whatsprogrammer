#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE* stream = popen("sort", "w");

    fprintf(stream, "hi\n");
    fprintf(stream, "hello\n");
    fprintf(stream, "hey\n");

    pclose(stream);

    return 0;
}
