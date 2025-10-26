#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>   // for pid_t

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execlp("ls", "ls", "-l", NULL);

        // Agar exec fail hua to yeh chalega
        printf("This will not print if exec succeeds.\n");
    } else {
        // Parent process
        printf("Parent still running...\n");
    }

    return 0;
}
