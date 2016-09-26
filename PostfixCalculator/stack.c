//
//  stack.c
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#include "stack.h"
#include <stdlib.h>

struct stack* newStack() {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->list = newLinkedList();
    return s;
}

struct node* peekStack(struct stack* s) {
    if (s == NULL) {
        return NULL;
    }
    return elementAtIndex(s->list, 0);
}

struct node* pop(struct stack* s) {
    if (s == NULL) {
        return NULL;
    }
    return removeAtIndex(s->list, 0);
}

void push(struct stack* s, struct node* n) {
    if (n == NULL || s == NULL) {
        return;
    }
    insertAtIndex(s->list, 0, n);
}

int sizeOfStack(struct stack* s) {
    if (s == NULL || s->list == NULL) {
        return -1;
    }
    return sizeOfList(s->list);
}
