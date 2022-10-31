#include "../headers/const.h"

/*int fcpy(const char *src, const char *dst) {
    const int buffsize = 64000;
    char *buff = (char*)malloc(buffsize);
    if (buff != 0) {return -1;}

    FILE *fin = fopen(src, "rb");
    if (!fin) {
        free(buff);
        return -1;
    }

    FILE *fout = fopen(dst, "wb");
    if (!fout) {
        free(buff);
        return -1;
    }
    size_t bufflen;
    while((bufflen = fread(buff, 1, buffsize, fin)) > 0) {
        if (bufflen != fwrite(buff, 1, buffsize, fout)) {
            //error while writing
            fclose(fin);
            fclose(fout);
            free(buff);
            return -1;
        }
    }

    free(buff);
    int r = ferror(fin) ? -1 : 0; 
    fclose(fin);
    return r | (fclose(fout) ? -1 : 0);
}*/