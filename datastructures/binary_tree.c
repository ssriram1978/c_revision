//
// Created by sriramsridhar on 10/31/18.
//

#include "binary_tree.h"

typedef struct _binary_tree
{
    long id;
    struct _binary_tree *leftchild;
    struct _binary_tree *rightchild;
} binary_tree_t;



static binary_tree_t *add_node_to_bst(binary_tree_t *p_node, long id); //o(log(n))
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
static void print_inorder(binary_tree_t *p_node);
extern long max_length;

static char *get_printable_bst_string() //o(n)
{

}

static void print_inorder(binary_tree_t *p_node)
{
    if (!p_node) {
        return;
    }
    print_inorder(p_node->leftchild);
    printf(" %ld",p_node->id);
    print_inorder(p_node->rightchild);
}

static binary_tree_t *add_node_to_bst(binary_tree_t *p_node, long id) //o(log(n))
{
    if (!p_node) {
        p_node = calloc(1,sizeof(binary_tree_t));
        p_node->id = id;
        return p_node;
    }
    if (p_node->id >=id) {
        p_node->leftchild = add_node_to_bst(p_node->leftchild,id);
    } else {
        p_node->rightchild = add_node_to_bst(p_node->rightchild,id);
    }
    return p_node;
}


void revise_binary_tree()
{
    binary_tree_t *p_head = NULL;
    long index = 0;
    time_t t;

    printf("***************** Binary Tree ********************\n");

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    printf("**********Binary Search Tree***************\n");
    for (index=0;index < max_length; index++)
    {
        long random_number = (long) (rand() % MAX_RANDOM_NUMBER);
        printf("Adding %ld to BST.\n",random_number);
        p_head = add_node_to_bst(p_head,random_number);
    }
    printf("In order traversal is :");
    print_inorder(p_head);
    printf("\n");
}