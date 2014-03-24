#include <pthread.h>

class ThreadExitException
{
    public:

        ThreadExitException(void* return_value)
            :thread_return_value_(return_value)
        {

        }

        void* doThreadExit()
        {
            pthread_exit(thread_return_value_);
        }

    private:
        void* thread_return_value_;
}

void do_some_work()
{
    while(1) {
        /* real job here */

        if(should_exit_thread_immediately) {
            throw ThreadExitException(NULL);
        }
    }
}

void* thread_function(void*)
{
    try{
        do_some_work();
    }
    catch(ThreadExitException as ex) {
        ex.doThreadExit();
    }

    return NULL;
}
