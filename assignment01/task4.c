// Name: Areeba Tariq
// Reg No: 23-ntu-cs-1139
// Task 4: Factorial using return value in Thread

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *factorial(void *arg) {
    int num = *(int *)arg;
    long *result = malloc(sizeof(long)); // Memory for returning value
    *result = 1;

    for(int i = 1; i <= num; i++) {
        *result *= i;   // Calculating factorial
    }
    return result;
}

int main() {
    pthread_t t;
    int n;
    long *res;

    printf("Enter number: ");
    scanf("%d", &n);

    pthread_create(&t, NULL, factorial, &n);
    pthread_join(t, (void **)&res); // Receiving return value

    printf("Factorial of %d is %ld\n", n, *res);

    free(res); // Free allocated memory
    return 0;
}
