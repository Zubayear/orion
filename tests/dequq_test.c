
#include "../include/deque.h"
#include <assert.h>
#include <stdio.h>
#include <wchar.h>

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
  push_front(deque, 10);
  assert(get_size(deque) == 1);
  assert(front(deque)->data == 10);
  assert(back(deque)->data == 10);
  push_front(deque, 20);
  assert(get_size(deque) == 2);
  assert(front(deque)->data == 20);
  assert(back(deque)->data == 10);
  destroy_deque(deque);
  printf("test_push_front PASSED\n");
}

void test_push_back() {
  Deque *deque = create_deque();
  push_back(deque, 5);
  assert(get_size(deque) == 1);
  assert(front(deque)->data == 5);
  assert(back(deque)->data == 5);
  push_back(deque, 15);
  assert(get_size(deque) == 2);
  assert(front(deque)->data == 5);
  assert(back(deque)->data == 15);
  destroy_deque(deque);
  printf("test_push_back PASSED\n");
}

void test_pop_front() {
  Deque *deque = create_deque();
  push_front(deque, 1);
  push_front(deque, 2);
  push_front(deque, 3);
  assert(get_size(deque) == 3);
  assert(pop_front(deque) == 3);
  assert(get_size(deque) == 2);
  assert(front(deque)->data == 2);
  destroy_deque(deque);
  printf("test_pop_front PASSED\n");
}

void test_pop_back() {
  Deque *deque = create_deque();
  push_back(deque, 100);
  push_back(deque, 200);
  push_back(deque, 300);
  assert(get_size(deque) == 3);
  assert(pop_back(deque) == 1);
  assert(get_size(deque) == 2);
  assert(back(deque)->data == 200);
  destroy_deque(deque);
  printf("test_pop_back PASSED\n");
}

void test_front_back() {
  Deque *deque = create_deque();
  push_front(deque, 42);
  assert(front(deque)->data == 42);
  assert(back(deque)->data == 42);
  push_back(deque, 99);
  assert(front(deque)->data == 42);
  assert(back(deque)->data == 99);
  destroy_deque(deque);
  printf("test_front_back PASSED\n");
}

void test_clear_deque() {
  Deque *deque = create_deque();
  push_front(deque, 1);
  push_front(deque, 2);
  push_front(deque, 3);
  assert(get_size(deque) == 3);
  clear_deque(deque);
  assert(get_size(deque) == 0);
  assert(is_empty(deque) == 1);
  destroy_deque(deque);
  printf("test_clear_deque PASSED\n");
}

void test_destroy_deque() {
  Deque *deque = create_deque();
  push_front(deque, 10);
  push_front(deque, 20);
  destroy_deque(deque);
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
