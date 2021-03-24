#include <unistd.h>
#include <ctype.h>
// 0 = stdin
// 1 = stdout

int main(){
	char minc;
	char mayc;
    // El 1 es de un byte, y el 0 de entrada stdin
	while(read(0,&minc,1)){
		mayc = toupper(minc);
		write(1,&mayc,1);
	}
	return 0;
}