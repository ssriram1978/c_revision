//
// Created by sriramsridhar on 10/31/18.
//

#include "binary_tree.h"

typedef struct _binary_tree
{
    long id;
    struct _binary_tree *leftchild;
    struct _binary_tree *rightchild;
} binary_tree;


static void add_node_to_bst(long id); //o(log(n))
static int delete_node_from_bst(long id); //o(log(n))
static int find_node(long id); //o(log(n))
static int delete_node(long id); //o(log(n) + o(swapping nodes to form a bst).
static int create_binary_tree_from_input(char *p_binary_tree);
static char *get_printable_bst_string(); //o(n)
static long *get_sorted_nodes(); //o(n)
static int check_bst(); //o(n)
static int find_height(); //o(n)
static int perform_dfs();
static int perform_bfs();

extern long max_length;

void revise_binary_tree()
{
    binary_tree *p_head = NULL;
    long index = 0;
    time_t t;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    printf("**********Binary Search Tree***************\n");
    for (index=0;index < max_length; index++)
    {
        //add_node_to_bst(index%MAX_RANDOM_NUMBER);
    }
}