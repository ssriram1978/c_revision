//
// Created by sriramsridhar on 10/31/18.
//

#include "binary_tree.h"

typedef struct _binary_tree
{
    long id;
    struct __binary_tree *leftchild;
    struct __binary_tree *rightchild;
} binary_tree;

static binary_tree *p_head = NULL;

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


void revise_binary_tree()
{
    printf("**********Binary Search Tree***************\n");

}