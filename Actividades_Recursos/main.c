
#include <stdio.h>
#include <unistd.h> //Libreria necesaria para pid_t
#include <sys/wait.h> 
#include <stdlib.h>

int main(){

    pid_t hijo = fork(); //Creacion del hijo
    int estado;

    if(hijo==0){
        execlp("/bin/ls", "ls", "-l", NULL);
    } else if(hijo >1) {
        waitpid(hijo, &estado, 0);
        printf("Listado de directorio finalizado.\n");
    } else if (hijo < 0){
        perror("Error en la creacion de hijo.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}