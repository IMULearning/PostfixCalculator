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

void printStack(struct stack* s) {
    if (s == NULL || s->list == NULL) {
        printf("<NULL>\n");
        return;
    }
    
    if (sizeOfStack(s) == 0) {
        printf("<EMPTY>\n");
        return;
    }
    
    int width = sizeOfStack(s) * 2 + 1;
    
    // print upper border
    int i = 0;
    for (i = 0; i < width; i++) {
        printf("-");
    }
    
    // print content
    printf("\n|");
    struct node* cursor;
    for (cursor = s->list->head; cursor != NULL; cursor = cursor->next) {
        printf("%c ", cursor->value);
    }
    printf("size=%d\n", sizeOfStack(s));
    
    //print lower border
    for (i = 0; i < width; i++) {
        printf("-");
    }
    
    printf("\n\n");
}
