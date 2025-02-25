
#include "../include/binary_tree.h" // Ensure this path is correct
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_insert() {
  TreeNode *root = NULL;

  root = insert_node(root, 10);
  root = insert_node(root, 5);
  root = insert_node(root, 15);

  assert(root != NULL);
  assert(root->data == 10);
  assert(root->left != NULL && root->left->data == 5);
  assert(root->right != NULL && root->right->data == 15);
}

void test_traversal() {
  TreeNode *root = NULL;
  root = insert_node(root, 10);
  root = insert_node(root, 5);
  root = insert_node(root, 15);

  printf("inorder traversal\n");
  inorder_traversal(root);
}

void test_bfs() {

  TreeNode *root = NULL;
  root = insert_node(root, 10);
  root = insert_node(root, 5);
  root = insert_node(root, 15);

  printf("bfs\n");
  bfs(root);
}

int main() {

  test_insert();
  test_traversal();
  test_bfs();

  return 0;
}
