#include "../headers/const.h"

void getprojectlang(char *lang) {
    FILE *fp = fopen(PROJECT_FILE, "r");
    fread(lang, 3, 1, fp);
    fclose(fp);

    return;
}