#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char* path = argv[1];
    int retval;

    retval = access(path, F_OK);

    if(retval == 0)
    {
        printf("%s exists.\n", path);
    }
    else {
        if(errno == ENOENT) {
            printf("%s does not exist.\n", path);
        }
        else if(errno == EACCES) {
            printf("%s is not accessible.\n", path);
        }
        return 0;
    }

    /* check read access */
    retval = access(path, R_OK);

    if(retval == 0) {
        printf("%s is readable.\n", path);
    }
    else {
        printf("%s is not readable, permission denied!\n", path);
    }

    /* check write access */
    retval = access(path, W_OK);

    if(retval == 0) {
        printf("%s is writable.\n", path);
    }
    else {
        if (errno == EACCES) {
            printf("%s is not writable, permission denied!\n", path);
        }
        else if(errno == EROFS) {
            printf("%s is not writable, read-only system!\n", path);
        }
    }

    return 0;
}
