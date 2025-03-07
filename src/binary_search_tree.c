#include "../include/binary_search_tree.h"
#include <stdlib.h>

tree_node_t *create_bst_node(int data) { return create_new_node(data); }

tree_node_t *insert_in_bst(tree_node_t *root, int data) {
  if (root == NULL) {
    return create_bst_node(data);
  }

  tree_node_t *t = root;
  tree_node_t *r = NULL;

  while (t != NULL) {
    r = t;
    if (t->data == data) {
      return root;
    }
    if (t->data < data) {
      t = t->right;
    } else {
      t = t->left;
    }
  }

  tree_node_t *new_node = create_bst_node(data);

  if (r->data < data) {
    r->right = new_node;
  } else {
    r->left = new_node;
  }

  return root;
}

tree_node_t *search_in_bst(tree_node_t *root, int key) {
  if (root == NULL) {
    return NULL;
  }

  if (root->data == key) {
    return root;
  }

  if (root->data > key) {
    return search_in_bst(root->left, key);
  } else {
    return search_in_bst(root->right, key);
  }
}

tree_node_t *delete_node(tree_node_t *root, int key) {
  if (root == NULL)
    return NULL;
  if (root->data < key) {
    root->right = delete_node(root->right, key);
  } else if (root->data > key) {
    root->left = delete_node(root->left, key);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left == NULL) {
      tree_node_t *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      tree_node_t *temp = root->left;
      free(root);
      return temp;
    } else {
      tree_node_t *successor = get_successor(root->right);
      root->data = successor->data;
      delete_node(root->right, successor->data);
    }
  }
  return root;
}

tree_node_t *get_successor(tree_node_t *root) {
  while (root->left != NULL) {
    root = root->left;
  }
  return root;
}

void free_bst(tree_node_t *root) {
  if (root == NULL) {
    return;
  }
  free_bst(root->left);
  free_bst(root->right);
  free(root);
}
