/*
    mi pequena implementacion de deque
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "deque.h"

// inicializa un deque vacio
Deque* createDeque() {
    Deque* deque = malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

// destruye un deque
void destroyDeque(Deque* deque) {
    while (deque->front != NULL) {
        Node* temp = deque->front;
        deque->front = deque->front->next;
        free(temp);
    }
    free(deque);
}

// si esta vacio
bool isEmpty(Deque* deque) {
    return deque->front == NULL;
}


// inserta un elemento al frente del deque
void pushFront(Deque* deque, void* data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = deque->front;

    if (!isEmpty(deque)) {
        deque->front->prev = node;
    } else {
        deque->rear = node;
    }

    deque->front = node;
}

// inserta un elemento al final del deque
void pushBack(Deque* deque, void* data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->prev = deque->rear;
    node->next = NULL;

    if (!isEmpty(deque)) {
        deque->rear->next = node;
    } else {
        deque->front = node;
    }

    deque->rear = node;
}

// elimina el elemento al frente del deque
void* popFront(Deque* deque) {
    if (isEmpty(deque)) {
        return NULL;
    }

    Node* node = deque->front;
    void* data = node->data;

    deque->front = deque->front->next;
    if (deque->front != NULL) {
        deque->front->prev = NULL;
    } else {
        deque->rear = NULL;
    }

    free(node);
    return data;
}

// elimina el elemento al final del deque
void* popBack(Deque* deque) {
    if (isEmpty(deque)) {
        return NULL;
    }

    Node* node = deque->rear;
    void* data = node->data;

    deque->rear = deque->rear->prev;
    if (deque->rear != NULL) {
        deque->rear->next = NULL;
    } else {
        deque->front = NULL;
    }

    free(node);
    return data;
}

// busca si existe un elemento en el deque
bool find(Deque* deque, void* data, int size) {
    Node* node = deque->front;
    while (node != NULL) {
        if (memcmp(node->data, data, size) == 0) {
            return true;
        }
        node = node->next;
    }
    return false;
}