//
//  parser.h
//  PostfixCalculator
//
//  Created by Weinan Qiu on 2016-09-23.
//  Copyright © 2016 davidimu. All rights reserved.
//

#ifndef parser_h
#define parser_h

#include <stdio.h>
#include "queue.h"

// Parse the given tokens array to a queue of token nodes using space as delimiter.
// If the provided argument is NULL, an empty queue will be returned.
// RC is the return value
int parseTokensDelim(char tokens[], struct queue** q);

#endif /* parser_h */
