/*
 * This file is where you should implement your queue.  It already contains
 * skeletons of the functions you need to implement (along with documentation
 * for each function).  Feel free to implement any additional functions you
 * might need.  Also, don't forget to include your name and @oregonstate.edu
 * email address below.
 *
 * Name: Parker Choc
 * Email: chocp@oregonstate.edu
 */

#include <stdlib.h>

#include "queue.h"
#include "dynarray.h"

struct queue
{
  struct dynarray* array;
};

struct queue* queue_create()
{
    struct queue* q = malloc(sizeof(struct queue));
    q->array = dynarray_create();
    return q;
}

void queue_free(struct queue* queue)
{
    dynarray_free(queue->array);
    free(queue);
}

int queue_isempty(struct queue* queue)
{
  if(dynarray_size(queue->array) == 0)
    return 1;
  else
    return 0;
}

void queue_enqueue(struct queue* queue, void* val)
{
  addVal(queue->array, val);
}

void* queue_front(struct queue* queue)
{
  return dynarray_topVal(queue->array);
}

void* queue_dequeue(struct queue* queue)
{
  void* top = dynarray_topVal(queue->array);
  removeVal(queue->array);
  return top;
}