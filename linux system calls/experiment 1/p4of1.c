#include <stdio.h>
#include <dirent.h>

int main() {
    printf("Opening the current directory...\n");

    // Open a directory
    DIR *dir = opendir(".");
    if (dir == NULL) {
        printf("Failed to open the directory.\n");
        return 1;
    }

    printf("Directory opened successfully.\n");

    // Read directory entries
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) { 
        printf("Name: %s\n", entry->d_name);
    }

    // Close the directory
    closedir(dir);

    printf("Directory closed successfully.\n");

    return 0;
}
