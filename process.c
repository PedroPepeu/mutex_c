#include <stdio.h>
#include "header.h"

int occupied = 0;

void* process_task(void* arg) {
    occupied = 1;
    int i;
    for(i = 0; i < 100; i++) {
        printf("Process task is running. t=%d\n", i);
    }
    occupied = 0;
    return NULL;
}
