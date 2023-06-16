#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/*  Escribe un programa en C que cree dos procesos hijos y 
haga que el padre espere hasta que ambos hijos hayan terminado. 
Asegúrate de que ningún proceso hijo se convierta en un proceso zombie.*/

int main(){
    pid_t hijo1, hijo2;
    int est1, est2;
   
    //Primer hijo
     hijo1 = fork();
    if(hijo1==0){
        printf("Soy el primer hijo. Mi PID es: %d, el PID de mi padre es: %d \n",getpid(),getppid());
        exit(EXIT_SUCCESS);
    }

    //Segundo hijo
       hijo2 = fork();
    if(hijo2==0){
            waitpid(hijo1, &est1,0); //Espero al primer hijo para no superponer
            printf("Soy el segundo hijo. Mi PID es: %d, el PID de mi padre es: %d \n",getpid(),getppid());
            exit(EXIT_SUCCESS);
        }

    waitpid(hijo1, &est1,0);
    waitpid(hijo2, &est2,0);
    printf("Soy el padre. Finalizaron ambos hijos.\n");

    


    return 0;
}