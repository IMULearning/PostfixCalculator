//
//  linked_list.c
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#include "linked_list.h"
#include <stdlib.h>

struct linkedlist* newLinkedList() {
    struct linkedlist* list = (struct linkedlist*)malloc(sizeof(struct linkedlist));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int sizeOfList(struct linkedlist* list) {
    if (list == NULL) {
        return 0;
    }
    return list->size;
}

struct node* elementAtIndex(struct linkedlist* list, int index) {
    if (list == NULL) {
        return NULL;
    } else if (index < 0 || index > list->size - 1) {
        return NULL;
    }
    
    struct node* cursor = NULL;
    
    if (index < list->size / 2) {
        // more economical to start traversing from head
        int count = 0;
        for (cursor = list->head; cursor != NULL && count <= index; cursor = cursor->next) {
            count++;
        }
        cursor = cursor->prev;
    } else {
        // more economical to start traversing from
        int count = list->size - 1;
        for (cursor = list->tail; cursor != NULL && count > index; cursor = cursor->prev) {
            count--;
        }
    }
    
    return cursor;
}

// Inserting the same node (same address) twice into the list will have side effects.
// next and previous pointers will be messed up, hence, if the pointer already exists
// in the list chain, clone it and return a new address with the same value.
struct node* sanitizeNode(struct linkedlist* list, struct node* n) {
    struct node* cursor;
    for(cursor = list->head; cursor != NULL; cursor = cursor->next) {
        if (cursor == n) {
            return newNode(n->value, n->type);
        }
    }
    return n;
}

int insertAtIndex(struct linkedlist* list, int index, struct node* n) {
    // input check
    if (list == NULL) {
        return -1;
    } else if (index < 0 || index > list->size) {
        return -1;
    }
    
    // sanitize the node
    n = sanitizeNode(list, n);

    // insert node
    if (list->size == 0) {
        // special case, list is empty
        list->head = n;
        list->tail = n;
    } else {
        if (index == 0) {
            // we are inserting before the head
            list->head->prev = n;
            n->next = list->head;
            list->head = n;
        } else if (index == list->size) {
            // we are inserting after the tail
            list->tail->next = n;
            n->prev = list->tail;
            list->tail = n;
        } else {
            // we are inserting somewhere in between
            struct node* cursor = elementAtIndex(list, index);
            cursor = cursor->prev;
            n->next = cursor->next;
            cursor->next->prev = n;
            n->prev = cursor;
            cursor->next = n;
        }
    }
    
    // increment size
    list->size++;
    
    return 0;
}

struct node* removeAtIndex(struct linkedlist* list, int index) {
    // input check
    if (list == NULL) {
        return NULL;
    } else if (index < 0 || index > list->size - 1) {
        return NULL;
    }
    
    struct node* item = NULL;
    if (index == 0) {
        // we are removing the head.
        item = list->head;
        list->head = list->head->next;
        if (list->head != NULL) {
            list->head->prev->next = NULL;
            list->head->prev = NULL;
        } else {
            list->tail = NULL;
        }
    } else if (index == list->size - 1) {
        // we are removing the tail.
        item = list->tail;
        list->tail = list->tail->prev;
        if (list->tail != NULL) {
            list->tail->next->prev = NULL;
            list->tail->next = NULL;
        } else {
            list->head = NULL;
        }
    } else {
        // we are removing somewhere in between
        item = elementAtIndex(list, index);
        item->prev->next = item->next;
        item->next->prev = item->prev;
        item->next = NULL;
        item->prev = NULL;
    }
    
    // decrement size
    list->size--;
    
    return item;
}
