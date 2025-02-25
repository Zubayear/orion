#ifndef binary_tree_h
#define binary_tree_h

typedef struct TreeNode {
  int data;
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode ;

TreeNode* create_new_node(const int data);
TreeNode* insert_node(TreeNode* root, const int data);
void inorder_traversal(const TreeNode* root);
void bfs(TreeNode* root);
void free_tree(TreeNode* root);

#endif
