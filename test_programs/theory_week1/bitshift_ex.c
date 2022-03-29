/* Programilla que ilustra el uso del bitshift (>>,<<) */
// gcc -o p bitshift_example.c

#include <stdio.h>
int main() {
  int a=9;
  printf("a = %d \n",a);
  printf("a<<1 = %d \n", a<<1);
  printf("a<<2 = %d \n", a<<2);
  printf("a<<3 = %d \n", a<<3);
  printf("a>>1 = %d \n", a>>1);
  printf("a>>2 = %d \n", a>>2);
  printf("a>>3 = %d \n", a>>3);
  return 0;
}
