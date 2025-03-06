#ifndef binary_tree_h
#define binary_tree_h

typedef struct TreeNode {
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} tree_node_t;

tree_node_t *create_new_node(const int data);
tree_node_t *insert_node(tree_node_t *root, const int data);
void inorder_traversal(const tree_node_t *root);
void bfs(tree_node_t *root);
void free_tree(tree_node_t *root);

#endif
