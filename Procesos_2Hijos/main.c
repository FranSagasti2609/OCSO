/* Consigna: Escribir un programa en C que cree dos procesos hijos y que, después de que ambos
hayan terminado, imprima en pantalla el mensaje "Ambos procesos hijos han terminado".
*/

#include <stdio.h>
#include <sys/wait.h> //Para usar wait y waitpid.
#include <stdlib.h> //Libreria para reconocer Exit_success y failure. Podria usar 0 y 1 respectivaente
#include <unistd.h> //libreria para funciones como "getpid"

int main(){
    pid_t hijo1, hijo2;
    int estado1, estado2;

    //Creacion del primer hijo.
    hijo1=fork();
    if(hijo1==0){
        printf("Soy el primer hijo, mi PID: %d. Mi padre tiene ID: %d\n",getpid(),getppid());
        exit(EXIT_SUCCESS); //Salgo del hijo con exito.
    } else if (hijo1 <0){ //un proceso no tiene identificador negativo.
        printf("Error al crear el hijo.\n");
        exit(EXIT_FAILURE);

    }

    //Creacion del segundo hijo.
    hijo2 = fork();
    if(hijo2==0){
        waitpid(hijo1, &estado1, 0); //espero a que hijo 1 termine.
        printf("Soy el segundo hijo, mi PID: %d. Mi padre tiene ID: %d\n",getpid(),getppid());
        printf("Lista de Procesos:\n");
        system("ps"); //mostramos procesos activos en el momento de ejecucion del hijo.
        exit(EXIT_SUCCESS);
    } else if(hijo2 < 0){
        printf("Error al crear el hijo.\n");
        exit(EXIT_FAILURE);
    }

    //Ahora hacemos esperar a los procesos hijos, poniendo en prueba waitpid.
    waitpid(hijo1, &estado1, 0);
    waitpid(hijo2, &estado2, 0);

    printf("Ambos procesos hijos han terminado.\n");
    

    return 0;
}