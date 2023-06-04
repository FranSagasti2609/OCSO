
#include <stdio.h>
#include <unistd.h> //Libreria necesaria para pid_t
#include <sys/types.h>
#include <time.h>

int main(){
    pid_t hijo;
    srand(time(NULL)); //semilla para el tiempo 
    int tiempoRandom;
      

    for(int i=0; i<6; i++){
        hijo = fork(); //Creacion de hijo
    
        if(hijo==0){
            tiempoRandom = rand() % 11;
            sleep(tiempoRandom);
        }  else {
            printf("Listado de directorio finalizado.\n");
        }
    }
    
    return 0;
}