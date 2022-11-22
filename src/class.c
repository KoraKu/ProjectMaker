#include "../headers/class.h"

int newclass(int argc, char *argv[]) {
    if (argc < 4) {
        errno = EINVAL;
        perror("No class name provided ");
        return -1;
    }

    int language = 1;
    int r = newheader(argc, argv, language, 0); //newheader modifiesthe name in argv[3]
    if (r != 0) {
        return -1;
    }

    char name[strlen(argv[3])];
    strcpy(name, argv[3]);

    char classname[strlen(name)];
    strcpy(classname, name);

    for(int i = strlen(classname) - 4; i < strlen(classname) -1; ++i) {
        classname[i] = '\0';
    }
    
    //Replace the incorrect char in the name and also capitalize lowercase letters
    if (classname[0] >= 'a' && classname[0] <= 'z') {
        classname[0] = toupper(classname[0]);
    }
    
    //open file
    chdir("./headers");
    FILE *fp = fopen(name, "a");

    //Prints the class header
    fprintf(fp, "\n\nclass %s {\n", classname);

    //public
    fprintf(fp, "\tprivate:\n\t\t//private variable/method\n");

    //private
    fprintf(fp, "\n\tpublic:\n\t\t%s();\n\t\t~%s();\n\t\t//public method and variable\n", classname, classname);


    //Print the last '}'
    fprintf(fp, "};\n");

    fclose(fp);

    return 0;
}