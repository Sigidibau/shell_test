#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char *input = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t pid;
    int status;

    while (1) {
        // Print the shell prompt
        printf("simple_shell> ");
        fflush(stdout);

        // Read input from the user
        read = getline(&input, &len, stdin);
        if (read == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }

        // Remove the newline character from input if present
        if (input[read - 1] == '\n') {
            input[read - 1] = '\0';
        }

        // Check if the input is 'exit' to break the loop
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Create a child process
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            // Define the arguments for execve
            char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
            char *envp[] = {NULL}; // Default environment variables

            // Execute the command
            execve(argv[0], argv, envp);
            // If execve returns, there was an error
            perror("execve");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                printf("Child exited with status %d\n", WEXITSTATUS(status));
            } else {
                printf("Child did not exit normally\n");
            }
        }
    }

    // Free allocated memory
    free(input);

    return 0;
}

