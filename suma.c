#include <stdio.h> 
#include <stdlib.h>

int main(int numarg, char **argv){
	
	if(numarg==1){
		printf("No hay argumentos suficientes\n");
		return 0;
	}
	
	int total = 0;
	for(int i=1;i<numarg;i++){
		
		int temp = atoi(argv[i]);
		total += temp;
	}	
	printf("%i\n", total);
	
	return 0;
}