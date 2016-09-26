//
//  postfix.h
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-24.
//  Copyright © 2016 davidimu. All rights reserved.
//

#ifndef postfix_h
#define postfix_h

#include <stdio.h>
#include "shunting_yard.h"

// ---------------------------------------------------------------
// Postfix
// This file calculates a postfix expression, it directly uses
// the function from infix shunting yard to help its calculation.
// ---------------------------------------------------------------

// Given the queue of parsed tokens, calculate the expression.
// If calculation was successful, return value is 0 or some error code
int calculatePostfix(struct queue* tokens, double* result);

#endif /* postfix_h */
