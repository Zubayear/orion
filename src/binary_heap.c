#include "../include/binary_heap.h"
#include <stdio.h>
#include <stdlib.h>

binary_heap_t *create_heap(const int capacity) {
  binary_heap_t *heap = (binary_heap_t *)malloc(sizeof(binary_heap_t));
  heap->arr = (int *)malloc(capacity * sizeof(int));
  heap->size = 0;
  heap->capacity = capacity;
  return heap;
}

void push(binary_heap_t *heap, int value) {
  if (heap->size == heap->capacity) {
    return;
  }

  heap->arr[heap->size] = value;
  heapify_up(heap, heap->size);
  heap->size++;
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void heapify_up(binary_heap_t *heap, int index) {
  int parent = (index - 1) / 2;
  while (index > 0 && heap->arr[parent] < heap->arr[index]) {
    swap(&heap->arr[parent], &heap->arr[index]);
    index = parent;
    parent = (index - 1) / 2;
  }
}

void heapify_down(binary_heap_t *heap, int index) {
  int left_child = 2 * index + 1;
  int right_child = 2 * index + 2;
  int largest = index;

  // compare parent with left and right child
  // swap parent with largest element
  if (left_child < heap->size && heap->arr[left_child] > heap->arr[largest]) {
    largest = left_child;
  }

  if (right_child < heap->size && heap->arr[right_child] > heap->arr[largest]) {
    largest = right_child;
  }

  if (largest != index) {
    swap(&heap->arr[largest], &heap->arr[index]);
    heapify_down(heap, largest);
  }
}

int pop(binary_heap_t *heap) {
  if (heap->size == 0) {
    return -1;
  }
  int root = heap->arr[0];
  heap->arr[0] = heap->arr[heap->size - 1];
  heap->size--;
  heapify_down(heap, 0);
  return root;
}

int peek(binary_heap_t *heap) {
  if (heap->size == 0) {
    return -1;
  }
  return heap->arr[0];
}

void destroy_heap(binary_heap_t *heap) {
  free(heap->arr);
  free(heap);
}

void print_heap(binary_heap_t *heap) {
  printf("Heap: ");
  for (int i = 0; i < heap->size; ++i) {
    printf("%d ", heap->arr[i]);
  }
  printf("\n");
}

void heap_sort(binary_heap_t *heap) {
  int size = heap->size;
  for (int i = 0; i < size; ++i) {
    printf("%d ", pop(heap));
  }
  printf("\n");
}
