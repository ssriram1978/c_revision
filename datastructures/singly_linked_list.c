//
// Created by sriramsridhar on 10/31/18.
//

#include "singly_linked_list.h"

static long count_total_nodes_in_linked_list(singly_linked_list_t *p_list);
static void print_nodes_in_linked_list(singly_linked_list_t *p_list);
static void reverse_linked_list(singly_linked_list_t *p_list);
extern long max_length;

void add_node_to_linked_list(singly_linked_list_t *p_list,
                             void *p_key,
                             void *p_value)
{
    node_t *ptr = NULL;

    if (!p_list) {
        printf("Invalid input parameters.\n");
        return;
    }

    ptr = (node_t *) calloc(1,sizeof(node_t));
    ptr->p_value = p_value;
    ptr->p_key = p_key;

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

void free_linked_list(singly_linked_list_t *p_list)
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

static void reverse_linked_list(singly_linked_list_t *p_list)
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

void delete_node_from_linked_list(singly_linked_list_t *p_list,
                                  void *p_key)
{
    node_t *node = p_list->head;
    node_t *prev = p_list->head;

    if (!p_list || !node) {
        printf("Invalid input parameters.\n");
        return;
    }

    while(node && node->p_key != p_key)
    {
        prev = node;
        node = node->next;
    }

    if(!node)
    {
        printf("Unable to locate the node with key =%p\n",p_key);
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

int find_node_in_linked_list(singly_linked_list_t *p_list,
                             void *p_key,
                             void **p_data)
{
    node_t *node = p_list->head;
    int found = -1;

    if (!p_list || !node || !p_data) {
        printf("Invalid input parameters.\n");
        return found;
    }

    while(node && node->p_key != p_key)
    {
        node = node->next;
    }

    if(!node)
    {
        printf("Unable to locate the node with value =%p\n",p_key);
        return found;
    }

    printf("Found Node that has p_key= %p and p_value =%p\n",node->p_key,node->p_value);
    found = 1;
    *p_data = node->p_value;
    return found;
}


static long count_total_nodes_in_linked_list(singly_linked_list_t *p_list)
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

static void print_nodes_in_linked_list(singly_linked_list_t *p_list)
{
    long count = 0;
    node_t *node = p_list->head;

    if (!p_list) {
        printf("Invalid input parameters.\n");
        return;
    }

    while(node)
    {
        printf("Node at index =%ld has p_key = %p and p_value =%p\n",
                count,
                node->p_key,
                node->p_value);

        node = node->next;
        count++;
    }
}

void prepare_data(void **p_data, void **p_key)
{
    long index;
    player_t *p_player_data = NULL;
    long *p_player_id = NULL;

    if (!p_data || !p_key) {
        printf("Invalid inpur parameters.\n");
        return;
    }

    p_player_data = (player_t *) calloc(max_length,sizeof(player_t));
    p_player_id = (long *) calloc(max_length,sizeof(long));

    for(index=0;index < max_length;index++) {
        sprintf((p_player_data+index)->player_name,"%s%ld","Hello",index);
        (p_player_data+index)->player_id = index;
        (p_player_data+index)->player_score = index+100;
        *(p_player_id+index) = index;
    }
    *p_data = p_player_data;
    *p_key = p_player_id;
}

void singly_linked_list_revise()
{
    int index = 0;
    singly_linked_list_t singly_linked_list = {0};
    void *p_data = NULL;
    void *p_key = NULL;

    printf("************ Singly Linked List************************\n");

    //Prepare data.
    prepare_data(&p_data, &p_key);

    for(index=0; index < max_length; index++)
    {
        printf("Key = %ld, Player name = %s, player_id=%ld, player_score=%ld.\n",
               *(((long *)p_key+index)),
               (((player_t *)p_data+index))->player_name,
               (((player_t *)p_data+index))->player_id,
               (((player_t *)p_data+index))->player_score);
    }

    for(index=0; index < max_length; index++)
    {
        add_node_to_linked_list(&singly_linked_list,
                (void *)*((long *)p_key + index),
                (void *)((player_t *)p_data + index));
    }

    print_nodes_in_linked_list(&singly_linked_list);

    printf("Total number of nodes = %ld.\n",
            count_total_nodes_in_linked_list(&singly_linked_list));

    for(index=0; index < max_length; index++)
    {
        delete_node_from_linked_list(&singly_linked_list,
                                     (void *)*((long *)p_key + index));
    }

    print_nodes_in_linked_list(&singly_linked_list);

    printf("Total number of nodes = %ld.\n",
            count_total_nodes_in_linked_list(&singly_linked_list));

    for(index=0; index < max_length; index++)
    {
        add_node_to_linked_list(&singly_linked_list,
                                (void *)*((long *)p_key + index),
                                (void *)((player_t *)p_data + index));
    }

    print_nodes_in_linked_list(&singly_linked_list);

    printf("Total number of nodes = %ld.\n",
            count_total_nodes_in_linked_list(&singly_linked_list));

    reverse_linked_list(&singly_linked_list);

    printf("After reversing...\n");

    print_nodes_in_linked_list(&singly_linked_list);

    printf("Total number of nodes = %ld.\n",
            count_total_nodes_in_linked_list(&singly_linked_list));

    for(index=0; index < max_length; index++)
    {
        void *p_data = NULL;
        printf("searching for node %ld in linked list returned %d.\n",
               *((long *)p_key + index),
                find_node_in_linked_list(&singly_linked_list,
                                         (void *)*((long *)p_key + index),
                                         &p_data));
        printf("Player name = %s, player_id=%ld, player_score=%ld.\n",
               ((player_t *)p_data)->player_name,
               ((player_t *)p_data)->player_id,
               ((player_t *)p_data)->player_score);
    }

    free_linked_list(&singly_linked_list);
    free(p_key);
    free(p_data);
}