//
//  shunting_yard.c
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#include "shunting_yard.h"
#include <stdlib.h>
#include "node.h"
#include "error_codes.h"

// Mathematically calculate
// Returns an operand node containing the result as its value.
struct node* performCalculation(char op, double n1, double n2);

// Compare the precedence of the two operators.
// plus and minus are assigned precedence level 0
// divide and multiply are assigned precedence level 1
// Returns the the difference of their precedence level.
// - 0 if the same
// - 1 if o1 enjoys precendence over o2
// - -1 otherwise
int comparePrecedence(char o1, char o2);

int calculate(struct queue* tokens, double* result) {
    int rc = 0;
    if (tokens == NULL || sizeOfQueue(tokens) == 0) {
        return InvalidInputArgument;
    }
    
    struct stack* operatorStack = newStack();
    struct stack* outputStack = newStack();
    
    while(sizeOfQueue(tokens) != 0) {
        struct node* token = dequeue(tokens);
        
        // token is a number
        if (token->type == operand) {
            rc = pushToOutputStack(outputStack, token);
            if (rc != 0) {
                goto freeAndReturn;
            }
        }
        
        // token is an operator
        else if (token->type == operator) {
            
            // while this operator's precedence is less or equal to the one at the top of the stack,
            // pop the top of the stack onto output stack.
            // assuming all left-associative
            while(1) {
                struct node* o1 = peekStack(operatorStack);
                if (o1 == NULL) {
                    break;
                }
                
                if (comparePrecedence(token->value.operatorValue, o1->value.operatorValue) <= 0) {
                    o1 = pop(operatorStack);
                    rc = pushToOutputStack(outputStack, o1);
                    if (rc != 0) {
                        goto freeAndReturn;
                    }
                } else {
                    break;
                }
            }
            
            push(operatorStack, token);
        }
        
        // token is a parenthesis
        else if (token->type == parenthesis) {
            if (token->value.parenthesisValue == leftParenthesis) {
                push(operatorStack, token);
            } else {
                // for right parenthesis, pop everything until the left parenthesis onto output stack.
                while(1) {
                    struct node* o1 = peekStack(operatorStack);
                    if (o1 == NULL) {
                        rc = MisMatchingParenthesis;
                        goto freeAndReturn;
                    }
                    
                    if (o1->type != parenthesis && o1->value.parenthesisValue != leftParenthesis) {
                        o1 = pop(operatorStack);
                        rc = pushToOutputStack(outputStack, o1);
                        if (rc != 0) {
                            goto freeAndReturn;
                        }
                    } else {
                        // throw the left and right parenthesis away
                        pop(operatorStack);
                        break;
                    }
                }
            }
        }
    }
    
    // Pop the rest of operators to output stack
    while (sizeOfStack(operatorStack) != 0) {
        rc = pushToOutputStack(outputStack, pop(operatorStack));
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
    free(operatorStack);
    
    return rc;
}

int comparePrecedence(char o1, char o2) {
    int level1, level2 = 0;
    
    if (o1 == plus || o1 == minus) {
        level1 = 1;
    } else if (o1 == multiply1 || o1 == multiply2 || o1 == divide) {
        level1 = 2;
    }
    
    if (o2 == plus || o2 == minus) {
        level2 = 1;
    } else if (o2 == multiply1 || o2 == multiply2 || o2 == divide) {
        level2 = 2;
    }
    
    return level1 - level2;
}

int pushToOutputStack(struct stack* outputStack, struct node* token) {
    
    // directly push if it is a number
    if (token->type == operand) {
        push(outputStack, token);
        return 0;
    }
    
    // pop out two numbers and do calculation, and then push back in
    else if (token->type == operator) {
        struct node* secondOp = pop(outputStack);
        struct node* firstOp = pop(outputStack);
        
        if (secondOp == NULL || firstOp == NULL) {
            return InvalidExpression;
        } else if (secondOp->type != operand || firstOp->type != operand) {
            return InvalidExpression;
        }
        
        struct node* result = performCalculation(token->value.operatorValue,
                                                 firstOp->value.operandValue,
                                                 secondOp->value.operandValue);
        if (result == NULL) {
            return InvalidOperator;
        }
        
        int pushResult = pushToOutputStack(outputStack, result);
        free(token);
        free(firstOp);
        free(secondOp);
        
        return pushResult;
    }
    
    // invalid
    else {
        return InvalidTokenInOutput;
    }
}

struct node* performCalculation(char op, double n1, double n2) {
    double result;
    
    switch (op) {
        case plus:
            result = n1 + n2;
            break;
        
        case minus:
            result = n1 - n2;
            break;
        
        case multiply1:
            result = n1 * n2;
            break;
            
        case multiply2:
            result = n1 * n2;
            break;
        
        case divide:
            result = n1 / n2;
            break;
            
        default:
            return NULL;
    }
    
    union token tok;
    tok.operandValue = result;
    return newNode(tok, operand);
}
