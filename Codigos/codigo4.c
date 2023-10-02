#include <stdio.h>

int sum(int a, int b)
{
  return(a + b);
}

int sumDobrada(int *a, int *b)
{
  *a *= 2;
  *b *= 2;

  return(*a + *b);
}

int main()
{
  int n1 = 3.0, n2 = 5.0, res = 0;
  
  res = sum(n1, n2);
  printf("Resultado = %d\n",res);
  
  res = sumDobrada(&n1, &n2);
  printf("Resultado = %d\n",res);

  return(0);
}
