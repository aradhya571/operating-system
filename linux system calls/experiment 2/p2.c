#include <fcntl.h>  // for open()
#include <unistd.h> // for write()
#include <stdio.h>

int main() {
    int fd , cf;
    char buffer[] = "This is the end of example file.";

    // Open a file in write mode, create it if it doesn't exist
    fd = open("ex.txt", O_WRONLY | O_CREAT);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("File opened successfully\n");
    

    // Write to the file
    ssize_t bytesWritten = write(fd, buffer, sizeof(buffer));

    if (bytesWritten == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    printf("Wrote %ld bytes\n", bytesWritten);

    // Close the file
    cf = close(fd);
    close(fd);

    if (cf == 0) {
        printf("File closed successfully.\n");
    }
    
    return 0;
}
