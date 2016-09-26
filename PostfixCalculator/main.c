//
//  main.c
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "parser.h"
#include "node.h"
#include "shunting_yard.h"
#include "postfix.h"
#include "error_codes.h"

// Render the RC code in human readable form.
char* renderRc(int rc);

int main(int argc, const char * argv[]) {
    
    while(1) {
        char format[1];
        
    inputFormat:
        printf("infix or postfix? (type 'i' or 'p')?\n");
        printf("> ");
        scanf("%1s", format);
        
        if (format[0] != 'i' && format[0] != 'p') {
            printf("invalid format.\n");
            goto inputFormat;
        }
        
        if (format[0] == 'i') {
            printf("infix selected.\n");
        } else if (format[0] == 'o') {
            printf("postfix selected.\n");
        }
    
        char expression[500];
        
    inputExpression:
        
        printf("type the expression (or 'exit' to quit)\n");
        printf("> ");
        scanf("\n%500[^\n]", expression);
        
        if (strncmp(expression, "exit", 4) == 0) {
            printf("bye\n");
            return 0;
        }
        
        struct queue* q;
        int rc = 0;
        rc = parseTokensDelim(expression, &q);
        if (rc != 0) {
            printf("> %s\n", renderRc(rc));
            goto inputExpression;
        }
        
        double result;
        if (format[0] == 'i') {
            rc = calculate(q, &result);
        } else {
            rc = calculatePostfix(q, &result);
        }
        
        if (rc == 0) {
            printf("> %f\n", result);
        } else {
            printf("> %s\n", renderRc(rc));
        }
    }
    
    return 0;
}

char* renderRc(int rc) {
    switch (rc) {
        case InvalidInputArgument:
            return "invalid input argument";
        
        case NoExpressionProvided:
            return "no expression provided";
        
        case OutputStackNotExhausted:
            return "output stack didn't exhaust";
            
        case NonOperandTypeInTheEnd:
            return "no operand left at the end of algorithm run";
            
        case MisMatchingParenthesis:
            return "mismatch parenthesis";
        
        case InvalidTokenInOutput:
            return "invalid token in output stack";
            
        case InvalidExpression:
            return "invalid expression";
            
        case InvalidOperator:
            return "invalid operator";
        
        case 0:
            return "OK";
            
        default:
            return "unknown error";
    }
}
