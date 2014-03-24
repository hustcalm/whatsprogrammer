#include <pthread.h>

void* thread_function(void* thread_arg)
{
    
}

int main()
{
    pthread_attr_t attr;
    pthread_t thread;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&thread, &attr, &thread_function, NULL);
    pthread_attr_destroy(&attr);

    /* Other stuff */

    /* As the second thread is created as a detached one
     * no need to join
     */

    return 0;
}
