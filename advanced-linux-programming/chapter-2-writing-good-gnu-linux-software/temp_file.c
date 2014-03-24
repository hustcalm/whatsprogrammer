#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int temp_file_handle;

temp_file_handle write_temp_file(char* buffer, size_t length)
{
    char temp_filename[] = "/tmp/temp_file.XXXXXX";
    int fd = mkstemp(temp_filename);

    unlink(temp_filename);

    write(fd, &length, sizeof(length));

    write(fd, buffer, length);

    return fd;
}

char* read_temp_file(temp_file_handle temp_file, size_t* length)
{
    char* buffer;
    int fd = temp_file;

    lseek(fd, 0, SEEK_SET);

    read(fd, length, sizeof(*length));

    buffer = (char*)malloc(*length);

    read(fd, buffer, *length);

    close(fd);

    return buffer;
}

int main(int argc, char* argv[])
{
    size_t length;

    int temp_file_handle = write_temp_file("hello temp file", 5);
    char* read_buffer = read_temp_file(temp_file_handle, &length);

    printf("Buffer read is: %s.\n", read_buffer);

    free(read_buffer);
    read_buffer = NULL;

    return 0;
}
