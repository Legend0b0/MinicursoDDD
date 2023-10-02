#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  int data;
  struct Node *next; 
};

struct List
{
  struct Node *head;
};

struct List* create_list()
{
  struct List *list = (struct List*)malloc(sizeof(struct List));
  if(list != NULL)
  {
    list->head = NULL;
    return(list);
  }
  else
  {
    printf("\nError Create List\n");
    free(list);
    return(NULL);
  }
}

struct Node* create_node()
{
  struct Node *node = (struct Node*)malloc(sizeof(struct Node));

  if(node != NULL)
  {
    node->next = NULL;
    return(node);
  }
  else
  {
    printf("\nError Create Node\n");
    free(node);
    return(NULL);
  }
}

int is_empty(struct List *list)
{
  return(list->head == NULL);
}

void insert_begin(struct List *list, int value)
{
  struct Node *aux = create_node();

  aux->data = value;

  aux->next = list->head;
  list->head = aux;
}

void insert_end(struct List *list, int value)
{ 
  if(is_empty(list))
  {
    list->head = create_node();

    struct Node *aux = list->head;
    
    aux->data = value;
  }
  else
  {
    struct Node *aux = list->head;
    while(aux->next != NULL)
      {
        aux = aux->next;
      }

    aux->next = create_node();

    if(aux->next != NULL)
      {
        aux = aux->next;

        aux->data = value;

        aux->next = NULL;
      }
    else
    {
      printf("\nError Malloc\n");
    }
  }
}

void delete_begin(struct List *list)
{
  if(!is_empty(list))
  {
    struct Node *aux = list->head;
    list->head = aux->next;
    free(aux);
  }
  else
  {
    printf("\nLista Vazia\n");
  }
}

void delete_end(struct List *list)
{
  if(!is_empty(list))
  {
    struct Node *aux = list->head;
    
    if(aux->next != NULL)
    {
      while(aux->next->next != NULL)
      {
        aux = aux->next;
      }
      free(aux->next);
      aux->next = NULL;
    }
    else
    {
      free(aux);
      list->head = NULL;
    }
  }
  else
  {
    printf("\nLista Vazia\n");
    return;
  }

}

void destroy_node(struct Node *head)
{
  if(head->next != NULL)
  {
    destroy_node(head->next);
  }
  else
  {
    return;
  }
  
  free(head->next);

  return;
}

void destroy_list(struct List *list)
{
  if(!is_empty(list))
  {
    destroy_node(list->head);
  }

  free(list->head);

  free(list);
}

int
main()
{
  struct List *list = create_list();
 
  for(int i = 1; i <= 3; i++)
  {
    insert_begin(list, i);
  }
  for(int i = 4; i <= 6; i++)
  {
    insert_end(list, i);
  }

  for(int i = 1; i <= 3; i++)
  {
    delete_begin(list);
  }
  for(int i = 4; i <= 6; i++)
  {
    delete_end(list);
  }

  destroy_list(list);
  
  return(0);
}
