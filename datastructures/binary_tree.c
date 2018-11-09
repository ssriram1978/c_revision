//
// Created by sriramsridhar on 10/31/18.
//

#include "binary_tree.h"
#include "queue.h"

static int delete_node_from_bst(long id); //o(log(n))

static int delete_node(long id); //o(log(n) + o(swapping nodes to form a bst).

static int perform_dfs();
static int perform_bfs();
extern long max_length;

long find_height(binary_tree_t *p_node)
{
    //Post order traversal.
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

void *find_node(binary_tree_t *p_node, void *p_key) //o(log(n))
{
    void *p_found_node = NULL;

    if (!p_node) {
        return p_found_node;
    }
    //pre order traversal.
    if (p_node->p_key == p_key) {
        return p_node->p_value;
    }
    p_found_node = find_node(p_node->leftchild,p_key);
    if (p_found_node) {
        return p_found_node;
    }
    p_found_node = find_node(p_node->rightchild,p_key);
    return p_found_node;
}

static unsigned char isBSTRecurse(binary_tree_t *p_node,
                                  void *p_key_min,
                                  void *p_key_max) {
    unsigned char isBST = 1;

    if (!p_node) {
        return isBST;
    }

    if (!((p_node->p_key >= p_key_min) && \
         (p_node->p_key < p_key_max))) {
        isBST = 0;
        return isBST;
    }

    isBST = isBSTRecurse(p_node->leftchild, p_key_min,p_node->p_key);
    if (isBST) {
        return isBST;
    }

    isBST = isBSTRecurse(p_node->leftchild, p_node->p_key,p_key_max);
    return isBST;
}

unsigned char isBST(binary_tree_t *p_node) {
    return isBSTRecurse(p_node,(void *)0,(void *)0xFFFFFFFFFFFFFFFF);
}

static char **get_node_string_from_bt_string(char *p_binary_tree_string)
{
    char **pp_array_of_node_string = NULL;
    char **pp_node_ptr = NULL;
    long count_number_of_nodes = 0,index=0;
    char *p_token = NULL;
    char *p_dup_bt_string = NULL;

    if (!p_binary_tree_string) {
        return pp_array_of_node_string;
    }

    p_dup_bt_string = (char *) calloc(strlen(p_binary_tree_string),sizeof(char));
    strcpy(p_dup_bt_string,p_binary_tree_string);

    //count the total number of tokens in the binary tree string.
    p_token = strtok(p_dup_bt_string," \r\n");
    while(p_token) {
        count_number_of_nodes+=1;
        //printf("p_token=%s.\n",p_token);
        p_token = strtok(NULL," \r\n");
    }

    if (!count_number_of_nodes) {
        printf("Invalid number of nodes.\n");
        free(p_dup_bt_string);
        return pp_array_of_node_string;
    }

    printf("Total number of nodes = %ld.\n",count_number_of_nodes);

    //Allocate memory for the output array. Assume a long can be of 20 characters.
    //Keep the last character array list as \0 for deducing the end of character array list.
    pp_array_of_node_string = (char **) calloc((size_t)count_number_of_nodes+1,
            sizeof(char **));
    strcpy(p_dup_bt_string,p_binary_tree_string);
    pp_node_ptr = pp_array_of_node_string;

    //Copy the token into the array.
    p_token = strtok(p_dup_bt_string," \r\n");
    while(p_token) {
        *pp_node_ptr = (char *) calloc(MAX_KEY_LENGTH,sizeof(char));
        strncpy(*pp_node_ptr, p_token, MAX_KEY_LENGTH);
        pp_node_ptr++;
        p_token = strtok(NULL," \r\n");
    }

    /*for(index=0; index < count_number_of_nodes; index++) {
        printf("node at index %ld is %s.\n",index,pp_array_of_node_string[index]);
    }*/

    free(p_dup_bt_string);
    return pp_array_of_node_string;
}

static binary_tree_t *prepare_btree_recursive(char **pp_node_string,
                                              long current_node_position,
                                              long total_number_of_nodes)
{
    binary_tree_t *p_node = NULL;
    char *p_current_node_string = NULL;
    long left_child_position = 0, right_child_position = 0;

    if (!pp_node_string) {
        return p_node;
    }

    p_current_node_string = *pp_node_string;

    if (!p_current_node_string) {
        return p_node;
    }

    if(!strcmp(p_current_node_string,"NULL")) {
        //printf("The node is NULL.Return NULL.\n");
        return p_node;
    } else  {
        long p_node_value = atol((const char *)p_current_node_string);
        p_node = (binary_tree_t *) calloc(1,sizeof(binary_tree_t));
        p_node->p_key = (void *)p_node_value;
        p_node->p_value = (void *)p_node_value;
        /*printf("Storing value = (%s)%ld in the current node.\n",
               p_current_node_string,
               (long)p_node->p_key);*/
        //Find the left child.
        left_child_position = current_node_position*2+1;
        if(left_child_position < total_number_of_nodes) {
            p_node->leftchild = prepare_btree_recursive(pp_node_string+left_child_position,
                                                        left_child_position,
                                                        total_number_of_nodes);
        }
        //Find the right child.
        right_child_position = current_node_position*2+2;
        if (right_child_position < total_number_of_nodes) {
            p_node->rightchild = prepare_btree_recursive(pp_node_string+right_child_position,
                                                         right_child_position,
                                                         total_number_of_nodes);
        }
    }
    return p_node;
}

static void prepare_btree_from_node_string(binary_tree_t **pp_binary_tree,
                                           char **pp_node_string,
                                           long total_number_of_nodes)
{
    if (!pp_binary_tree || !pp_node_string || !total_number_of_nodes) {
        printf("Invalid input parameters.\n");
        return;
    }
    *pp_binary_tree = prepare_btree_recursive(pp_node_string,0,total_number_of_nodes);
}

binary_tree_t *create_binary_tree_from_input(char *p_binary_tree_string)
{
    binary_tree_t *p_binary_tree = NULL;
    char **p_node_string = NULL, **p_temp = NULL;
    long total_number_of_nodes = 0;

    if (!p_binary_tree_string) {
        return p_binary_tree;
    }
    //prepare an array of strings where each string is a node in text format.
    p_node_string = get_node_string_from_bt_string(p_binary_tree_string);
    if (!p_node_string) {
        return p_binary_tree;
    }

    p_temp = p_node_string;

    while(*p_temp) {
        //printf("p_temp=%s.\n",(*p_temp));
        p_temp++;
        total_number_of_nodes++;
    }

    //convert the array of strings into a binary tree.
    prepare_btree_from_node_string(&p_binary_tree,p_node_string, total_number_of_nodes);

    free(p_node_string);

    return p_binary_tree;
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
        strcat(p_string, "\n");
        //printf("After appending EOL p_string=%s.\n", p_string);
        //Add NULL string word to the queue.
        enqueue(pp_queue, pp_eol_str);
    } else if (p_dequed_node == (void *) pp_null_str) {
        //Add a "NULL" to the p_string.
        strcat(p_string, "NULL ");
        //printf("After appending NULL p_string=%s.\n", p_string);
    } else {
        //Append this node value to the p_string.
        char long_int_str[20] = {0};
        sprintf(long_int_str, "%ld ", (long) ((binary_tree_t *) p_dequed_node)->p_key);
        strcat(p_string, long_int_str);
        /*printf("After appending %p, p_string=%s.\n",
               (void *)((binary_tree_t *) p_dequed_node)->p_key,
               p_string); */
        //Add the left and right sub child to the queue.
        if (!((binary_tree_t *) p_dequed_node)->leftchild) {
            //Add NULL string word to the queue.
            enqueue(pp_queue, pp_null_str);
            /*printf("Enqueuing NULL string to ppqueue because left of %s is NULL.\n",
                   long_int_str);*/
        } else {
            enqueue(pp_queue, ((binary_tree_t *) p_dequed_node)->leftchild);
            /*printf("Enqueuing left child of %s to ppqueue.\n",
                   long_int_str);*/
        }

        if (!((binary_tree_t *) p_dequed_node)->rightchild) {
            //Add NULL string word to the queue.
            enqueue(pp_queue, pp_null_str);
            /*printf("Enqueuing NULL string to ppqueue because right of %s is NULL.\n",
                   long_int_str);*/
        } else {
            enqueue(pp_queue, ((binary_tree_t *) p_dequed_node)->rightchild);
            /*printf("Enqueuing right child of %s to ppqueue.\n",
                   long_int_str);*/
        }
    }
}

