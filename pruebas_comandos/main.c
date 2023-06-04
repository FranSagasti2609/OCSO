#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MEM_SIZE 100

int main(){
    //Uso de read.
    char memoria[MEM_SIZE];

    int max_char=10;
    int fichero;
    ssize_t caracteres_leidos;

    //Realizo apertura de archivo "FILE"
    fichero = open("archivo_leer", "O_RDONLY");
    
    //Compruebo lectura de fichero
    if (fichero = -1){
        perror("fallo lectura de fichero");
        exit(EXIT_FAILURE);
    }

    caracteres_leidos = read(fichero, memoria, max_char);
    /*
    if(caracteres_leidos < 0){
        perror("Error al hacer lectura.");
        exit(EXIT_FAILURE);
    } else {
        printf("Los primeros %d caracteres leídos son: %s\n", max_char,memoria);
    } */

    printf("Los primeros %d caracteres leídos son: %s\n", max_char,memoria);     


    return 0;
}