#include "../include/binary_search_tree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_bst_creation() {
  tree_node_t *root = NULL;
  root = insert_in_bst(root, 10);
  root = insert_in_bst(root, 20);
  root = insert_in_bst(root, 30);
  root = insert_in_bst(root, 40);
  root = insert_in_bst(root, 50);
  root = insert_in_bst(root, 60);

  tree_node_t *found_node = search_in_bst(root, 20);
  assert(found_node != NULL && found_node->data == 20);

  printf("Inorder Traversal: ");
  inorder_traversal(root);
  printf("\n");

  printf("✅ test_bst_creation PASSED\n");
  free_bst(root);
}

void test_bst_delete() {
  tree_node_t *root = NULL;
  root = insert_in_bst(root, 50);
  root = insert_in_bst(root, 30);
  root = insert_in_bst(root, 70);
  root = insert_in_bst(root, 20);
  root = insert_in_bst(root, 40);
  root = insert_in_bst(root, 60);
  root = insert_in_bst(root, 80);

  printf("BST before deletion:\n");
  inorder_traversal(root);
  printf("\n");

  root = delete_node(root, 20); // Leaf node
  root = delete_node(root, 30); // Node with one child
  root = delete_node(root, 50); // Node with two children
  assert(search_in_bst(root, 50) == NULL);

  printf("BST after deletion:\n");
  inorder_traversal(root);
  printf("\n");

  free_bst(root); // Clean up memory
  printf("test_bst_delete passed\n");
}

int main() {
  test_bst_creation();
  test_bst_delete();
  return 0;
}
