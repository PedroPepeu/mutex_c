// main.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "logic.h"

#define NUM_THREADS 5

void* thread_routine(void* arg) {
    int id = *((int*)arg);
    for (int i = 0; i < 5; ++i) {
        if (i % 2 == 0) {
            deposit(100.0 + id);
        } else {
            withdraw(50.0 + id);
        }
        usleep(100000); // simulate work (100 ms)
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    init_account();

    for (int i = 0; i < NUM_THREADS; ++i) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, thread_routine, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("Final balance: %.2f\n", get_balance());

    cleanup_account();
    return 0;
}
