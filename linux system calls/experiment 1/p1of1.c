#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Forking the process...\n");

    pid_t child_pid = fork();

    if (child_pid == 0) {
        // This code executes in the child process
        printf("Child process (PID: %d)\n", getpid());
        execl("/bin/ls", "ls", "-l", NULL);
    } else if (child_pid > 0) {
        // This code executes in the parent process
        printf("Parent process (PID: %d)\n", getpid());
    } else {
        printf("Fork failed.\n");
    }

    return 0;
}

