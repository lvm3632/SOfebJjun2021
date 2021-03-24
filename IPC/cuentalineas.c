#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
// 0 = stdin
// 1 = stdout
int main(){
    char minC;
    char mayC;
    int bandera = 0;
    //1 = 1byte de linea 11
    // Primer argumento a donde voy a escribir
    //  0 entrada estandar, 1 salida estandar, y 2 de error
    // Salida estandar es 1 y 1 de 1 byte
    int count = 0;
    while(read(0,&minC,1)){
        if(minC == '\n' || minC==0x0A){
            count++;
        }
        bandera = 1;
    }

    if(bandera==0){
        printf("\nSaltos de lineas contados: %d\n", count);
        return 0;
    }    

    if(minC != '\n' || minC != 0x0A){
        count++;
    }

    printf("\nSaltos de lineas contados: %d\n", count);
    return 0;
}