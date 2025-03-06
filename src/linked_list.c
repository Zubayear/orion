#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

list_node_t *create_node(const int data) {
  list_node_t *node = malloc(sizeof(list_node_t));
  if (!node) {
    return NULL;
  }
  node->data = data;
  node->next = NULL;
  return node;
}

void destroy_list(list_node_t **head) {
  list_node_t *current = *head;
  list_node_t *next_node;
  while (current != NULL) {
    next_node = current->next;
    free(current);
    current = next_node;
  }
  *head = NULL;
}

void insert_at_beginning(list_node_t **head, const int data) {
  list_node_t *node = create_node(data);
  if (node == NULL) {
    return;
  }
  node->next = *head;
  *head = node;
}

void insert_at_end(list_node_t **head, const int data) {
  list_node_t *node = create_node(data);
  if (node == NULL) {
    return;
  }

  if (*head == NULL) {
    *head = node;
    return;
  }

  list_node_t *current = *head;

  while (current->next != NULL) {
    current = current->next;
  }
  current->next = node;
}

void insert_at_position(list_node_t **head, const int data,
                        const int position) {
  if (position == 0) {
    insert_at_beginning(head, data);
    return;
  }

  int k = 0;
  list_node_t *traveler = *head;
  list_node_t *node = create_node(data);

  if (node == NULL) {
    return;
  }

  while (traveler != NULL && k < position - 1) {
    traveler = traveler->next;
    k++;
  }

  if (traveler == NULL) {
    insert_at_end(head, data);
  }

  node->next = traveler->next;
  traveler->next = node;
}

void delete_at_beginning(list_node_t **head) {
  if (*head == NULL) {
    return;
  }
  list_node_t *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void delete_at_end(list_node_t **head) {
  if (*head == NULL) {
    return;
  }

  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }

  list_node_t *traveler = *head;
  list_node_t *prev = NULL;

  while (traveler->next != NULL) {
    prev = traveler;
    traveler = traveler->next;
  }

  prev->next = NULL;
  free(traveler);
}

void delete_at_position(list_node_t **head, const int position) {
  if (*head == NULL) {
    return;
  }

  if (position == 0) {
    delete_at_beginning(head);
    return;
  }

  int k = 0;
  list_node_t *traveler = *head;
  list_node_t *prev = NULL;

  while (traveler != NULL && k < position - 1) {
    prev = traveler;
    traveler = traveler->next;
    k++;
  }

  if (traveler == NULL) {
    return;
  }

  prev->next = traveler->next;
  free(traveler);
}

list_node_t *search(list_node_t *head, const int key) {
  if (head == NULL) {
    return NULL;
  }

  list_node_t *traveler = head;
  while (traveler != NULL) {
    if (traveler->data == key) {
      return traveler;
    }
    traveler = traveler->next;
  }
  return NULL;
}

void update(list_node_t *head, const int old_val, const int new_val) {
  if (head == NULL) {
    return;
  }
  list_node_t *node = search(head, old_val);
  if (node == NULL) {
    return;
  }
  node->data = new_val;
}

void print_list(const list_node_t *head) {
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("\n");
}

int get_len(const list_node_t *head) {
  int result = 0;
  while (head != NULL) {
    result++;
    head = head->next;
  }
  return result;
}
