#include "../headers/new.h"

int language = -1;

int newcmd(int argc, char* argv[]) {
    //check how many arguments are provided
    if (argc < 3) {
        errno = EINVAL;
        perror("No language was provided, Project Manager supports c and c++/cpp");
        return -1;
    }

    //define which language we want the new item to be
    if (!strcmp(C ,argv[2])) {
        language = 0;
    } else if ((!strcmp(CPP, argv[2]) || !strcmp(CPP_, argv[2]))) {
        language = 1;
    } else {
        errno = EINVAL;
        perror("Invalid language, Project Manager supports c and c++/cpp");
        return -1;
    }

    //now we proceed to seeing what the user want the create new
    if (argc < 4) {
        errno = EINVAL;
        perror("No item provided, see 'pjm help' for a list of possible new item ");
    }

    //Check for every item
    if (!strcmp("project", argv[3])) {
        newpj(argc, argv, language);
    } else if (!strcmp("header", argv[3])) {
        newheader(argc, argv, language);
    } else if (!strcmp("headeronly", argv[3])) {
        //newheaderonly(argc, argv, language);
    } else if (!strcmp("main", argv[3])) {
        //newmain(argc, argv, language);
    } else if (language && !strcmp("class", argv[3])) { //classes are specific to c++
        //newcppclass(argc, argv, language);
    } else {
        errno = EINVAL;
        perror("Invalid item name, see 'pjm help' for a list of available items");
        return -1;
    }

    return 0;
}