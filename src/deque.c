#include "../include/deque.h"
#include <stdlib.h>

Deque *create_deque() {
  Deque *deque = malloc(sizeof(Deque));
  if (!deque) {
    return NULL;
  }
  deque->front = deque->rear = NULL;
  deque->size = 0;
  return deque;
}

int is_empty(Deque *deque) { return deque->size == 0; }

size_t get_size(Deque *deque) { return deque->size; }

void push_front(Deque *deque, void *data) {
  DequeNode *node = malloc(sizeof(DequeNode));
  if (node == NULL) {
    return;
  }
  node->data = data;
  node->next = NULL;
  node->prev = NULL;

  if (deque->front == NULL) {
    deque->front = deque->rear = node;
  } else {
    node->next = deque->front;
    deque->front->prev = node;
    deque->front = node;
  }

  deque->size++;
}

void push_back(Deque *deque, void *data) {
  DequeNode *node = malloc(sizeof(DequeNode));
  if (node == NULL) {
    return;
  }
  node->data = data;
  node->next = NULL;
  node->prev = NULL;

  if (deque->rear == NULL) {
    deque->rear = deque->front = node;
  } else {
    node->prev = deque->rear;
    deque->rear->next = node;
    deque->rear = node;
  }
  deque->size++;
}

void *pop_front(Deque *deque) {
  if (deque == NULL || deque->front == NULL) {
    return 0;
  }
  DequeNode *temp = deque->front;
  void *data = temp->data;
  deque->front = deque->front->next;

  if (deque->front == NULL) {
    deque->rear = NULL;
  } else {
    deque->front->prev = NULL;
  }
  free(temp);
  deque->size--;
  return data;
}

void *pop_back(Deque *deque) {
  if (deque == NULL || deque->rear == NULL) {
    return 0;
  }
  DequeNode *temp = deque->rear;
  deque->rear = deque->rear->prev;

  void *data = temp->data;
  if (deque->rear == NULL) {
    deque->front = NULL;
  } else {
    deque->rear->next = NULL;
  }
  free(temp);
  deque->size--;
  return data;
}

DequeNode *front(Deque *deque) {
  if (deque == NULL) {
    return NULL;
  }
  return deque->front;
}

DequeNode *back(Deque *deque) {
  if (deque == NULL) {
    return NULL;
  }
  return deque->rear;
}

void clear_deque(Deque *deque) {
  if (deque == NULL) {
    return;
  }
  while (!is_empty(deque)) {
    pop_front(deque);
  }
}

void destroy_deque(Deque *deque) {
  if (deque == NULL) {
    return;
  }
  clear_deque(deque);
  free(deque);
}
