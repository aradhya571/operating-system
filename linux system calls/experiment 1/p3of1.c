#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>  // Include errno.h for perror

int main() {
    int fd = open("ex.txt", O_RDONLY);

    if (fd == -1) {
        perror("Failed to open the file");
        return 1;
    }

    printf("File opened successfully.\n");

    // Use stat to get file information
    struct stat file_info;

    if (stat("ex.txt", &file_info) == -1) {
        perror("Failed to get file information");
        return 1;
    }

    printf("File size: %ld bytes\n", file_info.st_size);

    // Close the file descriptor
    if (close(fd) == -1) {
        perror("Failed to close the file");
        return 1;
    }

    printf("File closed successfully.\n");

    return 0;
}
