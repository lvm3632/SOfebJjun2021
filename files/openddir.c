#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char **argv){
    char *dirName = argv[1];
    DIR * dir = opendir(dirName);
    //if(dir == NULL) no pudo abrirlo
    struct dirent  * dirContent;
    //dirData.d_name; tambien se puede acceder por atributo
    // dirContent -> d_name por memoria
    while(dirContent = readdir(dir)){
        printf("file %s y esta %lu", dirContent->d_name, dirContent->d_ino);
        printf("\n");
    } 
    //lu long u->unsigned 
    closedir(dir);
    return 0;
}