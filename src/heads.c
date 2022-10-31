#include "../headers/heads.h"



void newheader(int argc, char *argv[], int language) {
    /*if (argc < 5) {
        errno = EINVAL;
        perror("No name argument provided ");
    }
    
    FILE *fp = fopen("./uwu.h", "w");
    
    fclose(fp);

    return;*/
    char name[FILENAME_MAX];
    getcwd(name, FILENAME_MAX);
    printf(name);
}