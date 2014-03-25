#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    uid_t uid;
    gid_t gid;

    uid = getuid();
    gid = getgid();

    printf("The process is owned by uid: %d gid: %d\n", (int)uid, (int)gid);

    return 0;
}
