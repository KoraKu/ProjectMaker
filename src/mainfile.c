#include "../headers/mainfile.h"

int newmain(int argc, char *argv[], int language) {
    if (access("main.c", F_OK) == 0 || access("main.cpp", F_OK) == 0) {
        errno = EEXIST;
        perror("Main file already exists.");
        return -1;
    }
    
    char name[9];
    if (language) {
        strcpy(name, "main.cpp");
    } else {
        strcpy(name, "main.c");
    }

    FILE *fp = fopen(name, "w");
    if (!fp) {
        printf("Unable to create file.");
        return -1;
    }
     
    if (language) {
        fprintf(fp, "%s", INT_MAIN_CPP);
    } else {
        fprintf(fp, "%s", INT_MAIN_C);
    }

    fclose(fp);




    return 0;
}