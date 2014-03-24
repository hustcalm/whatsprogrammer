#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0;

void sigusr1_handler(int signal_number)
{
    ++sigusr1_count;
}

int main()
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &sigusr1_handler;
    sigaction(SIGUSR1, &sa, NULL);

    /** Main stuff here **/

    printf("The SIGUSR1 signal was raised for %d times.\n", sigusr1_count);

    return 0;
}
