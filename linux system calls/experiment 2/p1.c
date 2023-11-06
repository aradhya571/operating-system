#include <fcntl.h>  // for open()
#include <unistd.h> // for read()
#include <stdio.h>

#define BUF_SIZE 4096

int main() {
    int fd , cf;
    char buffer[BUF_SIZE];

     // Open a file in read-only mode
    fd = open("ex.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("File opened successfully\n");
    

    // Read from the file
    ssize_t bytesRead = read(fd, buffer, BUF_SIZE);

    if (bytesRead == -1) {
        perror("Error reading from file");
        close(fd);
        return 1;
    }

    printf("Read %ld bytes:\n%s\n", bytesRead, buffer);

     // Close the file
    cf = close(fd);
    close(fd);

    if (cf == 0) {
        printf("File closed successfully.\n");
    }
    
    return 0;
}
