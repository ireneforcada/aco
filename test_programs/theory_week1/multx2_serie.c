/* Programilla que multiplica un cierto valor STARTVALUE x2 N veces de forma iterativa. La iteración es un recurso elegante pero no se puede paralelizar, siempre va en serie. */
// gcc -o p multx2_serie.c

#include <stdio.h>

int main(){
  int N=10;
  float STARTVALUE = 2.;
  float a[N];
  a[0] = STARTVALUE;
  printf("\n %.0f, ",a[0]);
  
  
  for(int i=1; i<N; i++){
    a[i] = 2*a[i-1];
    
    if (i==N-1){
      printf("%.0f \n\n ",a[i]);}
    else {
      printf("%.0f, ",a[i]);}
  }
}

	       
