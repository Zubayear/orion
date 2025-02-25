#include "../include/deque.h" // Include your deque header file
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_create_deque() {
  Deque *deque = create_deque();
  assert(deque != NULL);
  assert(is_empty(deque) == 1);
  assert(get_size(deque) == 0);
  destroy_deque(deque);
  printf("test_create_deque PASSED\n");
}

void test_push_front() {
  Deque *deque = create_deque();
  int *val1 = malloc(sizeof(int));
  int *val2 = malloc(sizeof(int));
  *val1 = 10;
  *val2 = 20;

  push_front(deque, val1);
  assert(get_size(deque) == 1);
  assert(*(int *)(front(deque)->data) == 10);
  assert(*(int *)(back(deque)->data) == 10);

  push_front(deque, val2);
  assert(get_size(deque) == 2);
  assert(*(int *)(front(deque)->data) == 20);
  assert(*(int *)(back(deque)->data) == 10);

  destroy_deque(deque);
  printf("test_push_front PASSED\n");
}

void test_push_back() {
  Deque *deque = create_deque();
  int *val1 = malloc(sizeof(int));
  int *val2 = malloc(sizeof(int));
  *val1 = 5;
  *val2 = 15;

  push_back(deque, val1);
  assert(get_size(deque) == 1);
  assert(*(int *)(front(deque)->data) == 5);
  assert(*(int *)(back(deque)->data) == 5);

  push_back(deque, val2);
  assert(get_size(deque) == 2);
  assert(*(int *)(front(deque)->data) == 5);
  assert(*(int *)(back(deque)->data) == 15);

  destroy_deque(deque);
  printf("test_push_back PASSED\n");
}

void test_pop_front() {
  Deque *deque = create_deque();
  int *val1 = malloc(sizeof(int));
  int *val2 = malloc(sizeof(int));
  *val1 = 1;
  *val2 = 2;

  push_front(deque, val1);
  push_front(deque, val2);
  assert(get_size(deque) == 2);

  int *popped = (int *)pop_front(deque);
  assert(*popped == 2);
  free(popped);

  assert(get_size(deque) == 1);
  assert(*(int *)(front(deque)->data) == 1);

  destroy_deque(deque);
  printf("test_pop_front PASSED\n");
}

void test_pop_back() {
  Deque *deque = create_deque();
  int *val1 = malloc(sizeof(int));
  int *val2 = malloc(sizeof(int));
  *val1 = 100;
  *val2 = 200;

  push_back(deque, val1);
  push_back(deque, val2);
  assert(get_size(deque) == 2);

  int *popped = (int *)pop_back(deque);
  assert(*popped == 200);
  free(popped);

  assert(get_size(deque) == 1);
  assert(*(int *)(back(deque)->data) == 100);

  destroy_deque(deque);
  printf("test_pop_back PASSED\n");
}

void test_front_back() {
  Deque *deque = create_deque();
  int *val1 = malloc(sizeof(int));
  int *val2 = malloc(sizeof(int));
  *val1 = 42;
  *val2 = 99;

  push_front(deque, val1);
  assert(*(int *)(front(deque)->data) == 42);
  assert(*(int *)(back(deque)->data) == 42);

  push_back(deque, val2);
  assert(*(int *)(front(deque)->data) == 42);
  assert(*(int *)(back(deque)->data) == 99);

  destroy_deque(deque);
  printf("test_front_back PASSED\n");
}

void test_clear_deque() {
  Deque *deque = create_deque();
  int *val1 = malloc(sizeof(int));
  int *val2 = malloc(sizeof(int));
  *val1 = 1;
  *val2 = 2;

  push_front(deque, val1);
  push_front(deque, val2);
  assert(get_size(deque) == 2);

  clear_deque(deque); // Should free memory inside deque
  assert(get_size(deque) == 0);
  assert(is_empty(deque) == 1);

  destroy_deque(deque);
  printf("test_clear_deque PASSED\n");
}

void test_destroy_deque() {
  Deque *deque = create_deque();
  int *val1 = malloc(sizeof(int));
  *val1 = 10;
  push_front(deque, val1);
  destroy_deque(deque); // Should free all memory
  printf("test_destroy_deque PASSED\n");
}

int main() {
  test_create_deque();
  test_push_front();
  test_push_back();
  test_pop_front();
  test_pop_back();
  test_front_back();
  test_clear_deque();
  test_destroy_deque();

  printf("\nAll Deque tests PASSED successfully!\n");
  return 0;
}
