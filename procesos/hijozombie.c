#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
   
   pid_t hijo = fork();

   if(hijo==0){
        exit(EXIT_SUCCESS); //Creacion del zombie.
   } else {
    printf("Creando un zombie.\n");
    sleep(120); //Durante 2 minutos el hijo va a ser zombie.
   }

    return 0;
}