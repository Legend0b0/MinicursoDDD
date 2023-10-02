#include <stdio.h>
#include <stdlib.h>

struct Pile
{
  int v[10];
  int size;
  int top;
};

struct Pile* start_pile()
{
  struct Pile *pile = (struct Pile*)malloc(sizeof(struct Pile));
  pile->top = -1;
  pile->size = 10;

  return(pile);
}

int is_empty(struct Pile *pile)
{
  return(pile->top == -1);
}

int is_full(struct Pile *pile)
{
  return((pile->top) == (pile->size - 1));
}

void stack(struct Pile *pile, int value)
{
  if(!(pile->top == (pile->size - 1)))
  {
    pile->top++;
    pile->v[pile->top] = value;
  }
  else
  {
    printf("Pilha Cheia\n");
  }
}

void unstack(struct Pile *pile)
{
  if(!is_empty(pile))
  {
    pile->v[pile->top] = 0;
    pile->top--;
  }
  else
  {
    printf("Pilha Vazia\n");
  }
}

int main()
{
  struct Pile *pile = start_pile();

  for(int i = 0; i < 10; i++)
  {
    stack(pile, i*2);
  }

  for(int i = 0; i < 10; i++)
  {
    unstack(pile);
  }

  free(pile);
  return(0);
}
