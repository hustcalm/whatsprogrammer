#include <stdio.h>
#include <errno.h>
#include <time.h>

int better_sleep(double sleep_time)
{
    struct timespec tv;
    tv.tv_sec = (time_t)sleep_time;
    tv.tv_nsec = (long)((sleep_time - tv.tv_sec)*1e+9);

    while(1) {
        int retval = nanosleep(&tv, &tv);
        if(retval == 0) {
            printf("Sleep accomplished!\n");
            return 0;
        }
        else if(errno == EINTR) {
            printf("Sleep interrupted!\n");
            continue;
        }
        else {
            printf("Other codes returned: %d.\n", retval);
            return retval;
        }
    }

    return 0;
}

int main()
{
    return better_sleep(9.034);
}
