//
// Created by sriramsridhar on 10/31/18.
//

#include "doubly_linked_list.h"

typedef struct _node_t
{
    void *p_value;
    struct _node_t *prev;
    struct _node_t *next;
} node_t;

typedef struct _doubly_linked_list_t {
    node_t *head;
    node_t *tail;
    long count;
} doubly_linked_list_t;

extern long max_length;

static void add_node_to_linked_list(doubly_linked_list_t *p_list,void *p_node);
static void delete_node_from_linked_list(doubly_linked_list_t *p_list,void *p_node);
static long count_total_nodes_in_linked_list(doubly_linked_list_t *p_list);
static void print_nodes_in_linked_list(doubly_linked_list_t *p_list);
static void reverse_linked_list(doubly_linked_list_t *p_list);
static void free_linked_list(doubly_linked_list_t *p_list);
static void add_node_to_linked_list(doubly_linked_list_t *p_list,void *p_node)
{
    node_t *ptr = NULL;

    if (!p_list || !p_node) {
        printf("Invalid input parameters.\n");
        return;
    }

    ptr = (node_t *) calloc(1,sizeof(node_t));
    ptr->p_value = p_node;

    if(p_list->head == NULL)
    {
        p_list->head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
        p_list->tail = p_list->head;
        p_list->count++;
    }
    else
    {
        //add it to the tail
        p_list->tail->next = ptr;
        ptr->prev = p_list->tail;
        p_list->tail = ptr;
    }
}

static void free_linked_list(doubly_linked_list_t *p_list)
{
    node_t *p_node = NULL, *next = NULL;

    if (!p_list || !p_list->head) {
        printf("Invalid input parameters.\n");
        return;
    }

    p_node = p_list->head;
    next = p_list->head;
    while(p_node) {
        next = p_node->next;
        free(p_node);
        p_node = next;
    }
}

static void reverse_linked_list(doubly_linked_list_t *p_list)
{
    node_t *currNode = NULL, *prevNode = NULL, *nextNode = NULL;

    if (!p_list) {
        printf("Invalid input parameters.\n");
        return;
    }
    currNode = p_list->head;
    p_list->tail = currNode;
    while (currNode) {
        if (currNode->next == NULL) {
            p_list->head = currNode;
        }
        nextNode = currNode->next;
        currNode->next = prevNode;
        currNode->prev = nextNode;
        prevNode = currNode;
        currNode = nextNode;
    }
}

static void delete_node_from_linked_list(doubly_linked_list_t *p_list,void *p_node)
{
    node_t *node = NULL;

    if (!p_list || !p_node) {
        printf("Invalid input parameters.\n");
        return;
    }
    node = p_list->head;

    while(node && node->p_value != p_node)
    {
        node = node->next;
    }

    if(!node)
    {
        printf("Unable to locate the node with value =%p\n",p_node);
        return;
    }

    //Adjust head and tail.
    if(p_list->head == node) {
        if (node->next) {
            node->next->prev = NULL;
        }
        p_list->head = node->next;
    } else if(p_list->tail == node) {
        if (node->prev) {
            node->prev->next = NULL;
        }
        p_list->tail = node->prev;
    }
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    printf("Deleting Node that has p_value =%p\n",node->p_value);
    free(node);
    p_list->count--;
}

static long count_total_nodes_in_linked_list(doubly_linked_list_t *p_list)
{
    long count = 0;
    node_t *node = NULL;

    if (!p_list) {
        printf("Invalid input parameters.\n");
        return count;
    }

    node = p_list->head;

    while(node)
    {
        count++;
        node = node->next;
    }

    return count;
}

static void print_nodes_in_linked_list(doubly_linked_list_t *p_list)
{
    long count = 0;
    node_t *node = NULL;

    if (!p_list) {
        printf("Invalid input parameters.\n");
        return;
    }

    node = p_list->head;

    while(node)
    {
        printf("Node at index =%ld has p_value =%p\n",count,node->p_value);
        node = node->next;
        count++;
    }
}

void doubly_linked_list_revise()
{
    int index = 0;

    int *p_array = (int *) calloc(max_length,sizeof(int));

    doubly_linked_list_t list = {0};

    printf("************ Doubly Linked List************************\n");

    for(index=0; index < max_length; index++)
    {
        p_array[index]=index;
        add_node_to_linked_list(&list,(void *)p_array + index);
    }

    print_nodes_in_linked_list(&list);

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list(&list));

    for(index=0; index < max_length; index++)
    {
        delete_node_from_linked_list(&list,(void *)p_array + index);
    }

    print_nodes_in_linked_list(&list);

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list(&list));

    for(index=0; index < max_length; index++)
    {
        p_array[index]=index;
        add_node_to_linked_list(&list,(void *)p_array + index);
    }

    print_nodes_in_linked_list(&list);

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list(&list));

    reverse_linked_list(&list);

    printf("After reversing...\n");

    print_nodes_in_linked_list(&list);

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list(&list));

    free(p_array);

    free_linked_list(&list);
}