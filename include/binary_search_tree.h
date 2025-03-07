#ifndef binary_search_tree_h
#define binary_search_tree_h

#include "binary_tree.h"

tree_node_t *create_bst_node(int data);
tree_node_t *insert_in_bst(tree_node_t *root, int data);
tree_node_t *search_in_bst(tree_node_t *root, int key);
tree_node_t *delete_node(tree_node_t *root, int key);
tree_node_t *get_successor(tree_node_t *root);
void free_bst(tree_node_t *root);

#endif // !binary_search_tree_h
