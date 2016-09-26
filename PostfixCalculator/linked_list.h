//
//  linked_list.h
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include "node.h"

// ---------------------
// Linked List
// ---------------------

// Linedlist implementation
struct linkedlist {
    int size;
    struct node* head;
    struct node* tail;
};

// Create a new linked list
// Returns the newly created empty linked list
struct linkedlist* newLinkedList();

// Get the size of a linked list
// Returns the size of the linked list, if the list is NULL, returns 0
int sizeOfList(struct linkedlist* list);

// Get the node element at specified index.
// Valid index ranges from 0 (head) to size-1 (tail)
// If invalid index is specified, returns NULL.
struct node* elementAtIndex(struct linkedlist* list, int index);

// Add a char element to the linked list at specified index
// Valid index ranges from 0 (insert as head) to size of the list (insert as tail)
// Invalid index or failed insertion will receive -1 return.
// Successful insertion will receive 0 return
int insertAtIndex(struct linkedlist* list, int index, struct node* n);

// Remove the node element from the linked list at the specified index
// Valid index ranges from 0 (remove head) to size-1 (remove tail);
// Invalid index or failed removal will receive -1 return.
// Successful removal will receive 0 return.
// Note that remove detaches the node from the list, but it does not free its memory.
struct node* removeAtIndex(struct linkedlist* list, int index);

// Prints the specified list in arbitary format.
// If the list is NULL, <NULL> will be printed.
void print(struct linkedlist* list);

// Prints the specified list in reversed order in arbitary format.
// If the list is NULL, <NULL> will be printed.
void printReverse(struct linkedlist* list);

#endif /* linked_list_h */
