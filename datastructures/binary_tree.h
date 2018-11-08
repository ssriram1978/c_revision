//
// Created by sriramsridhar on 10/31/18.
//

#ifndef C_REVISION_BINARY_TREE_H
#define C_REVISION_BINARY_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>       /* time */
#include <sys/time.h>
#include <time.h>       /* time */
#include <sys/time.h>

#ifndef MAX_RANDOM_NUMBER
#define MAX_RANDOM_NUMBER 500
#endif

typedef struct _binary_tree
{
    long id;
    struct _binary_tree *leftchild;
    struct _binary_tree *rightchild;
} binary_tree_t;

void revise_binary_tree();
void free_binary_tree(binary_tree_t *p_node);

#endif //C_REVISION_BINARY_TREE_H
