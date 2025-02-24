#ifndef linked_list_h
#define linked_list_h

typedef struct ListNode {
  int data;
  struct ListNode* next;
} ListNode;

ListNode* create_node(const int data);
void destroy_list(ListNode** head);

void insert_at_beginning(ListNode** head, const int data);
void insert_at_end(ListNode** head, const int data);
void insert_at_position(ListNode** head, const int data, const int position);

void delete_at_beginning(ListNode** head);
void delete_at_end(ListNode** head);
void delete_at_position(ListNode** head, const int position);

ListNode* search(ListNode* head, const int key);
void update(ListNode* head, const int old_val, const int new_val);

void print_list(const ListNode* head);
int get_len(const ListNode* head);

#endif
