//
//  parser.c
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#include "parser.h"
#include <string.h>
#include <stdlib.h>
#include "error_codes.h"

#define true    1
#define false   0

int isNumber(char *s);
int isOperand(char t);
int isOperator(char t);
int isParenthesis(char t);
void enqueueOperator(struct queue* q, char t);
void enqueueOperand(struct queue* q, double t);
void enqueueParenthesis(struct queue* q, char t);

int parseTokensDelim(char tokens[], struct queue** q) {
    *q = newQueue();
    
    char *p;
    p = strtok(tokens, " ");
    while(p) {
        if (strlen(p) > 1) {
            if (isNumber(p) == false) {
                return InvalidExpression;
            }
            enqueueOperand(*q, atof(p));
        } else if (isOperator(*p) == true) {
            enqueueOperator(*q, *p);
        } else if (isParenthesis(*p) == true) {
            enqueueParenthesis(*q, *p);
        } else {
            if (isNumber(p) == false) {
                return InvalidExpression;
            }
            enqueueOperand(*q, atof(p));
        }
        
        p = strtok(NULL, " ");
    }
    
    free(p);
    return 0;
}

int isNumber(char *s) {
    double val;
    char *next;
    
    val = strtod(s, &next);
    if ((next == s) || (*next != '\0')) {
        return false;
    } else {
        return true;
    }
}

void enqueueOperator(struct queue* q, char t) {
    union token tok;
    tok.operatorValue = t;
    enqueue(q, newNode(tok, operator));
}

void enqueueOperand(struct queue* q, double t) {
    union token tok;
    tok.operandValue = t;
    enqueue(q, newNode(tok, operand));
}

void enqueueParenthesis(struct queue* q, char t) {
    union token tok;
    tok.parenthesisValue = t;
    enqueue(q, newNode(tok, parenthesis));
}

int isOperand(char t) {
    if (t == one    ||
        t == two    ||
        t == three  ||
        t == four   ||
        t == five   ||
        t == six    ||
        t == seven  ||
        t == eight  ||
        t == nine   ||
        t == zero) {
        return true;
    }
    return false;
}

int isOperator(char t) {
    if (t == plus       ||
        t == minus      ||
        t == multiply1  ||
        t == multiply2  ||
        t == divide) {
        return true;
    }
    return false;
}

int isParenthesis(char t) {
    if (t == leftParenthesis || t == rightParenthesis) {
        return true;
    }
    return false;
}
