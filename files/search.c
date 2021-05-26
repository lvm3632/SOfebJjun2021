#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../student.h"

int main(int argc, char **argv){
    char *filename= argv[1];
    char *parameter = argv[2];
    char *input = argv[3];

    FILE *foriginal;
    foriginal = fopen(filename, "rb");

    int size = 0; 
    STUDENT newstudent;
     while(fread(&newstudent,sizeof(newstudent),1,foriginal) != 0){   
        size++;
     }
        rewind(foriginal);
       for(int i=0;i<size;i++){
        fread(&newstudent,sizeof(newstudent),1,foriginal);
       if(strcmp(parameter,"name")==0){
           if(strcmp(input,newstudent.name) == 0){
               printf("\n");
               printf("------Dato encontrado------\n");
               printf("Nombre:%s\nApellido:%s \nID:%d \nSemestre:%d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);
               printf("----------------");
               break;
           }else{
               //printf("Dato no encontrado por name");
               //printf("\n");
           }
       }else if(strcmp(parameter,"lastname")==0){
           if(strcmp(input,newstudent.lastname) == 0){
               printf("\n");
               printf("------Dato encontrado------\n");
               printf("Nombre:%s\nApellido:%s \nID:%d \nSemestre:%d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);
               printf("----------------");
               break;
           }else{
               //printf("Dato no encontrado por lastname");
           }
       }else if(strcmp(parameter,"id")==0){
           int id = atoi(input);
           if(id == newstudent.id){
               printf("\n");
               printf("------Dato encontrado------\n");
               printf("Nombre:%s\nApellido:%s \nID:%d \nSemestre:%d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);
               printf("----------------");
               break;
           }else{
               //printf("\n");
               //printf("Dato no encontrado por ID");
               
           }
       }else if(strcmp(parameter,"semestre")==0){
           int semestre = atoi(input);
           if(semestre == newstudent.semestre){
               printf("\n");
               printf("------Dato encontrado------\n");
               printf("Nombre:%s\nApellido:%s \nID:%d \nSemestre:%d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);
               printf("----------------");
               break;
           }else{
               //printf("\n");
               //printf("Dato no encontrado por semestre");   
           }
   }
   
   if(i==size-1)printf("Dato no encontrado");
}
   printf("\n");
   fclose(foriginal);
    return 0;
}