#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

/*
int main()
{
    int a = 2;
    int b = 4;
    int c = 6;
    int* a_ptr = &a;
    int* b_ptr = &b;
    int* c_ptr = &c;
    struct stack* s = stack_create();    
    printf("Stack empty: %d\n", stack_isempty(s));
    stack_push(s, a_ptr);
    printf("Stack empty: %d\n", stack_isempty(s));
    printf("Stack top: %d\n", *(int*)(stack_top(s)));
    stack_push(s, b_ptr);
    printf("Stack top: %d\n", *(int*)(stack_top(s)));
    stack_push(s, c_ptr);
    printf("Stack top: %d\n", *(int*)(stack_top(s)));
    printf("Popping... %d\n", *(int*)(stack_pop(s)));
    printf("Stack top: %d\n", *(int*)(stack_top(s)));

    stack_free(s);
    return 0;
}
*/


int main(int argc, char** argv) {
  int simtop, i, n = 16, k_pop = 4, k_push = 8;
  int* test_data;
  int** simstack;
  struct stack* s;

  /*
   * Create array of testing data.
   */
  test_data = malloc(n * sizeof(int));
  for (i = 0; i < n; i++) {
    test_data[i] = i * i;
  }

  /*
   * Create stack and push part of the testing data into it.  Simulate a stack
   * in the simstack array (with current top kept track of in simtop).
   */
  s = stack_create();
  simstack = malloc(n * sizeof(int*));
  simtop = 0;
  printf("== Pushing first %d of %d values onto stack.\n", k_push, n);
  for (i = 0; i < k_push; i++) {
    stack_push(s, &test_data[i]);
    simstack[simtop++] = &test_data[i];
  }

  /*
   * Pop a few of the values held in the stack and make sure they're the
   * correct values.
   */
  printf("\n== Popping some from stack: top / popped (expected)\n");
  for (i = 0; i < k_pop; i++) {
    int* expected = simstack[--simtop];
    int* top = stack_top(s);
    int* popped = stack_pop(s);
    if (top && popped) {
      printf("  - %4d / %4d (%4d)\n", *top, *popped, *expected);
    } else {
      printf("  - top (%p) or popped (%p) is NULL (expected: %4d)\n", top,
        popped, *expected);
    }
  }

  /*
   * Push remaining values into stack (and simulated stack).
   */
  printf("\n== Pushing remaining %d of %d values onto stack.\n", n - k_push, n);
  for (i = k_push; i < n; i++) {
    stack_push(s, &test_data[i]);
    simstack[simtop++] = &test_data[i];
  }

  /*
   * Pop the remaining values held in the stack and make sure they're the
   * correct values.
   */
  printf("\n== Popping rest from stack: top / popped (expected)\n");
  while (simtop > 0 && !stack_isempty(s)) {
    int* expected = simstack[--simtop];
    int* top = stack_top(s);
    int* popped = stack_pop(s);
    if (top && popped) {
      printf("  - %4d / %4d (%4d)\n", *top, *popped, *expected);
    } else {
      printf("  - top (%p) or popped (%p) is NULL (expected: %4d)\n", top,
        popped, *expected);
    }
  }

  /*
   * Make sure the stack is actually empty and also exhausted all actual data.
   */
  printf("\n== Is stack empty (expect 1)? %d\n", stack_isempty(s));
  printf("== Saw all test data (expect 1)? %d\n", simtop == 0);

  stack_free(s);
  free(test_data);
  free(simstack);

  return 0;
}