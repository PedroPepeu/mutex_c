// logic.c
#include "logic.h"
#include <stdio.h>

static double balance = 0.0;
static pthread_mutex_t balance_mutex; // thread mutex

void init_account() {
    // Initialize the threads
    pthread_mutex_init(&balance_mutex, NULL);
}

void cleanup_account() {
    // Destroy the mutex and free system resource
    pthread_mutex_destroy(&balance_mutex);
}

void deposit(double amount) {
    pthread_mutex_lock(&balance_mutex); // Lock while the money is being moved
    balance += amount;
    printf("[DEPOSIT] +%.2f | Balance: %.2f\n", amount, balance);
    pthread_mutex_unlock(&balance_mutex); // Unlock after the movement is done
}

void withdraw(double amount) {
    pthread_mutex_lock(&balance_mutex); // Lock while the money is being moved
    if (balance >= amount) { // Check if the amount is removable
        balance -= amount;
        printf("[WITHDRAW] -%.2f | Balance: %.2f\n", amount, balance);
    } else {
        printf("[WITHDRAW FAILED] -%.2f | Balance: %.2f (Insufficient)\n", amount, balance);
    }
    pthread_mutex_unlock(&balance_mutex); // Unlock after the movement is done
}

double get_balance() {
    pthread_mutex_lock(&balance_mutex); // Lock while the money is being moved
    double current_balance = balance;
    pthread_mutex_unlock(&balance_mutex); // Unlock after the movement is done
    return current_balance;
}
