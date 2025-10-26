#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_ITERATIONS 1000000

int count = 10;

pthread_mutex_t mutex; // mutex object

// Critical section function
void critical_section(int process) {

    if(process == 0) {
        for (int i = 0; i < NUM_ITERATIONS; i++)
            count--;
    }
    else {
        for (int i = 0; i < NUM_ITERATIONS; i++)
            count++;
    }
}

// Process 0 (Decrement)
void *process0(void *arg) {

    pthread_mutex_lock(&mutex);

    critical_section(0);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

// Process 1 (Increment)
void *process1(void *arg) {

    pthread_mutex_lock(&mutex);

    critical_section(1);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

// ✅ New Process 2 (Increment)
void *process2(void *arg) {

    pthread_mutex_lock(&mutex);

    critical_section(2);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t thread0, thread1, thread2, thread3, thread4;

    pthread_mutex_init(&mutex, NULL);

    // Create threads (same pattern + 1 more)
    pthread_create(&thread0, NULL, process0, NULL);
    pthread_create(&thread1, NULL, process1, NULL);
    pthread_create(&thread2, NULL, process0, NULL);
    pthread_create(&thread3, NULL, process1, NULL);
    pthread_create(&thread4, NULL, process2, NULL); // 👈 new thread

    // Wait for threads to finish
    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    pthread_mutex_destroy(&mutex);

    printf("Final count: %d\n", count);

    return 0;
}
