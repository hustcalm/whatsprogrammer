#include <stdio.h>
#include <sys/utsname.h>

int main()
{
    struct utsname u;
    uname(&u);

    printf("%s release %s (version %s) on %s\n", u.sysname, u.release,
            u.version, u.machine);

    return 0;
}
