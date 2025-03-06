#include "../include/binary_heap.h"
#include <stdio.h>
#include <stdlib.h>

BinaryHeap *create_heap(const int capacity) {
  BinaryHeap *heap = (BinaryHeap *)malloc(sizeof(BinaryHeap));
  heap->arr = (int *)malloc(capacity * sizeof(int));
  heap->size = 0;
  heap->capacity = capacity;
  return heap;
}

void push(BinaryHeap *heap, int value) {
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

void heapify_up(BinaryHeap *heap, int index) {
  int parent = (index - 1) / 2;
  while (index > 0 && heap->arr[parent] < heap->arr[index]) {
    swap(&heap->arr[parent], &heap->arr[index]);
    index = parent;
    parent = (index - 1) / 2;
  }
}

void heapify_down(BinaryHeap *heap, int index) {
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

int pop(BinaryHeap *heap) {
  if (heap->size == 0) {
    return -1;
  }
  int root = heap->arr[0];
  heap->arr[0] = heap->arr[heap->size - 1];
  heap->size--;
  heapify_down(heap, 0);
  return root;
}

int peek(BinaryHeap *heap) {
  if (heap->size == 0) {
    return -1;
  }
  return heap->arr[0];
}

void destroy_heap(BinaryHeap *heap) {
  free(heap->arr);
  free(heap);
}

void print_heap(BinaryHeap *heap) {
  printf("Heap: ");
  for (int i = 0; i < heap->size; ++i) {
    printf("%d ", heap->arr[i]);
  }
  printf("\n");
}

void heap_sort(BinaryHeap *heap) {
  int size = heap->size;
  for (int i = 0; i < size; ++i) {
    printf("%d ", pop(heap));
  }
  printf("\n");
}
