#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/time.h>

void timer_handler(int signal_number)
{
    static int count = 0;
    printf("timer expired %d times\n", ++count);
}

int main()
{
    struct sigaction sa;
    struct itimerval timer;

    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &timer_handler;
    sigaction(SIGVTALRM, &sa, NULL);

    /* configure the timer to expire after 250 ms */
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 250000;

    /* ... and every 250 ms after that */
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 250000;

    /* start a virtual timer. It counts down whenever this process is executing. */
    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    /* do busy work */
    while(1);
}

