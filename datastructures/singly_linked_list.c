//
// Created by sriramsridhar on 10/31/18.
//

#include "singly_linked_list.h"

static single_linked_list *head = NULL;
static single_linked_list *tail = NULL;
long count = 0;
extern long max_length;

void add_node_to_linked_list(void *p_node)
{
    single_linked_list *ptr = NULL;

    ptr = (single_linked_list *) calloc(1,sizeof(single_linked_list));
    ptr->p_value = p_node;

    if(head == NULL)
    {
        head = ptr;
        ptr->next = NULL;
        tail = head;
        count++;
    }
    else
    {
        //add it to the tail
        tail->next = ptr;
        tail = ptr;
    }
}

void reverse_linked_list()
{
    single_linked_list *currNode = head, *prevNode = NULL, *nextNode = NULL;

    while(currNode)
    {
        if(currNode == head)
        {
            tail = currNode;
        }

        if(currNode->next == NULL)
        {
            head = currNode;
        }

        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
}

void delete_node_from_linked_list(void *p_node)
{
    single_linked_list *node = head;
    single_linked_list *prev = head;

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
    if(head == node)
    {
        //Adjust head to point to the next node.
        head = node->next;
    }

    if(tail == node)
    {
        //Adjust the tail to point to the next node.
        tail = prev;
    }
    printf("Deleting Node that has p_value =%p\n",node->p_value);
    free(node);
}

long count_total_nodes_in_linked_list()
{
    long count = 0;
    single_linked_list *node = head;

    while(node)
    {
        count++;
        node = node->next;
    }

    return count;
}

void print_nodes_in_linked_list()
{
    long count = 0;
    single_linked_list *node = head;

    while(node)
    {
        printf("Node at index =%ld has p_value =%p\n",count,node->p_value);
        node = node->next;
        count++;
    }
}

void linked_list_revise()
{
    int index = 0;

    int *p_array = (int *) calloc(max_length,sizeof(int));
    printf("************Linked List************************\n");
    for(index=0; index < max_length; index++)
    {
        p_array[index]=index;
        add_node_to_linked_list((void *)p_array + index);
    }

    print_nodes_in_linked_list();

    printf("Total number of nodes = %d.\n",count_total_nodes_in_linked_list());

    for(index=0; index < max_length; index++)
    {
        delete_node_from_linked_list((void *)p_array + index);
    }

    print_nodes_in_linked_list();

    printf("Total number of nodes = %d.\n",count_total_nodes_in_linked_list());

    for(index=0; index < max_length; index++)
    {
        p_array[index]=index;
        add_node_to_linked_list((void *)p_array + index);
    }

    print_nodes_in_linked_list();

    printf("Total number of nodes = %d.\n",count_total_nodes_in_linked_list());

    reverse_linked_list();

    print_nodes_in_linked_list();

    printf("Total number of nodes = %d.\n",count_total_nodes_in_linked_list());

    free(p_array);

}