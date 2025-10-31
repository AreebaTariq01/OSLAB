//Group 6: Thread Return Values
//Question 6 - Array Sum with Multiple Threads

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>   // for malloc() and free()
#define SIZE 20       // total elements in array
#define THREADS 4     // total threads

// Structure to pass data to each thread
struct ThreadData {
    int start; // starting index of array part
    int end;   // ending index of array part
};

// Global array
int arr[SIZE];

// Function that each thread will run
void* calculate_sum(void* arg) {
    struct ThreadData* data = (struct ThreadData*)arg; // get thread data
    int sum = 0;

    // Calculate sum for given range
    for (int i = data->start; i <= data->end; i++) {
        sum += arr[i];
    }

    // Print partial result
    printf("Thread handling elements %d to %d → Partial Sum = %d\n", data->start, data->end, sum);

    // Return sum to main thread
    int* result = (int*)malloc(sizeof(int)); // allocate memory to return value
    *result = sum;
    return result;
}

int main() {
    pthread_t tid[THREADS];            // array to hold thread IDs
    struct ThreadData threadData[THREADS]; // data for each thread
    int totalSum = 0;                  // total sum of all elements

    // Fill array with values 1 to 20
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    // Create 4 threads, each summing 5 elements
    for (int i = 0; i < THREADS; i++) {
        threadData[i].start = i * 5;         // set starting index
        threadData[i].end = threadData[i].start + 4; // set ending index
        pthread_create(&tid[i], NULL, calculate_sum, &threadData[i]);
    }

    // Collect results from all threads
    for (int i = 0; i < THREADS; i++) {
        int* partialSum;
        pthread_join(tid[i], (void**)&partialSum); // wait for thread to finish
        totalSum += *partialSum;                   // add partial sum to total
        free(partialSum);                          // free allocated memory
    }

    // Print final total sum
    printf("\nTotal Sum = %d\n", totalSum);
    return 0;
}
