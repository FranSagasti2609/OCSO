import time
import threading
import random

#variable a la cual sumaremos y restaremos 10 mil
var = 5

#creacion de mi semaforo
semaforo = threading.Semaphore(1)

#funcion que suma diez Mil a "var"
def sumarDiezMil():
  global var #con esta linea podemos modificar la variable global var.
  semaforo.acquire()
  for i in range(0,10000):
    var = var + 1
  semaforo.release()

#funcion que resta diez Mil a "var"
def restarDiezMil():
  global var
  semaforo.acquire()
  for i in range(0,10000):
    var = var - 1
  semaforo.release()

# creamos los hilos
hilo1 = threading.Thread(target=sumarDiezMil, name='Hilo 1')
hilo2 = threading.Thread(target=restarDiezMil, name='Hilo 2')

# ejecutamos los hilos
hilo1.start()
hilo2.start()

# esperamos a que terminen los hilos
hilo1.join()
hilo2.join()

print(f"El hilo principal sí espera por el resto de hilos. El valor de la variable al ejecutarlos es: {var}")