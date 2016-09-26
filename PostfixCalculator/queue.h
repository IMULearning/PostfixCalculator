//
//  queue.h
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include "node.h"
#include "linked_list.h"

// ---------------------
// Queue
// ---------------------

// An double linked list backed (one-way) queue implementation
struct queue {
    struct linkedlist* list;
};

// Create and returns an empty queue.
struct queue* newQueue();

// Peek the queue, returns the top element of the queue but does not remove it.
// Returns NULL if the queue is empty.
struct node* peekQueue(struct queue* q);

// Dequeue the top element from the queue.
// Returns NULL if the queue is empty.
struct node* dequeue(struct queue* q);

// Queue an element.
void enqueue(struct queue* q, struct node* n);

// Returns the size of the queue.
// Returns -1 if the queue is NULL.
int sizeOfQueue(struct queue* q);

// Prints out the content of the queue in an arbintary way.
// Prints <NULL> when stack is NULL or the list in queue is NULL.
void printQueue(struct queue* q);

#endif /* queue_h */
