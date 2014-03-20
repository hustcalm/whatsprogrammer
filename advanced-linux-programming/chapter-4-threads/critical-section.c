#include <pthread.h>
#include <stdio.h>
#include <string.h>

float* balances;

int process_transaction(int from, int to, flost dollars)
{
    int old_cancle_state;

    if(balances[from] < dollars)
        return 1;

    /* Begin critical section */
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, &old_cancle_state);

    balances[from] -= dollars;
    balances[to]   += dollars;

    /* End critical section */
    pthread_setcancelstate(old_cancle_state, NULL);

    return 0;
}
