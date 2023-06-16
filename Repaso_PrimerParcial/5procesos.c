/*Crea un programa en C que simule una cadena de procesos en la que cada proceso 
crea un nuevo proceso y luego termina, para un total de 5 procesos 
en la cadena (incluido el proceso original). 
Cada proceso debe imprimir su PID y el PID de su proceso padre.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t p1,p2,p3,p4,p5;
    //Creo primer proceso
    p1 = fork();
    if (p1==0){
        printf("Soy el primer proceso. PID: %d - PPID: %d\n",getpid(),getppid());
        //Segundo proceso
        p2=fork();
        if(p2==0){
             printf("Soy el segundo proceso. PID: %d - PPID: %d\n",getpid(),getppid());
             p3=fork();
             if(p3==0){
                printf("Soy el tercer proceso. PID: %d - PPID: %d\n",getpid(),getppid());
                p4=fork();
                if(p4==0){
                    printf("Soy el cuarto proceso. PID: %d - PPID: %d\n",getpid(),getppid());
                    p5=fork();
                    if(p5==0){
                        printf("Soy el quinto proceso. PID: %d - PPID: %d\n",getpid(),getppid());

                    }
                }
             }
        }
        exit(1); //Salgo con exito del hijo. Evitar repeticiones en print.
    }
    waitpid(p1, NULL,0);
    waitpid(p2, NULL,0);
    waitpid(p3, NULL,0);
    waitpid(p4, NULL,0);
    waitpid(p5, NULL,0);
    printf("Finalizacion de programa.\n");

    return 0;
}