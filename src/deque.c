#include "../include/deque.h"
#include <stdlib.h>

deque_t *create_deque() {
  deque_t *deque = malloc(sizeof(deque_t));
  if (!deque) {
    return NULL;
  }
  deque->front = deque->rear = NULL;
  deque->size = 0;
  return deque;
}

int is_empty(deque_t *deque) { return deque->size == 0; }

int get_size(deque_t *deque) { return deque->size; }

void push_front(deque_t *deque, void *data) {
  deque_node_t *node = malloc(sizeof(deque_node_t));
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

void push_back(deque_t *deque, void *data) {
  deque_node_t *node = malloc(sizeof(deque_node_t));
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

void *pop_front(deque_t *deque) {
  if (deque == NULL || deque->front == NULL) {
    return 0;
  }
  deque_node_t *temp = deque->front;
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

void *pop_back(deque_t *deque) {
  if (deque == NULL || deque->rear == NULL) {
    return 0;
  }
  deque_node_t *temp = deque->rear;
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

deque_node_t *front(deque_t *deque) {
  if (deque == NULL) {
    return NULL;
  }
  return deque->front;
}

deque_node_t *back(deque_t *deque) {
  if (deque == NULL) {
    return NULL;
  }
  return deque->rear;
}

void clear_deque(deque_t *deque) {
  if (deque == NULL) {
    return;
  }
  while (!is_empty(deque)) {
    pop_front(deque);
  }
}

void destroy_deque(deque_t *deque) {
  if (deque == NULL) {
    return;
  }
  clear_deque(deque);
  free(deque);
}
