//
// Created by sriramsridhar on 10/31/18.
//

#include "doubly_linked_list.h"

typedef struct _doubly_linked_list
{
    void *p_value;
    struct _doubly_linked_list *prev;
    struct _doubly_linked_list *next;
} doubly_linked_list;

static doubly_linked_list *head = NULL;
static doubly_linked_list *tail = NULL;
static long count = 0;
extern long max_length;

static void add_node_to_linked_list(void *p_node);
static void delete_node_from_linked_list(void *p_node);
static long count_total_nodes_in_linked_list();
static void print_nodes_in_linked_list();
static void reverse_linked_list();

static void add_node_to_linked_list(void *p_node)
{
    doubly_linked_list *ptr = NULL;

    ptr = (doubly_linked_list *) calloc(1,sizeof(doubly_linked_list));
    ptr->p_value = p_node;

    if(head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
        ptr->prev = NULL;
        tail = head;
        count++;
    }
    else
    {
        //add it to the tail
        tail->next = ptr;
        ptr->prev = tail;
        tail = ptr;
    }
}

static void reverse_linked_list()
{
    doubly_linked_list *currNode = head, *prevNode = NULL, *nextNode = NULL;
    tail = currNode;
    while (currNode) {
        if (currNode->next == NULL) {
            head = currNode;
        }
        nextNode = currNode->next;
        currNode->next = prevNode;
        currNode->prev = nextNode;
        prevNode = currNode;
        currNode = nextNode;
    }
}

static void delete_node_from_linked_list(void *p_node)
{
    doubly_linked_list *node = head;

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
    if(head == node) {
        if (node->next) {
            node->next->prev = NULL;
        }
        head = node->next;
    } else if(tail == node) {
        if (node->prev) {
            node->prev->next = NULL;
        }
        tail = node->prev;
    }
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    printf("Deleting Node that has p_value =%p\n",node->p_value);
    free(node);
    count--;
}

static long count_total_nodes_in_linked_list()
{
    long count = 0;
    doubly_linked_list *node = head;

    while(node)
    {
        count++;
        node = node->next;
    }

    return count;
}

static void print_nodes_in_linked_list()
{
    long count = 0;
    doubly_linked_list *node = head;

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
    printf("************ Doubly Linked List************************\n");
    for(index=0; index < max_length; index++)
    {
        p_array[index]=index;
        add_node_to_linked_list((void *)p_array + index);
    }

    print_nodes_in_linked_list();

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list());

    for(index=0; index < max_length; index++)
    {
        delete_node_from_linked_list((void *)p_array + index);
    }

    print_nodes_in_linked_list();

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list());

    for(index=0; index < max_length; index++)
    {
        p_array[index]=index;
        add_node_to_linked_list((void *)p_array + index);
    }

    print_nodes_in_linked_list();

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list());

    reverse_linked_list();

    printf("After reversing...\n");

    print_nodes_in_linked_list();

    printf("Total number of nodes = %ld.\n",count_total_nodes_in_linked_list());

    free(p_array);

}