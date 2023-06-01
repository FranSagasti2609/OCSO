#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

    int main()
    {
        
        pid_t pid; //pid es el nombre de nuestro hijo. El tipo "pid_t" indica identificador de proceso.
        pid_t pid2 = fork(); //Creacion de segundo hijo
         
        if ((pid=fork()) == 0) //pid= fork() crea el proceso hijo. Luego lo comparamos, si retorna cero es el hijo
        { /* hijo */
        
        printf("Soy el primer hijo (%d, hijo de %d)\n", getpid(), getppid());
        //getpid nos brinda el identificador de un proceso. getppid el id de proceso del padre del proceso actual
        }
        else
        {   //Segundo hijo
            if(pid2==0){
             
             printf("Soy el segundo hijo (%d, hijo de %d)\n", getpid(),getppid());
            }   else {
                    /* padre */
                     printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
                }   
        }
        
        return 0;
    }
