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

#ifndef MAX_KEY_LENGTH
#define MAX_KEY_LENGTH 20
#endif

typedef struct _binary_tree
{
    void *p_key;
    void *p_value;
    struct _binary_tree *leftchild;
    struct _binary_tree *rightchild;
} binary_tree_t;

binary_tree_t *add_node_to_bst(binary_tree_t *p_node,
                                      void *p_key,
                                      void *p_value); //o(log(n))

long find_height(binary_tree_t *p_node);

void print_inorder(binary_tree_t *p_node);

void *find_node(binary_tree_t *p_node,
                void *p_key); //o(log(n))

char *get_printable_binary_tree_string(binary_tree_t *p_node); //o(n)
void revise_binary_tree();
void free_binary_tree(binary_tree_t *p_node);

unsigned char isBST(binary_tree_t *p_node);

binary_tree_t *create_binary_tree_from_input(char *p_binary_tree_string);

#endif //C_REVISION_BINARY_TREE_H
