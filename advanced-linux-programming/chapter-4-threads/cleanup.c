#include <malloc.h>
#include <pthread.h>

void* allocate_buffer(size_t size)
{
    return malloc(size);
}

void deallocate_buffer(void* buffer)
{
    free(buffer);
}

void do_some_work()
{
    void* tmp_buffer = allocate_buffer(1024);

    pthread_cleanup_push(deallocate_buffer, tmp_buffer);

    /* do some work here that might call pthread_exit
     * or might be cancelled
     */

    pthread_cleanup_pop(1);
}
