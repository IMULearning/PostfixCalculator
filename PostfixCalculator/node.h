//
//  node.h
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#ifndef node_h
#define node_h

#define operator    0
#define operand     1
#define parenthesis 2

#define one     '1'
#define two     '2'
#define three   '3'
#define four    '4'
#define five    '5'
#define six     '6'
#define seven   '7'
#define eight   '8'
#define nine    '9'
#define zero    '0'

#define leftParenthesis     '('
#define rightParenthesis    ')'

#define plus        '+'
#define minus       '-'
#define multiply1   'x'
#define multiply2   '*'
#define divide      '/'

#include <stdio.h>

// ---------------------
// Token
// ---------------------

// A token can only be an integer operand or a char operator
union token {
    double operandValue;
    char operatorValue;
    char parenthesisValue;
};

// ---------------------
// Node
// ---------------------

// A generic list element for a (double) linked list.
struct node {
    union token value;
    int type;
    struct node* prev;
    struct node* next;
};

// Create a new node
struct node* newNode(union token value, int type);

#endif /* node_h */
