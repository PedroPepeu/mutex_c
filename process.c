#include <stdio.h>
#include "header.h"

void* process_task(void* arg) {
    int i;
    for(i = 0; i < 100; i++) {
        printf("Process task is running. t=%d\n", i);
    }
    return NULL;
}
