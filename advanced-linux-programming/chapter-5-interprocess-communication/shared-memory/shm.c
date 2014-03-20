#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main()
{
    int segment_id;
    char* shared_memory;
    struct shmid_ds shmbuffer;
    int segment_size;
    const int shared_segment_size = 0x6400;

    /* allocate a shared memory segment */
    segment_id = shmget(IPC_PRIVATE, shared_segment_size, 
                        IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);

    /* attach the shared memory segment */
    shared_memory = (char*)shmat(segment_id, 0, 0);
    printf("shared memory attached at: %p\n", shared_memory);

    /* get info about shared memory */
    shmctl(segment_id, IPC_STAT, &shmbuffer);

    sprintf(shared_memory, "Hello Shared Memory");

    shmdt(shared_memory);

    shared_memory = (char*)shmat(segment_id, (void*)0x5000000, 0);
    printf("shared memory reattached at: %p\n", shared_memory);

    printf("%s\n", shared_memory);
    
    shmdt(shared_memory);

    /* deallocate the shared memory segment */
    shmctl(segment_id, IPC_RMID, 0);

    return 0;
}
