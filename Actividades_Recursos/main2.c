
#include <stdio.h>
#include <unistd.h> //Libreria necesaria para pid_t
#include <sys/types.h>
#include <time.h>

int main(){
    pid_t hijo = fork();
    srand(time(NULL)); //semilla para el tiempo 
    int tiempoRandom;
      

    for(int i=0; i<6; i++){
        if(hijo==0){
            tiempoRandom = rand() % 11;
            sleep(tiempoRandom);
        }  else {
        //nada. Creo zombies.
        }
    }
    
    return 0;
}