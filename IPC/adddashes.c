#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv){
    // El primer argumento path
    // segundo el programa ls
    // opciones -l
    //execl("/usr/bin/ls", "ls", "-l", NULL);
    //printf("Esto no dbee verse \n");
    // fd file descriptor
    // 0 salida tuberia
    // 1 entrada tuberia
    int fd[2];
    int pid;
    pipe(fd);
    pid = fork();

    if(pid == 0){
        // Proceso hijo
        // tr
        // salida de tuberia a la entrada tr
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execl("/usr/bin/tr", "tr", "' '", "-", NULL);
    }
    if(pid > 0){
        // Padre
        // cat
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execl("/usr/bin/cat", "cat", NULL);
        // la entrada de la tuberia al cat
    }
    return 0;
}
    