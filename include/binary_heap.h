#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

typedef struct BinaryHeap {
  int *arr;
  int size;
  int capacity;
} BinaryHeap;

BinaryHeap *create_heap(const int capacity);
void push(BinaryHeap *heap, int value);
void heapify_up(BinaryHeap *heap, int index);
void heapify_down(BinaryHeap *heap, int index);
int pop(BinaryHeap *heap);
int peek(BinaryHeap *heap);
void destroy_heap(BinaryHeap *heap);
void print_heap(BinaryHeap *heap);
void heap_sort(BinaryHeap *heap);

#endif // !BINARY_HEAP_H
