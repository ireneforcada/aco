/*  Programilla que hace que cada core diga hola (en paralelo) y te enseña qué CPU lo está diciendo*/
// gcc -o p -fopenmp parallelCPU_ex.c

#include <stdio.h>
#include <omp.h>

void main(){
  #pragma omp parallel
  {
    int ID = omp_get_thread_num(); //return the thread number
    printf("hello(%d)", ID);
    printf("world(%d)\n", ID);
  }
}


/* El orden en el que salen es un poco aleatorio porque están trabajando los
diferentes CPUs a la vez, pero si nos fijamos vemos que cada CPU dice primero hello y luego world. */
