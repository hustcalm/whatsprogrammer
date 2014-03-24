#include <malloc.h>
#include <pthread.h>
#include <semaphore.h>

struct job{
    struct job* next;
    /* other members omitted */
};

struct job* job_queue;

pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

sem_t job_queue_count;

void initialize_job_queue()
{
    job_queue = NULL;
    sem_init(&job_queue_count, 0, 0);
}

void* thread_function(void* args)
{
    while(1) {
        struct job* next_job;

        sem_wait(&job_queue_count);

        pthread_mutex_lock(&job_queue_mutex);

        next_job = job_queue;
        job_queue = job_queue->next;

        pthread_mutex_unlock(&job_queue_mutex);

        process_job(next_job);
        free(next_job);
    }
    return NULL;
}

void enqueue_job(/* job-specific data here... */)
{
    struct job* new_job;
    new_job = (struct job*)malloc(sizeof(struct job));

    /* set the other fields of the job struct here... */

    pthread_mutex_lock(&job_queue_mutex);

    new_job->next = job_queue;
    job_queue = new_job;

    sem_post(&job_queue_count);

    pthread_mutex_unlock(&job_queue_mutex);
}


