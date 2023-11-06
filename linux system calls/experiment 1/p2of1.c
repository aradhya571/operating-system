#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Forking the process...\n");

    pid_t child_pid = fork();

    if (child_pid == 0) {
        printf("Child process (PID: %d)\n", getpid());
    } else if (child_pid > 0) {
        int status;
        wait(&status);
        printf("Parent process (PID: %d), Child exited with status: %d\n", getpid(), status);
    } else {
        printf("Fork failed.\n");
    }

    return 0;
}
