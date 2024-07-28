#ifndef DEQUE_H
#define DEQUE_H

typedef struct Node {
    void* data;
    struct Node* prev;
    struct Node* next; 
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Deque;

Deque* createDeque();
void destroyDeque(Deque* deque);
bool isEmpty(Deque* deque);
void pushFront(Deque* deque, void* data);
void pushBack(Deque* deque, void* data);
void* popFront(Deque* deque);
void* popBack(Deque* deque);
bool find(Deque* deque, void* data, int size);

#endif