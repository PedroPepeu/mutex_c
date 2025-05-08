#ifndef HEADER_H
#define HEADER_H

#include <pthread.h>

void* increment_task(void* arg);
void* process_task(void* arg);
void* memory_task(void* arg);

#endif