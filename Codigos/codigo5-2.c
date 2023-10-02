#include <stdio.h>
#include <stdlib.h>

int main()
{ 
  char *c = NULL;
  
  c = (char*)malloc(5 * sizeof(char));
  c = "abcde";
  
  printf("%s\n", c);
  
  return(0);
}  
