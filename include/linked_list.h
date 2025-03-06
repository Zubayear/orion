#ifndef linked_list_h
#define linked_list_h

typedef struct ListNode {
  int data;
  struct ListNode *next;
} list_node_t;

list_node_t *create_node(const int data);
void destroy_list(list_node_t **head);

void insert_at_beginning(list_node_t **head, const int data);
void insert_at_end(list_node_t **head, const int data);
void insert_at_position(list_node_t **head, const int data, const int position);

void delete_at_beginning(list_node_t **head);
void delete_at_end(list_node_t **head);
void delete_at_position(list_node_t **head, const int position);

list_node_t *search(list_node_t *head, const int key);
void update(list_node_t *head, const int old_val, const int new_val);

void print_list(const list_node_t *head);
int get_len(const list_node_t *head);

#endif
