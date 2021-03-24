#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int pidHijoTermino;
int termino = 0;
void signalHandler(int sig){
     pidHijoTermino = wait(NULL);
	printf("Mi hijo termino %d \n", pidHijoTermino);
    termino = 1;
}
int main(){
    signal(17, signalHandler);
    int pid = fork();
    //int pidHijoTermino;
    if(pid  == 0){
        // Proceso hijo
        printf("Soy el proceso hijo\n");
    }else{
        printf("Soy el proceso padre y mi hijo es %d\n", pid);
        while(1){
            printf("Trabajando \n");
            sleep(1);
            if(termino == 1){
                printf("Terminó con el proceso hijo:  %d\n", pidHijoTermino);
                break;
            }
        }
    }
    printf("Terminando %d\n", pidHijoTermino);
    return 0;
}