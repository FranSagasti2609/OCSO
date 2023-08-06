#include <pthread.h>
#include <stdio.h>
#include <semaphore.h> //Libreria para uso de semaforos

static int cantidad = 10;
sem_t sem1; //Creacion del semaforo, luego se inicializa.

void *hilo1_routine(void *unused) {
  for (int i = 1; i < 100000; i++) {
  	sem_wait(&sem1);
    cantidad++;
    sem_post(&sem1);
  }
}

void *hilo2_routine(void *unused) {
  for (int i = 1; i < 100000; i++) {
  	sem_wait(&sem1);
    cantidad--;
    sem_post(&sem1);
  }
}

void errorExit(char *strerr) {
  perror(strerr);
  exit(1);
}

int main() {
  //Inicializamos el semaforo.
  sem_init (&sem1, 0, 1);
  pthread_t hilo1, hilo2;
	
  if (pthread_create(&hilo1, NULL, hilo1_routine, NULL) != 0)
    errorExit("hilo1 no se pudo crear");

  if (pthread_create(&hilo2, NULL, hilo2_routine, NULL) != 0)
    errorExit("hilo2 no se pudo crear");
	
  pthread_join(hilo1, NULL);
  pthread_join(hilo2, NULL);

  printf("Contar cantidad %d \n", cantidad);

  return 0;
}

