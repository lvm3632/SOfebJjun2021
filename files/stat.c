#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argvnum, char **argv){
    char *originalName = argv[1];
    char *newName = argv[2];
    struct stat sb;

    int foundOriginal = stat(originalName, &sb);
    int foundNewName = stat(newName, &sb);

     //Caso 1 renombar si arch1.txt existe y arch2.txt no existe lo va a renombrar
    if(foundOriginal == 0 && foundNewName == -1){
       
        link(originalName, newName);
         unlink(originalName);
        printf("Entro caso 1");
        return 0;
     // Caso 2 si arch2.txt existe manda un mensaje de error   
    }else if(foundNewName == 0 && S_ISREG(sb.st_mode) ){
        printf("El archivo con segundo argumento ya existe");
        printf("Entro caso 2");
        return 0;
     // Si dir2 existe y es un directorio mueve arch1.txt dentro de dir2   
    }else if(foundOriginal == 0 && foundNewName == 0 && S_ISDIR(sb.st_mode)){
        //unlink(originalName);
         link(originalName,  "dir2" );
        
         printf("Se ha movido el archivo");
         printf("Entro caso 3");
         return 0;
    }

    printf("No entro a ningún caso \n");


    

    return 1;
}




