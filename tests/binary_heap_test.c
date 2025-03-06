#include "../include/binary_heap.h"
#include <assert.h>
#include <stdio.h>

void test_create_heap() {
  BinaryHeap *heap = create_heap(5);
  assert(heap != NULL);
  assert(heap->size == 0);
  assert(heap->capacity == 5);
  destroy_heap(heap);
  printf("test_create_heap PASSED\n");
}

void test_push() {
  BinaryHeap *heap = create_heap(10);
  push(heap, 10);
  push(heap, 5);
  push(heap, 15);
  push(heap, 2);

  assert(heap->size == 4);
  assert(heap->arr[0] == 15);

  destroy_heap(heap);
  printf("test_push PASSED\n");
}

void test_pop() {
  BinaryHeap *heap = create_heap(10);
  push(heap, 10);
  push(heap, 5);
  push(heap, 15);
  push(heap, 2);

  int max1 = pop(heap);
  assert(max1 == 15);
  assert(heap->size == 3);
  assert(heap->arr[0] == 10);

  int max2 = pop(heap);
  assert(max2 == 10);
  assert(heap->size == 2);
  assert(heap->arr[0] == 5);

  destroy_heap(heap);
  printf("test_pop PASSED\n");
}

void test_peek() {
  BinaryHeap *heap = create_heap(10);
  push(heap, 8);
  push(heap, 3);
  push(heap, 7);

  assert(peek(heap) == 8);

  destroy_heap(heap);
  printf("test_peek PASSED\n");
}

void test_destroy_heap() {
  BinaryHeap *heap = create_heap(5);
  push(heap, 10);
  push(heap, 20);

  destroy_heap(heap);

  printf("test_destroy_heap PASSED\n");
}

void test_heap_sort() {
  BinaryHeap *heap = create_heap(5);
  push(heap, 10);
  push(heap, 20);
  push(heap, 5);
  push(heap, 4);
  push(heap, 40);

  printf("Heap sort: ");
  heap_sort(heap);
  destroy_heap(heap);
}

int main() {
  test_create_heap();
  test_push();
  test_pop();
  test_peek();
  test_destroy_heap();
  test_heap_sort();

  printf("\nAll BinaryHeap tests PASSED successfully!\n");
  return 0;
}
