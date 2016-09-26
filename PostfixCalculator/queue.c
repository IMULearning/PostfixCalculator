//
//  queue.c
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>

struct queue* newQueue() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->list = newLinkedList();
    return q;
}

struct node* peekQueue(struct queue* q) {
    if (q == NULL) {
        return NULL;
    }
    return elementAtIndex(q->list, sizeOfList(q->list) - 1);
}

struct node* dequeue(struct queue* q) {
    if (q == NULL) {
        return NULL;
    }
    return removeAtIndex(q->list, sizeOfList(q->list) - 1);
}

void enqueue(struct queue* q, struct node* n) {
    if (n == NULL || q == NULL) {
        return;
    }
    insertAtIndex(q->list, 0, n);
}

int sizeOfQueue(struct queue* q) {
    if (q == NULL || q->list == NULL) {
        return -1;
    }
    return sizeOfList(q->list);
}

void printQueue(struct queue* q) {
    if (q == NULL || q->list == NULL) {
        printf("<NULL>\n");
        return;
    }
    
    if (sizeOfQueue(q) == 0) {
        printf("<EMPTY>\n");
        return;
    }
    
    int width = sizeOfQueue(q) * 2;
    
    // print upper border
    int i = 0;
    for (i = 0; i < width; i++) {
        printf("-");
    }
    
    // print content
    printf("\n");
    struct node* cursor;
    for (cursor = q->list->head; cursor != NULL; cursor = cursor->next) {
        printf("%s ", asString(cursor));
    }
    printf("size=%d\n", sizeOfQueue(q));
    
    //print lower border
    for (i = 0; i < width; i++) {
        printf("-");
    }
    
    printf("\n\n");
}
