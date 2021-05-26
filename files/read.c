#include <stdio.h>
#include <stdlib.h>
#include "../student.h"

int main(int argc, char **argv){
    char *filename = argv[1];
    char *size_number = argv[2];
    int size = atoi(size_number);

    //char buffer[96];
    //printf("%d: ", size);
    //scanf("%d", &cuantos);

    FILE *foriginal;
    foriginal = fopen(filename, "rb");
    
   // int a = fread(buffer, sizeof(char),size,foriginal);

  /* while(fread(buffer, sizeof(char),size,foriginal)){
       
       printf("%s", buffer);
       STUDENT newstudent;
        fread(&newstudent,sizeof(newstudent),1,foriginal);

        printf("%d", newstudent.id);
   }*/

   for(int i=0;i<size;i++){
       STUDENT newstudent;
       fread(&newstudent,sizeof(newstudent),1,foriginal);
       printf("%s %s %d %d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);
   }

    /*for(int i=0;i<cuantos;i++){
        STUDENT newstudent;
        printf("nombre: ");
        scanf("%s", newstudent.name);
        printf("apellido: ");
        scanf("%s", newstudent.lastname);
        printf("id: ");
        scanf("%d", &newstudent.id);
        printf("semestre: ");
        scanf("%d", &newstudent.semestre);

        fread(&newstudent, sizeof(newstudent),1,fdestino); // El 1 es porque es solo 1 estudiante
        //printf("%s %s %d %d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);
    }*/


    fclose(foriginal);

    return 0;
}