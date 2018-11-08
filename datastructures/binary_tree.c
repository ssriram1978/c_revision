//
// Created by sriramsridhar on 10/31/18.
//

#include "binary_tree.h"
#include "queue.h"

static binary_tree_t *add_node_to_bst(binary_tree_t *p_node, long id); //o(log(n))
static int delete_node_from_bst(long id); //o(log(n))
static int find_node(long id); //o(log(n))
static int delete_node(long id); //o(log(n) + o(swapping nodes to form a bst).
static int create_binary_tree_from_input(char *p_binary_tree);
static char *get_printable_bst_string(); //o(n)
static long *get_sorted_nodes(); //o(n)
static int check_bst(); //o(n)
static int perform_dfs();
static int perform_bfs();
static void print_inorder(binary_tree_t *p_node);
extern long max_length;

static long find_height(binary_tree_t *p_node)
{
    long height = 0, left_height =0, right_height = 0;

    if (!p_node) {
        return height;
    }
    height++;
    left_height = find_height(p_node->leftchild);
    right_height = find_height(p_node->rightchild);
    if (left_height > right_height) {
        height += left_height;
    } else {
        height += right_height;
    }
    return height;
}

static void process_dequeued_node(void *p_dequed_node,
                                  queue_t **pp_queue,
                                  char **pp_null_str,
                                  char **pp_eol_str,
                                  char *p_string) {
    if (!p_dequed_node) {
        printf("Dequeued node is NULL.");
        return;
    }
    if (p_dequed_node == (void *) pp_eol_str) {
        //Add a \n to the p_string. This identifies end of the current level.
        strcat(p_string, " \n");
        printf("After appending EOL p_string=%s.\n", p_string);
        //Add NULL string word to the queue.
        enqueue(pp_queue, pp_eol_str);
    } else if (p_dequed_node == (void *) pp_null_str) {
        //Add a "NULL" to the p_string.
        strcat(p_string, "NULL ");
        printf("After appending NULL p_string=%s.\n", p_string);
    } else {
        //Append this node value to the p_string.
        char long_int_str[20] = {0};
        sprintf(long_int_str, "%ld ", ((binary_tree_t *) p_dequed_node)->id);
        strcat(p_string, long_int_str);
        printf("After appending %ld, p_string=%s.\n",
               ((binary_tree_t *) p_dequed_node)->id,
               p_string);
        //Add the left and right sub child to the queue.
        if (!((binary_tree_t *) p_dequed_node)->leftchild) {
            //Add NULL string word to the queue.
            enqueue(pp_queue, pp_null_str);
            printf("Enqueuing NULL string to ppqueue because left of %s is NULL.\n",
                   long_int_str);
        } else {
            enqueue(pp_queue, ((binary_tree_t *) p_dequed_node)->leftchild);
            printf("Enqueuing left child of %s to ppqueue.\n",
                   long_int_str);
        }

        if (!((binary_tree_t *) p_dequed_node)->rightchild) {
            //Add NULL string word to the queue.
            enqueue(pp_queue, pp_null_str);
            printf("Enqueuing NULL string to ppqueue because right of %s is NULL.\n",
                   long_int_str);
        } else {
            enqueue(pp_queue, ((binary_tree_t *) p_dequed_node)->rightchild);
            printf("Enqueuing right child of %s to ppqueue.\n",
                   long_int_str);
        }
    }
}

static char *get_printable_bst_string(binary_tree_t *p_node) //o(n)
{
    char *p_string = NULL;
    long height = 0;
    queue_t *p_queue = NULL;
    #define NULL_STR "NULL"
    #define EOL_STR "EOL"
    char *p_null_str = NULL_STR;
    char *p_eol_str = EOL_STR;
    void *p_dequed_node = NULL;

    if (!p_node) {
        return p_string;
    }
    //Find the height of the tree.
    height = find_height(p_node);

    if (!height) {
        printf("Invalid height found.\n");
        return p_string;
    }
    //Total number of nodes at each level is 2^n -1 where n is the height.
    //Take 8 bytes (long) for each node to represent a long number or NULL or \n
    //Allocate one more long 8 bytes for blank space.
    // Allocate integer representation of FFFFFFFFFFFFFFFF (18446744073709551615) approx 20.
    p_string = (char *)calloc((size_t)(2^height)-1,20);
    //Maintain a queue for performing BFS.
    //Enqueue a EOL string word.
    enqueue(&p_queue,&p_eol_str);
    //Enqueue the root.
    enqueue(&p_queue,p_node);
    while(dequeue(&p_queue,(void *)&p_dequed_node)) {
        process_dequeued_node(p_dequed_node,
                              &p_queue,
                              &p_null_str,
                              &p_eol_str,
                              p_string);
    }
    printf("Final p_string=%s.\n",p_string);
    release_queue(&p_queue);
    return p_string;
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
        p_node = (binary_tree_t *) calloc(1,sizeof(binary_tree_t));
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

void free_binary_tree(binary_tree_t *p_node) {
    //Post order traversal.
    if (!p_node) {
        return;
    }
    free_binary_tree(p_node->leftchild);
    free_binary_tree(p_node->rightchild);
    free(p_node);
}

void revise_binary_tree()
{
    binary_tree_t *p_head = NULL;
    long index = 0;
    time_t t;
    char *p_binary_tree_str = NULL;

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
    printf("Height = %ld.\n",find_height(p_head));

    p_binary_tree_str = get_printable_bst_string(p_head);

    printf("Binary tree printable string = %s.\n",p_binary_tree_str);

    free_binary_tree(p_head);
    free(p_binary_tree_str);
}