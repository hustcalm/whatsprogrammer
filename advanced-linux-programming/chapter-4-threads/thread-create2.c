#include <pthread.h>
#include <stdio.h>

struct char_print_params
{
    char character;
    int count;
};

void* char_print(void* parameters)
{
    struct char_print_params* param = (struct char_print_params*)parameters;

    int i;

    for(i = 0; i < param->count; i++) {
        fputc(param->character, stderr);
    }

    return NULL;
}

int main()
{
    pthread_t thread1_id, thread2_id;

    struct char_print_params thread1_params, thread2_params;

    thread1_params.count = 100;
    thread1_params.character = 'l';

    thread2_params.count = 100;
    thread2_params.character = 'i';

    pthread_create(&thread1_id, NULL, &char_print, &thread1_params);
    pthread_create(&thread2_id, NULL, &char_print, &thread2_params);

    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);

    return 0;
}
