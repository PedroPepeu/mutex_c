#include <stdio.h>
#include <pthread.h>
#include "header.h"

int main() {
    pthread_t process_thread, memory_thread;

    pthread_create(&process_thread, NULL, process_task, NULL);
    pthread_create(&memory_thread, NULL, memory_task, NULL);

    pthread_join(process_thread, NULL);
    pthread_join(memory_thread, NULL);

    printf("All threads completed.\n");
    return 0;
}