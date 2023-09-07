#include <stdio.h>
#include <unistd.h> //Acceso a funciones de Unix
#include <sys/types.h>
#include <stdlib.h>

int main(void) {
  pid_t pid, hijo2;
  hijo2 = fork(); //Creacion del segundo Hijo

  if ( (pid=fork()) == 0 ){ 
    /* hijo */
    execl("/bin/ls", "ls", "-l", NULL);
  
  } else { 
    if(hijo2==0){
    sleep(10);
    system("ps -ef");
      
    } else{ 
    /* padre */
    printf("Soy el padre (%d, hijo de %d)\n", getpid(), getppid());
    }
      

  }


  return 0;
}

