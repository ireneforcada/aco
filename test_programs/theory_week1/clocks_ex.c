/* Programilla que eleva al cubo un cierto valor, a, usando 3 métodos distintos y comparando el tiempo de ejecución. El más lento es usar una libreria externa, puesto que tiene que cargar más cosas que las que luego realmente usa */
// gcc -o p  clocks_ex.c -lm

#include <stdio.h>
#include <math.h>
#include <time.h>

float cubo(float x){
  float res = x*x*x;
  return res;
}

void main(){
  int N = 3;
  float a = 2.;
  float res;
  double time=0.;
  clock_t begin, end;
  
  // Método 1: cálculo directo
  
  begin = clock();
  res = a*a*a;
  end = clock();
  time = 1000.*(end - begin)/CLOCKS_PER_SEC; //ms
  
  printf("\nCálculo de a = %.0f al cubo: \n\n", a);
  printf("Método 1: %.0f*%.0f*%.0f = %.1f",a,a,a,res);
  printf("\t \t Time=%E ms \n",time);

  // Método 2: cálculo con la libreria math.h
  
  begin = clock();
  res = pow(a,N);
  end = clock();
  time = 1000.*(end - begin)/CLOCKS_PER_SEC; //ms
  
  printf("Método 2: pow(%.0f,3) = %.1f",a,res);
  printf("\t Time=%E ms \n",time);

  // Método 3: cálculo mediante la definición de una función
  
  begin = clock();
  res = cubo(a);
  end = clock();
  time = 1000.*(end - begin)/CLOCKS_PER_SEC; //ms
  
  printf("Método 3: def_function(%.0f) = %.1f",a,res);
  printf("\t Time=%E ms \n",time);
}
