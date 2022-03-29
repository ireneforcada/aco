/* Programilla que calcula el valor del número pi usando un sumatorio de términos (una de las defs de pi). Lo calcula en serie y en paralelo y compara los tiempos de ejecución. */
// gcc -o p -fopenmp pi_tarea.c -lm

#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <time.h>

float calc_a(int k){
  float a = 0.;
      for(int i=0; i<=k; i++){
	a = sqrt(12.)*pow(-1.0/3.0, k) / (2.*k+1.);
      }
      return a;
}

void main(){
  int k;
  int N=14; //Número de términos que metemos al sumatorio
  double pi_real=3.141592653589793238462;
  double pi=0.;
  
  double time=0.;
  clock_t begin, end;

  
  //Cálculo en serie usando iteraciones
  printf("\nCálculo en serie: \n");
  begin = clock();
  
  for (k=0; k<N; k++){
    pi += sqrt(12.)*pow(-1.0/3.0, k) / (2.*k+1.);  }
  
  
  end = clock();
  time = 1000.*(end - begin)/CLOCKS_PER_SEC; //ms  
  printf(" Pi=%.15f \n Terms=%d \n Error=%.15f \n Time=%E ms \n\n", pi, N, pi_real-pi, time);

  
  //Cálculo en paralelo 1
  printf("\nCálculo en paralelo 1: (usando un bucle) \n");
  pi=0.;
  float term[N];
  begin = clock();

  #pragma omp parallel
  {
    int ID = omp_get_thread_num();
    #pragma omp for
    for (k=0; k<N; k++){
      float a = 0.;
      for(int i=0; i<=k; i++){
	a = sqrt(12.)*pow(-1.0/3.0, k) / (2.*k+1.);
      }
      term[k] = a;
      printf(" Thread %d: term[%d]=%.15f \n", ID, k, term[k]);
    }  
  } // end of parallel section

  for (k=0; k<N; k++){
    pi += term[k];
  }
  
  end = clock();
  time = 1000.*(end - begin)/CLOCKS_PER_SEC; //ms
  printf("\n Pi=%.15f \n Terms=%d \n Error=%.15f \n Time=%E ms \n\n", pi, N, pi_real-pi, time);


  //Cálculo en paralelo 2 (usando una función externa)
  printf("\nCálculo en paralelo 2 (usando una función externa): \n");
  pi=0.;
  term[N];
  begin = clock();

  #pragma omp parallel
  {
    int ID = omp_get_thread_num();
    #pragma omp for
    for (k=0; k<N; k++){
      term[k] = calc_a(k);
      printf(" Thread %d: term[%d]=%.15f \n", ID, k, term[k]);
    }  
  } // end of parallel section

  for (k=0; k<N; k++){
    pi += term[k];
  }
  
  end = clock();
  time = 1000.*(end - begin)/CLOCKS_PER_SEC; //ms
  printf("\n Pi=%.15f \n Terms=%d \n Error=%.15f \n Time=%E ms \n\n", pi, N, pi_real-pi, time);


}


/*
-Valor real del numero pi = 3.141 592 653 589 793 238 462 ...
-Podemos cambiar el número de decimales que queremos que nos muestre en pantalla
-El error solo podemos calcularlo hasta un máximo de 18 decimales. Si queremos ser más finos tenemos que meterle más precisión al valor real de pi
-Los tiempos de ejecución en paralelo son mayores, ¿tiene que ver con el hecho de que no podemos hacer operaciones recursivas?
*/
