#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int read_fd;
    int write_fd;
    struct stat stat_buf;
    off_t offset = 0;

    read_fd = open(argv[1], O_RDONLY);
    fstat(read_fd, &stat_buf);

    write_fd = open(argv[2], O_WRONLY | O_CREAT, stat_buf.st_mode);

    /* fast copy */
    printf("Now copying from %s to %s...\n", argv[1], argv[2]);
    sendfile(read_fd, write_fd, offset, &stat_buf.st_size, NULL, 0);
    printf("Done!\n");

    close(read_fd);
    close(write_fd);

    return 0;
}
