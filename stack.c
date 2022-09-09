/*
 * This file is where you should implement your stack.  It already contains
 * skeletons of the functions you need to implement (along with documentation
 * for each function).  Feel free to implement any additional functions you
 * might need.  Also, don't forget to include your name and @oregonstate.edu
 * email address below.
 *
 * Name: Parker Choc
 * Email: chocp@oregonstate.edu
 */

#include <stdlib.h>

#include "stack.h"
#include "list.h"

struct stack
{
  struct list* list;
};

struct stack* stack_create()
{
  struct stack* s = malloc(sizeof(struct stack));
  s->list = list_create();
  return s;
}

void stack_free(struct stack* stack)
{
  list_free(stack->list);
  free(stack);
}

int stack_isempty(struct stack* stack)
{
  return isEmpty(stack->list);
}

void stack_push(struct stack* stack, void* val)
{
  list_insert(stack->list, val);
}

void* stack_top(struct stack* stack)
{
  return topVal(stack->list);
}

void* stack_pop(struct stack* stack)
{
  void* top = topVal(stack->list);
  remove(stack->list);
  return top;
}