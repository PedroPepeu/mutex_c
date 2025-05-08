// logic.c
#include "logic.h"
#include <stdio.h>

static double balance = 0.0;
static pthread_mutex_t balance_mutex;

void init_account() {
    // Initialize the threads
    pthread_mutex_init(&balance_mutex, NULL);
}

void cleanup_account() {
    pthread_mutex_destroy(&balance_mutex);
}

void deposit(double amount) {
    pthread_mutex_lock(&balance_mutex);
    balance += amount;
    printf("[DEPOSIT] +%.2f | Balance: %.2f\n", amount, balance);
    pthread_mutex_unlock(&balance_mutex);
}

void withdraw(double amount) {
    pthread_mutex_lock(&balance_mutex);
    if (balance >= amount) {
        balance -= amount;
        printf("[WITHDRAW] -%.2f | Balance: %.2f\n", amount, balance);
    } else {
        printf("[WITHDRAW FAILED] -%.2f | Balance: %.2f (Insufficient)\n", amount, balance);
    }
    pthread_mutex_unlock(&balance_mutex);
}

double get_balance() {
    pthread_mutex_lock(&balance_mutex);
    double current_balance = balance;
    pthread_mutex_unlock(&balance_mutex);
    return current_balance;
}
