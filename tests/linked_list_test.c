#include "../include/linked_list.h"
#include <assert.h>
#include <stdlib.h>

void test_search() {
  list_node_t *head = NULL;
  insert_at_end(&head, 1);
  insert_at_end(&head, 2);
  insert_at_end(&head, 3);

  list_node_t *node = search(head, 2);
  assert(node != NULL && node->data == 2);

  node = search(head, 4);
  assert(node == NULL);
}

int main() {
  test_search();
  return 0;
}
