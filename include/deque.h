#ifndef deque_h
#define deque_h

typedef struct DequeNode {
  int data;
  struct DequeNode *prev, *next;
} DequeNode;

typedef struct Deque {
  struct DequeNode *front, *rear;
  size_t size;
} Deque;

Deque* create_deque();
int is_empty(Deque* deque);
size_t get_size(Deque* deque);
void push_front(Deque* deque, const int data);
void push_back(Deque* deque, const int data);
int pop_front(Deque* deque);
int pop_back(Deque* deque);
DequeNode* front(Deque* deque);
DequeNode* back(Deque* deque);
void clear_deque(Deque* deque);
void destroy_deque(Deque* deque);

#endif
