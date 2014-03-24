#include <assert.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int random_number(int min, int max)
{
    static int dev_random_fd = -1;

    char* next_random_byte;
    int bytes_to_read;
    unsigned random_value;

    assert(max > min);

    if(dev_random_fd == -1)
    {
        dev_random_fd = open("/dev/random", O_RDONLY);
        assert(dev_random_fd != -1);
    }

    next_random_byte = (char*)&random_value;

    bytes_to_read = sizeof(random_value);;

    do {
        int bytes_read;
        bytes_read = read(dev_random_fd, next_random_byte, bytes_to_read);
        bytes_to_read -= bytes_read;
        next_random_byte += bytes_read;
    }while(bytes_to_read > 0);

    return min + (random_value % (max - min + 1));
}
