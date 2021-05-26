#include <stdio.h>
#include <stdlib.h>

int main(int argnum, char **argv){
    char *original = argv[1];
    char *destino = argv[2];
    char buffer;
    // Solamente leera bits
    // size cantidad de caracteres a /m
    FILE *foriginal, *fdestino;
    foriginal = fopen(original, "rb");
    fdestino = fopen(destino,"wb");
    while(fread(&buffer,sizeof(char),1,foriginal)){
        if(buffer == '\n'){
            char *linea;
            size += 1;
            fseek(foriginal, -size, SEEK_CUR);
            linea = (char *) calloc(size, sizeof(char)); // linea[size];
            fread(linea, sizeof(char), size, foriginal);
            if(strstr(linea, "hola") == NULL){
                fwrite(&buffer, sizeof(char),1,fdestino);
            }
            size = 0;
        }else{
            size += 1;
        }
        fwrite(&buffer, sizeof(char),1,fdestino);
    } 
    fclose(foriginal);
    fclose(fdestino);
    return 0;
}

//strcmp comparar si una cadena es igual ("hola", "hola"); si son igual es 0
// fseek
//strstr(sent,word) regresa la casilla donde inicia

// SEEK_SET inicio arriba
// SEEK_CUR pos current
// SEEK_END pos final