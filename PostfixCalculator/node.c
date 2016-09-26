//
//  node.c
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#include "node.h"
#include <stdlib.h>

#define digit_count(num) (1                                     /* sign            */   \
                            + sizeof (num) * CHAR_BIT / 3      /* digits          */    \
                            + (sizeof (num) * CHAR_BIT % 3 > 0)/* remaining digit */    \
                            + 1)                               /* NUL terminator  */

// Create a new node with value
// Returns the newly created node
struct node* newNode(union token value, int type) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->value = value;
    n->type = type;
    n->prev = NULL;
    n->next = NULL;
    return n;
}
