//
//  error_codes.h
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#ifndef error_codes_h
#define error_codes_h

#define InvalidInputArgument        -0x0001

#define NoExpressionProvided        -0x0010
#define OutputStackNotExhausted     -0x0011
#define NonOperandTypeInTheEnd      -0x0012
#define MisMatchingParenthesis      -0x0013
#define InvalidTokenInOutput        -0x0014
#define InvalidExpression           -0x0015
#define InsufficientOperands        -0x0016
#define InvalidOperator             -0x0017

#include <stdio.h>

#endif /* error_codes_h */
