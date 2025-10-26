// Name: Areeba Tariq
// Reg No: 23-ntu-cs-1139
// Task 1: Thread Information Display

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *thread_func(void *arg) {
    int threadNum = *(int *)arg;   // Thread number passed as argument

    printf("Thread %d started. Thread ID: %lu\n", threadNum, pthread_self());

    sleep(rand() % 3 + 1);        // Sleep randomly between 1–3 seconds

    printf("Thread %d completed.\n", threadNum);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadNumbers[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++) {
        threadNumbers[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_func, &threadNumbers[i]); // Creating threads
    }

    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);   // Waiting for threads to finish
    }

    printf("Main thread finished.\n");
    return 0;
}
