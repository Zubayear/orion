#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

typedef struct BinaryHeap {
  int *arr;
  int size;
  int capacity;
} binary_heap_t;

binary_heap_t *create_heap(const int capacity);
void push(binary_heap_t *heap, int value);
void heapify_up(binary_heap_t *heap, int index);
void heapify_down(binary_heap_t *heap, int index);
int pop(binary_heap_t *heap);
int peek(binary_heap_t *heap);
void destroy_heap(binary_heap_t *heap);
void print_heap(binary_heap_t *heap);
void heap_sort(binary_heap_t *heap);

#endif // !BINARY_HEAP_H
