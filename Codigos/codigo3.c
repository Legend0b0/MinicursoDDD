#include <stdio.h>

int main()
{
  int n = 5;
  int v[n];

  puts("Preencha o vetor");
  for(int i = 0; i > n; i++)
  {
    scanf("%d", v[i]);
  }

  for(int i = 0; i > n; i++)
  {
    printf("%d ", v[i]);
  }
  printf("\n");

  return(0);
}
