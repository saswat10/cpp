// increase the size of array
#include <stdio.h>
#include <stdlib.h>

int main(){
  int *p, *q;

  p = (int *)malloc(5*sizeof(int));
  p[0] = 3;
  p[1] = 5;
  p[2] = 7;
  p[3] = 9;
  p[4] = 11;
  
  q = (int *)malloc(10*sizeof(int));

  for(int i=0; i<5; i++)
    q[i] = p[i];

  free(p); // delete the prev array
  p=q;//p points to null
  q= NULL;

  for(int i = 0; i< 11; i++)
    printf("%d \t" , p[i]);

  return 0;

}