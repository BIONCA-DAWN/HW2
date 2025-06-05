#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Coordinator: Invalid number of arguments.\n");
        return 1;
    }

    char *divisor = argv[1];

    for (int i = 2; i < 6; ++i) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Coordinator: fork failed");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {
        
            execlp("./checker", "checker", divisor, argv[i], (char *)NULL);
            perror("Coordinator: exec failed");
            exit(EXIT_FAILURE);
        } else {
        
            printf("Coordinator: forked process with ID %d.\n", pid);
            printf("Coordinator: waiting for process [%d].\n", pid);

            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                int code = WEXITSTATUS(status);
                printf("Coordinator: child process %d returned %d.\n", pid, code);
            }
        }
    }

    printf("Coordinator: exiting.\n");
    return 0;
}
