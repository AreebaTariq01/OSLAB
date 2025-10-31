
//Question 6 - Array Sum with Multiple Threads

//Write a C program that calculates array sum using multiple threads:

//1.	Create an array of 20 integers: {1, 2, 3, ..., 20}
//2.	Create 4 threads, each calculating sum of 5 elements:   Thread 1: elements 0-4 (sum of 1 to 5)
  // Thread 2: elements 5-9 (sum of 6 to 10)
  //Thread 3: elements 10-14 (sum of 11 to 15)
   //Thread 4: elements 15-19 (sum of 16 to 20)
//3.	Pass the starting index and count to each thread using a structure:
//4.	Each thread prints its partial sum
//.	Main thread collects all return values and calculates total sum easy code with comments using pthread simple easy that doesnot look like ai generated



#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


#define SIZE 20
#define THREADS 4

// Structure to pass data to each thread
struct ThreadData {
    int start;
    int end;
};

// The array to sum
int arr[SIZE];

// Function executed by each thread
void* calculate_sum(void* arg) {
    struct ThreadData* data = (struct ThreadData*)arg;
    int sum = 0;
    for (int i = data->start; i <= data->end; i++) {
        sum += arr[i];
    }
    printf("Thread handling elements %d to %d → Partial Sum = %d\n", data->start, data->end, sum);

    // Return sum as a pointer
    int* result = (int*)malloc(sizeof(int));
    *result = sum;
    return result;
}

int main() {
    pthread_t tid[THREADS];
    struct ThreadData threadData[THREADS];
    int totalSum = 0;

    // Initialize array with 1 to 20
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    // Create 4 threads, each handling 5 elements
    for (int i = 0; i < THREADS; i++) {
        threadData[i].start = i * 5;
        threadData[i].end = threadData[i].start + 4;
        pthread_create(&tid[i], NULL, calculate_sum, &threadData[i]);
    }

    // Collect results from all threads
    for (int i = 0; i < THREADS; i++) {
        int* partialSum;
        pthread_join(tid[i], (void**)&partialSum);
        totalSum += *partialSum;
        free(partialSum);
    }

    printf("\nTotal Sum = %d\n", totalSum);
    return 0;
}

