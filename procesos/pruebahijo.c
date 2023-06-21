#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    //Prueba hijo huerfano
    pid_t hijo = fork();
    while(1){
        if(hijo==0){
            printf("Soy el hijo. PID: %d - PPID: %d\n", getpid(),getppid());
            sleep(2);
        } else{
            //nada
        }

    }

    return 0;
}