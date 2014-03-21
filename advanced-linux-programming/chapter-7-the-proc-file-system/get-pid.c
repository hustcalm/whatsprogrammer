#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t get_pid_from_proc_self()
{
    char target[32];
    pid_t pid;
    readlink("/proc/self", target, sizeof(target));

    sscanf(target, "%d", &pid);

    return (pid_t)pid;
}

int main()
{
    printf("PID reported by /proc/self is: %d\n", (int)get_pid_from_proc_self());
    printf("PID reported by getpid() is: %d\n", (int)getpid());

    return 0;
}
