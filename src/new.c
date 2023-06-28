#include "../headers/new.h"
#include <string.h>

int language = -1;

int newcmd(int argc, char* argv[]) {
    //check how many arguments are provided
    if (argc < 3) {
        errno = EINVAL;
        perror("No item provided, see 'pjm help' for a list of possible new item ");
        return -1;
    }    

    //Check for every item
    if (!strcmp("project", argv[2])) {

        
        if (argc < 4) {
            errno = EINVAL;
            perror("No project language was provided, choose either \"c\" or \"cpp\".");
            return -1;
        }

        //define which language we want the new item to be
        if (!strcmp(C ,argv[3])) {
            language = 0;
        } else if ((!strcmp(CPP, argv[3]) || !strcmp(CPP_, argv[3]))) {
            language = 1;
        } else {
            errno = EINVAL;
            perror("Invalid project language");
            return -1;
        }
        
        //create the project with this language
        return newpj(argc, argv, language);

    } 

    //if we don't create a new project, we get the project language from the .pjm.info
    if (access(PROJECT_FILE, F_OK) != 0) {
        errno = ENOENT;
        perror("No ProjectManager file found, if this directory is already a project your can regenerate the file using `pjm new project <language>`.");
        return -1;
    }
    char lang[4] = "";
    getprojectlang(lang);

    //"parse" the language found in the project file
    if (!strcmp(C ,lang)) {
            language = 0;
        } else if ((!strcmp(CPP, lang) || !strcmp(CPP_, lang))) {
            language = 1;
        } else {
            errno = EINVAL;
            perror("Invalid project language in '.pjm.info'. Please delete and regenerate using `pjm new project <language>`.");
            return -1;
        }
    
    //now we can check for everything else
    if (!strcmp("header", argv[2])) {
        return newheader(argc, argv, language, 0);
    } else if (!strcmp("headeronly", argv[2])) {
        return newheader(argc, argv, language, 1);
    } else if (!strcmp("main", argv[2])) {
        return newmain(argc, argv, language);
    } else if (language && !strcmp("class", argv[2])) { //classes are specific to c++
        return newclass(argc, argv);
    } else if (!strcmp("dir", argv[2])) {
        return newdir(argc, argv);
    } else {
        errno = EINVAL;
        perror("Invalid item name, see 'pjm help' for a list of available items.");
        return -1;
    }

    return 0;
}