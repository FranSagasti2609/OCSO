
#include <stdio.h>
#include <unistd.h> //Libreria necesaria para pid_t
#include <sys/types.h>

int main(){

    pid_t hijo = fork();
    int estado;

    if(hijo==0){
        execlp("/bin/ls", "ls", "-l", NULL);
    } else {
        wait(&estado);
        printf("Listado de directorio finalizado.\n");
    }

    return 0;
}