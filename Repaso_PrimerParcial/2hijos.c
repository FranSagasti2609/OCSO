#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/*  Escribe un programa en C que cree dos procesos hijos y 
haga que el padre espere hasta que ambos hijos hayan terminado. 
Asegúrate de que ningún proceso hijo se convierta en un proceso zombie.*/

int main(){
    pid_t hijo1, hijo2;

   
    //Primer hijo
    hijo1 = fork();
    if(hijo1==0){
        printf("Soy el primer hijo. Mi PID es: %d, el PID de mi padre es: %d \n",getpid(),getppid());
    } else{
        //Estoy en el padre (Main)
        waitpid(hijo1, NULL,0);

        hijo2 = fork();
        if(hijo2==0){
            printf("Soy el segundo hijo. Mi PID es: %d, el PID de mi padre es: %d \n",getpid(),getppid());
        } else {
            //Volvemos al padre. 
            waitpid(hijo2, NULL,0); //Espero al segundo hijo
            printf("Soy el padre. Finalizaron ambos hijos.\n");  
        }

        
    }
    



    


    return 0;
}