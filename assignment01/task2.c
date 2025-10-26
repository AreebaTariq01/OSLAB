// Name: Areeba Tariq
// Reg No: 23-ntu-cs-1139
// Task 2: Greeting Thread

#include <stdio.h>
#include <pthread.h>

void *greet(void *arg) {
    char *name = (char *)arg;      // Receiving name
    printf("Thread says: Hello, %s! Welcome to threads.\n", name);
    return NULL;
}

int main() {
    pthread_t t;
    
    printf("Main thread: Waiting for greeting...\n");
    
    pthread_create(&t, NULL, greet, "Areeba"); // Passing name to thread
    pthread_join(t, NULL); // Waiting for greeting

    printf("Main thread: Greeting completed.\n");
    return 0;
}
