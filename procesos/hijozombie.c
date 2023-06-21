#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    //Creacion del hijo
    for(int i=0; i<30; i++){
        pid_t hijo = fork();
        if(hijo==0){
            printf("Fecha de hoy: ");
            sleep(2);
            system("date");
        }
    }
   

    return 0;
}