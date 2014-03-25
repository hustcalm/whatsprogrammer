#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    const char* const filename = argv[1];
    struct stat buf;

    stat(filename, &buf);

    printf("The permission mode of %s is %o.\n", filename, buf.st_mode);

    char* perm = (char*)malloc(11);
    int len = 0;
    perm[len] = '-';

    /* check user permission */
    if(buf.st_mode & S_IRUSR)
        perm[++len] = 'r';
    else
        perm[++len] = '-';

    if(buf.st_mode & S_IWUSR)
        perm[++len] = 'w';
    else
        perm[++len] = '-';

    if(buf.st_mode & S_IXUSR)
        perm[++len] = 'x';
    else
        perm[++len] = '-';

    /* check group permission */
    if(buf.st_mode & S_IRGRP)
        perm[++len] = 'r';
    else
        perm[++len] = '-';

    if(buf.st_mode & S_IWGRP)
        perm[++len] = 'w';
    else
        perm[++len] = '-';

    if(buf.st_mode & S_IXGRP)
        perm[++len] = 'x';
    else
        perm[++len] = '-';

    /* check others permission */
    if(buf.st_mode & S_IROTH)
        perm[++len] = 'r';
    else
        perm[++len] = '-';

    if(buf.st_mode & S_IWOTH)
        perm[++len] = 'w';
    else
        perm[++len] = '-';

    if(buf.st_mode & S_IXOTH)
        perm[++len] = 'x';
    else
        perm[++len] = '-';

    perm[++len] = '\0';

    printf("mock the ls print: %s.\n", perm);

    return 0;
}
