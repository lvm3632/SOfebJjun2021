#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
// y un asteristico solo es un arreglo
// Doble asteristico es un arreglo de arreglo de caracteres
int main(int numarg, char **argv){
	int total = 0;
	
	
	for(int i=1;i<numarg;i++){
		
		int temp = atoi(argv[i]);
		total += temp;
	}
		//printf("Hello World %s\n", argv[i]);
	
	printf("%i\n", total);
	
	

}