#include <stdio.h>
#include <unistd.h>
#include <pthread.h> //Libreria para trabajar con hilos
#include <sys/types.h>

void *holamundo(void *argumentos){
    printf("Hola mundo, soy el primer hilo!.\n");
}


int main(){
    
    pthread_t hilo1;
    pthread_create(&hilo1, NULL, holamundo, NULL);
    pthread_join(hilo1, NULL);
    printf("Fin\n");

    return 0;
}