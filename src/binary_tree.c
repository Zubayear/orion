#include "../include/binary_tree.h"
#include "../include/deque.h"
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
  TreeNode *node = create_new_node(data);
  if (root == NULL) {
    return node;
  }

  Deque *queue = create_deque();
  push_front(queue, root);

  while (!is_empty(queue)) {
    TreeNode *current = pop_back(queue);
    if (current->left == NULL) {
      current->left = node;
      break;
    } else {
      push_front(queue, current->left);
    }

    if (current->right == NULL) {
      current->right = node;
      break;
    } else {
      push_front(queue, current->right);
    }
  }

  clear_deque(queue);
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

void bfs(TreeNode *root) {
  if (root == NULL) {
    return;
  }

  Deque *queue = create_deque();
  push_front(queue, root);

  while (!is_empty(queue)) {
    TreeNode *node = (TreeNode *)pop_back(queue);
    printf("%d ", node->data);
    if (node->left != NULL) {
      push_front(queue, node->left);
    }
    if (node->right != NULL) {
      push_front(queue, node->right);
    }
  }
}