char *get_printable_binary_tree_string(binary_tree_t *p_node) //o(n)
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
    p_string = (char *)calloc((size_t)(2^height)-1,MAX_KEY_LENGTH);
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
    //printf("Final p_string=%s.\n",p_string);
    release_queue(&p_queue);
    return p_string;
}

void print_inorder(binary_tree_t *p_node)
{
    if (!p_node) {
        return;
    }
    print_inorder(p_node->leftchild);
    printf(" %p",p_node->p_key);
    print_inorder(p_node->rightchild);
}

binary_tree_t *add_node_to_bst(binary_tree_t *p_node,
                                      void *p_key,
                                      void *p_value) //o(log(n))
{
    if (!p_key || !p_value) {
        return NULL;
    }

    if (!p_node) {
        p_node = (binary_tree_t *) calloc(1,sizeof(binary_tree_t));
        p_node->p_key = p_key;
        p_node->p_value = p_value;
        return p_node;
    }
    if (p_node->p_key >=p_key) {
        p_node->leftchild = add_node_to_bst(p_node->leftchild,p_key,p_value);
    } else {
        p_node->rightchild = add_node_to_bst(p_node->rightchild,p_key,p_value);
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
    long random_number = 0;

    printf("***************** Binary Tree ********************\n");

    /* Intialize random number generator */
    srand((unsigned) time(&t));

    printf("**********Binary Search Tree***************\n");
    for (index=0;index < max_length; index++)
    {
        random_number = (long) (rand() % MAX_RANDOM_NUMBER);
        printf("Adding %p to BST.\n",(void *)random_number);
        p_head = add_node_to_bst(p_head,
                                 (void *)random_number,
                                 (void *)random_number);
    }
    printf("In order traversal is :");
    print_inorder(p_head);
    printf("\n");
    printf("Height = %ld.\n",find_height(p_head));

    p_binary_tree_str = get_printable_binary_tree_string(p_head);

    printf("Binary tree printable string = %s.\n",p_binary_tree_str);

    printf("find_node(%ld) returned %p.\n",
            random_number,
           find_node(p_head,(void *)random_number));

    printf("find_node(%ld) returned %p.\n",
           (long)12345,
           find_node(p_head,(void *)12345));

    printf("isBST() returned %d.\n",isBST(p_head));

    free_binary_tree(p_head);

    p_head = create_binary_tree_from_input(p_binary_tree_str);

    if (p_head) {
        char *p_binary_tree_str = NULL;
        printf("Successfully fetched a binary tree from string formatted text. \n");
        p_binary_tree_str = get_printable_binary_tree_string(p_head);
        printf("Binary tree printable string = %s.\n",p_binary_tree_str);
        free(p_binary_tree_str);
    }

    free_binary_tree(p_head);

    free(p_binary_tree_str);
}