// logic.h
#ifndef LOGIC_H
#define LOGIC_H

#include <pthread.h>

void init_account();
void cleanup_account();
void deposit(double amount);
void withdraw(double amount);
double get_balance();

#endif
