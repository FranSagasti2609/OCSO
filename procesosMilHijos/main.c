#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){

    srand(time(NULL)); //semilla para el tiempo
    int tiempo, estado;

    for(int i=0; i<1000; i++){
        pid_t hijo;
        hijo = fork();

        if(hijo==0){
            tiempo = rand() % 6; 
            printf("Soy el proceso hijo, mi PID es: %d. Voy a esperar %d segundos\n",getpid(),tiempo);
            sleep(tiempo); //espero el tiempo que se genero
            printf("Soy el proceso hijo. Ya termine mi espera. Mi PID es: %d\n",getpid());
            exit(0);
        }
    }
    
    for(int i=0; i<1000; i++){
        wait(&estado);
    } //espero la creacion de los hijos.

    printf("Finalizo la creacion de los hijos.\n");

    return 0;
}