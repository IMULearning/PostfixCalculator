//
//  shunting_yard.h
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#ifndef shunting_yard_h
#define shunting_yard_h

#include <stdio.h>
#include "stack.h"
#include "queue.h"

// ----------------------------------------------------------
// Shunting Yard
// This file is responsible for calculating infix expression
// Although part of its function can be used directly
// for postfix expression
// ----------------------------------------------------------

// Given the queue of parsed tokens, calculate the expression.
// If calculation was successful, return value is 0 or some error code
int calculate(struct queue* tokens, double* result);

// Push the token onto the output stack
// If it is an operand token, directly push
// If it is a operator token, pop two operand tokens off and calculate the result, before push back in.
// We never push parenthesis token onto the output stack.
// Returns either 0 as success or some error code
int pushToOutputStack(struct stack* outputStack, struct node* token);

#endif /* shunting_yard_h */
