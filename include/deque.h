#ifndef deque_h
#define deque_h

typedef struct DequeNode {
  void* data;
  struct DequeNode *prev, *next;
} DequeNode;

typedef struct Deque {
  struct DequeNode *front, *rear;
  size_t size;
} Deque;

Deque* create_deque();
int is_empty(Deque* deque);
size_t get_size(Deque* deque);
void push_front(Deque* deque, void* data);
void push_back(Deque* deque, void* data);
void* pop_front(Deque* deque);
void* pop_back(Deque* deque);
DequeNode* front(Deque* deque);
DequeNode* back(Deque* deque);
void clear_deque(Deque* deque);
void destroy_deque(Deque* deque);

#endif
