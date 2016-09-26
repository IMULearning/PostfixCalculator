//
//  postfix.c
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-24.
//  Copyright © 2016 davidimu. All rights reserved.
//

#include "postfix.h"
#include <stdlib.h>
#include "error_codes.h"

int calculatePostfix(struct queue* tokens, double* result) {
    int rc = 0;
    if (tokens == NULL || sizeOfQueue(tokens) == 0) {
        return InvalidInputArgument;
    }
    
    struct stack* outputStack = newStack();
    
    while(sizeOfQueue(tokens) != 0) {
        struct node* token = dequeue(tokens);
        rc = pushToOutputStack(outputStack, token);
        if (rc != 0) {
            goto freeAndReturn;
        }
    }
    
    // assertion that there is one token left
    if (sizeOfStack(outputStack) != 1) {
        rc = OutputStackNotExhausted;
        goto freeAndReturn;
    }
    
    struct node* r = pop(outputStack);
    
    // assertion that the token left is an operand (number)
    if (r->type != operand) {
        rc = NonOperandTypeInTheEnd;
        goto freeAndReturn;
    }
    *result = r->value.operandValue;
    
freeAndReturn:
    free(outputStack);
    
    return rc;
}
