#include "../headers/heads.h"

void printheadercode(FILE *fp, char *name, int namesz) {

    //first : transform the name so it's all cap and uses _
    char newname[namesz];
    strcpy(newname, name);

    for(int i = 0; i<namesz; ++i) {
        if (newname[i] != '\0') {
            if (newname[i] <= 'z' && newname[i] >= 'a') {//uppercase every lowercase
                newname[i] = toupper(newname[i]);
            } else if (!(newname[i] >= 'A' && newname[i] <= 'Z') && !(newname[i] >= '0' && newname[i] <= '9')) {//if char is neither uppercase or lowercase nor number: change it to _
                newname[i] = '_';
            }
        }
    }

    //write to the file
    fprintf(fp, "#ifndef %s\n#define %s\n#endif", newname, newname);

    return;
}

int newheader(int argc, char *argv[], int language, int headeronly) {
    //check if enough args are provided :
    if (argc < 4) {
        errno = EINVAL;
        perror("No header name provided");
        return -1;
    }

    //check if the name contains illegal char
    if (strchr(argv[3], '/') != NULL) {
        errno = EINVAL;
        perror("Invalid char for filename : '/' is not allowed ");
        return -1;
    }

    //choose the right extension
    int extensionsz = EXT_C_LEN;
    if (language) {
        extensionsz = EXT_CPP_LEN;
    }

    int namelen = strlen(argv[3]);
    char name[namelen+extensionsz];
    strcpy(name, argv[3]);

    //choose the right extension part 2
    if (language) {
        strcat(name, EXT_CPP);
    } else {
        strcat(name, EXT_C);
    }

    argv[3] = name;

   

    //change to headers directory
    chdir("headers");

     //check if there is already a header with the same name :
    if (access(name, F_OK) == 0) {
        chdir(".."); //go backs
        errno = EEXIST;
        perror("A header with this name already exists ");
        return -1;
    }

    //create file and write in it
    FILE *fp = fopen(name, "w");
    printheadercode(fp, name, namelen+extensionsz);
    fclose(fp);

    //go back to ./
    chdir("..");


    printf("Succesfully created header %s \n", name);

    if (!headeronly) {
        //repalce *.h* by *.c* in name
        char srcname[namelen+extensionsz];
        strcpy(srcname, name);
        srcname[namelen+1] = 'c';

        //create new source file
        chdir("src");
        fp = fopen(srcname, "w");
        
        fprintf(fp, "#include \"../headers/%s\"", name);
        fclose(fp);

        chdir(".."); //go back

        printf("Succesfully created source file %s\n");

    }
    return 0;
}