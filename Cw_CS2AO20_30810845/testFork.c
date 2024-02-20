#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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
        printf("Child process: PID=%d\n", getpid());

        // Execute ls command using execvp
        char *args[] = {"/bin/ls", NULL};
        execvp(args[0], args);

        // execvp only returns if an error occurs
        fprintf(stderr, "Error executing ls\n");
        return 1;
    } else {
        // Parent process
        printf("Parent process: PID=%d, Child PID=%d\n", getpid(), pid);

        // Wait for the child process to finish
        wait(NULL);

        printf("Child process terminated\n");
    }

    return 0;
}

