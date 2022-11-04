#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "./headers/const.h"

#include "headers/new.h"

int main(int argc, char *argv[]) {    
    //if no argument was provided to the program :
    if(argc == 1) {
        errno = EINVAL;
        perror("No argument has been provided, see 'pjm help' to get a list of available arguments ");
        return -1;
    }

    //do first the help : not implemented yet...
    if (!strcmp("help", argv[1])) {
        //call help function  
    }
    //then, the new function :
    else if (!strcmp("new", argv[1])) {
        return newcmd(argc, argv);//newcmd return -1 if fail thus main must return the result of newcmd if it fail.
        
    } else {
        errno = EINVAL;
        perror("First argument must be 'new' or 'help', see 'pjm help' for detailed explaination ");
        
    }


    return 0;
}