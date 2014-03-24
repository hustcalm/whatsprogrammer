#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char* path = argv[1];
    int fd;
    struct flock lock;

    printf("opening file: %s...\n", path);

    fd = open(path, O_WRONLY);

    printf("locking...\n");
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK;
    fcntl(fd, F_SETLKW, &lock);
    printf("locked, hit Enter to unlock...\n");

    getchar();

    printf("unlocking...\n");
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);

    close(fd);

    return 0;
}
