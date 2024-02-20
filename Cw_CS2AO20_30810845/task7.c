#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int counter = 0;

int main() {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        for (int i = 0; i < 10; i++) {
            printf("child %d process: counter=%d\n", getpid(), ++counter);
            fflush(stdout); // Flush output to ensure it's printed immediately
            sleep(1);
        }
    } else {
        // Parent process
        for (int i = 0; i < 10; i++) {
            printf("parent %d process: counter=%d\n", getpid(), ++counter);
            fflush(stdout); // Flush output to ensure it's printed immediately
            sleep(1);
        }
        // Wait for the child to finish
        wait(NULL);
    }

    return 0;
}

