#include <stdio.h>
#include "./student.h"

int main(int argc, char **argv){
    char *filename = argv[1];
    int cuantos;
    printf("Cuantos alumnos a insertar: ");
    scanf("%d", &cuantos);

    FILE *fdestino;
    fdestino = fopen(filename, "wb");

    for(int i=0;i<cuantos;i++){
        STUDENT newstudent;
        printf("nombre: ");
        scanf("%s", newstudent.name);
        printf("apellido: ");
        scanf("%s", newstudent.lastname);
        printf("id: ");
        scanf("%d", &newstudent.id);
        printf("semestre: ");
        scanf("%d", &newstudent.semestre);

        fwrite(&newstudent, sizeof(newstudent),1,fdestino); // El 1 es porque es solo 1 estudiante
        //printf("%s %s %d %d \n", newstudent.name, newstudent.lastname, newstudent.id, newstudent.semestre);
    }
    fclose(fdestino);

    return 0;
}