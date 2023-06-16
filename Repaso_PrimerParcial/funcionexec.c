/*
Problema: Desarrolla un programa en C que cree un proceso hijo. 
El proceso hijo debe reemplazarse a sí mismo con el comando Unix ls utilizando execlp(). 
Asegúrate de que el proceso padre espere hasta que el proceso hijo haya terminado.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t hijo = fork(); //Creacion del hijo
    if(hijo==0){
        execlp("bin/ls", "-ls", NULL);
        exit(1);
    } else {
        waitpid(hijo, NULL, 0);
        printf("Ya termino la ejecucion de mi hijo.\n");
    }


    return 0;
}