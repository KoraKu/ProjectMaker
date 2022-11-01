#include "../headers/project.h"


int newpj(int argc, char *argv[], int language) {
    if (access(PROJECT_FILE, F_OK) == 0) {
        errno = EEXIST;
        perror("Current directory is already a project ");
        return 1;
    } 

    FILE *fp = fopen(PROJECT_FILE, "w");
    fprintf(fp, argv[2]);

    fclose(fp);

    //create the whole project architecture
    mkdir("bin", 0777);
    fp = fopen("./bin/info", "w"); //create "info" file
    if (!fp) {
        printf("UwU ? :(\n");
        return -1;
    }
    fprintf(fp, "compiled program folder");
    fclose(fp);

    mkdir("headers", 0777);
    mkdir("obj", 0777);
    fp = fopen("./obj/info", "w"); //create "info" file
    if (!fp) {
        return -1;
    }
    fprintf(fp, "Object File folder");
    fclose(fp);
    mkdir("resources", 0777);
    mkdir("todo", 0777);

    //creating the files
    //makefile
    fp = fopen("makefile", "w");
    if (!fp) {
        return -1;
    }

    if (!language) {
        fprintf(fp, "%s", MAKEFILE_C);
    } else {
        fprintf(fp, "%s", MAKEFILE_CPP);
    } 
    
    fclose(fp);

    //gitignore
    fp = fopen(".gitignore", "w");
    if (!fp) {
        return -1;
    }

    fprintf(fp, "%s", GITIGNORE);
    fclose(fp);

    //end
    printf("New project succesfyully created !\nYou may modify the `makefile` and `.gitignore` to better suit your needs.\n");

    return 0;

}