// Name: Areeba Tariq
// Reg No: 23-ntu-cs-1139
// Task 3: Number Info Thread

#include <stdio.h>
#include <pthread.h>

void *process(void *arg) {
    int num = *(int *)arg; // Taking value from main

    printf("Number: %d\n", num);
    printf("Square: %d\n", num * num);
    printf("Cube: %d\n", num * num * num);

    return NULL;
}

int main() {
    pthread_t t;
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    pthread_create(&t, NULL, process, &number);
    pthread_join(t, NULL); // Synchronization

    printf("Main thread: Work completed.\n");
    return 0;
}
