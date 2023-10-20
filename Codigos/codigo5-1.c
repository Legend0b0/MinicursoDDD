#include <stdio.h>
#include <stdlib.h>

int main ()
{ 
  int *v = NULL;
  
  v = (int*)malloc(5 * sizeof(int));

  for(int i = 0; i < 5; i++)
  {
    v[i] = i+1;
  }

  free(v);

  return 0;
}  
