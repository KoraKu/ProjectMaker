#include "../headers/directory.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int newdir(int argc, char **argv) {
    if (argc < 4) {
        errno = EINVAL;
        perror("No directory name provided.");
        return -1;
    }

    if (strchr(argv[3], '/') != NULL) {
        errno = EINVAL;
        perror("Invalid char for filename : '/' is not allowed ");
        return -1;
    }

    int namelen = strlen(argv[3]);
    char nameheader[namelen+1+7];
    char namesrc[namelen+1+3];

    strcpy(nameheader, "headers/");
    strcpy(namesrc, "src/");

    strcat(nameheader, argv[3]);
    strcat(namesrc, argv[3]);

    mkdir(nameheader, 0777);
    mkdir(namesrc, 0777);

    printf("Sucessfully created %s directory in /src and /headers.\n", argv[3]);

    return 0;
}