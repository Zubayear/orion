#include "../include/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode *create_new_node(const int data) {
  TreeNode *new_node = malloc(sizeof(TreeNode));
  if (new_node == NULL) {
    return NULL;
  }
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

TreeNode *insert_node(TreeNode *root, const int data) {
  if (root == NULL) {
    return create_new_node(data);
  }
  if (root->data > data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

void inorder_traversal(const TreeNode *root) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);
}

void free_tree(TreeNode *root) {
  if (root == NULL) {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}
