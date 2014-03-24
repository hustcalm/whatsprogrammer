#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t get_executable_path(char* buffer, size_t len)
{
    char* path_end;
    if(readlink("/proc/self/exe", buffer, len) < 0) {
        return -1;
    }

    path_end = strrchr(buffer, '/');

    if(path_end == NULL)
        return -1;

    ++path_end;

    *path_end = '\0';

    return (size_t)(path_end - buffer);
}

int main(int argc, char* argv[])
{
    char path[PATH_MAX];
    get_executable_path(path, sizeof(path));
    printf("this program is in: %s\n", path);

    return 0;
}
