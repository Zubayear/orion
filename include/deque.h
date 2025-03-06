#ifndef deque_h
#define deque_h

typedef struct DequeNode {
  void *data;
  struct DequeNode *prev, *next;
} deque_node_t;

typedef struct deque_t {
  deque_node_t *front, *rear;
  int size;
} deque_t;

deque_t *create_deque();
int is_empty(deque_t *deque);
int get_size(deque_t *deque);
void push_front(deque_t *deque, void *data);
void push_back(deque_t *deque, void *data);
void *pop_front(deque_t *deque);
void *pop_back(deque_t *deque);
deque_node_t *front(deque_t *deque);
deque_node_t *back(deque_t *deque);
void clear_deque(deque_t *deque);
void destroy_deque(deque_t *deque);

#endif
