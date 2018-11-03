//
// Created by sriramsridhar on 10/31/18.
//

#include "singly_linked_list.h"


typedef struct _node
{
    void *p_value;
    struct _node *next;
} node_t;

typedef struct _singly_linked_list {
    node_t *head;
    node_t *tail;
    long count;
} singly_linked_list;

static void add_node_to_linked_list(singly_linked_list *p_list,void *p_node);
static void delete_node_from_linked_list(singly_linked_list *p_list,void *p_node);
static long count_total_nodes_in_linked_list(singly_linked_list *p_list);
static void print_nodes_in_linked_list(singly_linked_list *p_list);
static void reverse_linked_list(singly_linked_list *p_list);
extern long max_length;

static void add_node_to_linked_list(singly_linked_list *p_list,void *p_node)
{
    node_t *ptr = NULL;

    if (!p_list) {
        printf("Invalid input parameters.\n");
        return;
    }

    ptr = (node_t *) calloc(1,sizeof(node_t));
    ptr->p_value = p_node;

    if(p_list->head == NULL)
    {
        p_list->head = ptr;
        ptr->next = NULL;
        p_list->tail = p_list->head;
        p_list->count++;
    }
    else
    {
        //add it to the tail
        p_list->tail->next = ptr;
        p_list->tail = ptr;
    }
}

static void free_linked_list(singly_linked_list *p_list)
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

static void reverse_linked_list(singly_linked_list *p_list)
{
    node_t *currNode = NULL, *prevNode = NULL, *nextNode = NULL;

    if (!p_list) {
        printf("Invalid input parameters.\n");
        return;
    }

    currNode = p_list->head;

    while(currNode)
    {
        if(currNode == p_list->head)
        {
            p_list->tail = currNode;
        }

        if(currNode->next == NULL)
        {
            p_list->head = currNode;
        }

        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
}

static void delete_node_from_linked_list(singly_linked_list *p_list,void *p_node)
{
    node_t *node = p_list->head;
    node_t *prev = p_list->head;

    if (!p_list || !node) {
        printf("Invalid input parameters.\n");
        return;
    }

    while(node && node->p_value != p_node)
    {
        prev = node;
        node = node->next;
    }

    if(!node)
    {
        printf("Unable to locate the node with value =%p\n",p_node);
        return;
    }

    prev->next = node->next;

    //Adjust head and tail.
    if(p_list->head == node)
    {
        //Adjust head to point to the next node.
        p_list->head = node->next;
    }

    if(p_list->tail == node)
    {
        //Adjust the tail to point to the next node.
        p_list->tail = prev;
    }
    printf("Deleting Node that has p_value =%p\n",node->p_value);
    free(node);
    p_list->count--;
}

static long count_total_nodes_in_linked_list(singly_linked_list *p_list)
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

static void print_nodes_in_linked_list(singly_linked_list *p_list)
{
    long count = 0;
    node_t *node = p_list->head;

    if (!p_list) {
        printf("Invalid input parameters.\n");
        return;
    }

    while(node)
    {
        printf("Node at index =%ld has p_value =%p\n",count,node->p_value);
        node = node->next;
        count++;
    }
}

void singly_linked_list_revise()
{
    int index = 0;
    singly_linked_list singly_linked_list = {0};
    int *p_array = (int *) calloc(max_length,sizeof(int));
    printf("************ Singly Linked List************************\n");
    for(index=0; index < max_length; index++)
    {
        p_array[index]=index;
        add_node_to_linked_list(&singly_linked_list,(void *)p_array + index);
    }

    print_nodes_in_linked_list(&singly_linked_list);

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list(&singly_linked_list));

    for(index=0; index < max_length; index++)
    {
        delete_node_from_linked_list(&singly_linked_list, (void *)(p_array + index));
    }

    print_nodes_in_linked_list(&singly_linked_list);

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list(&singly_linked_list));

    for(index=0; index < max_length; index++)
    {
        p_array[index]=index;
        add_node_to_linked_list(&singly_linked_list,(void *)(p_array + index));
    }

    print_nodes_in_linked_list(&singly_linked_list);

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list(&singly_linked_list));

    reverse_linked_list(&singly_linked_list);

    printf("After reversing...\n");

    print_nodes_in_linked_list(&singly_linked_list);

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list(&singly_linked_list));

    free(p_array);

    free_linked_list(&singly_linked_list);

}