//
//  stack.h
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include "linked_list.h"
#include "node.h"

// ---------------------
// Stack
// ---------------------

// An double linked list backed stack implementation
struct stack {
    struct linkedlist* list;
};

// Create and returns an empty stack.
struct stack* newStack();

// Peep the stack, returns the top element on the stack but does not remove it.
// Returns NULL if the stack is empty.
struct node* peekStack(struct stack* s);

// Pop the top element off the stack.
// Returns NULL if the stack is empty.
struct node* pop(struct stack* s);

// Push element onto the stack.
void push(struct stack* s, struct node* n);

// Returns the size of the stack.
// Returns -1 if the stack is NULL.
int sizeOfStack(struct stack* s);

#endif /* stack_h */
