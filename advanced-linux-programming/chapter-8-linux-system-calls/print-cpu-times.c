#include <stdio.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <unistd.h>

void print_cpu_times()
{
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    printf("CPU time: %ld.%06ld sec user, %ld.%06ld sec sys.\n", 
            usage.ru_utime.tv_sec, usage.ru_utime.tv_usec,
            usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
}

int main()
{
    print_cpu_times();

    return 0;
}
