#include <stdio.h> 

// y un asteristico solo es un arreglo
// Doble asteristico es un arreglo de arreglo de caracteres
int main(int numarg, char **argv){
	
	for(int i=1;i<numarg;i++)
		printf("Hello World %s\n", argv[i]);
	
	
}