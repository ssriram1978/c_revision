//
// Created by sriramsridhar on 10/31/18.
//

#include "queue.h"

extern int max_length;

void enqueue(queue_t **pp_queue,void *p_node)
{
    node *ptr = NULL;

    if (!pp_queue || !p_node) {
        printf("Invalid input parameters.\n");
        return;
    }

    ptr = (node *) calloc(1,sizeof(node));
    ptr->p_node = p_node;
    ptr->next = NULL;

    if (!*pp_queue) {
        *pp_queue = (queue_t *) calloc(1,sizeof(queue_t));
    }

    if((*pp_queue)->tail == NULL)
    {
        (*pp_queue)->tail = ptr;
        (*pp_queue)->count++;

        if((*pp_queue)->head == NULL)
        {
            (*pp_queue)->head = (*pp_queue)->tail;
        }
    }
    else
    {
        (*pp_queue)->tail->next = ptr;
        (*pp_queue)->tail = ptr;
    }
}

unsigned char dequeue(queue_t **pp_queue,void **pp_node)
{
    unsigned char success = 0;
    node *p_node = NULL;

    if (!pp_queue || !*pp_queue || !pp_node) {
        printf("Invalid input parameters.\n");
        return success;
    }
    p_node = (*pp_queue)->head;

    if(!p_node)
    {
        //printf("Invalid node.\n");
        return success;
    }

    (*pp_queue)->head = p_node->next;

    (*pp_node) = p_node->p_node;

    free(p_node);
#if 0
    if (!(*pp_queue)->head) {
        free(*pp_queue);
        *pp_queue = NULL;
    }
#endif
    success = 1;
    return success;
}

long count_queue_size(queue_t *p_queue)
{
    long count = 0;
    node *node = NULL;

    if (!p_queue) {
        printf("Invalid input parameters.\n");
        return count;
    }

    node = p_queue->head;

    while(node)
    {
        count++;
        node = node->next;
    }

    return count;
}

void print_queue(queue_t *p_queue)
{
    long count = 0;
    node *p_node = p_queue->head;

    while(p_node)
    {
        printf("Node at index =%ld has p_node =%p\n",count,p_node->p_node);
        p_node = p_node->next;
        p_queue->count++;
    }
}

void release_queue(queue_t **pp_queue) {
    if(*pp_queue) {
        node *p_node = (*pp_queue)->head;
        node *p_node_next = NULL;
        while(p_node) {
            p_node_next = p_node->next;
            free(p_node);
            p_node = p_node_next;
        }
        free(*pp_queue);
    }
}

void revise_queue() {
    long player_id = 0, player_score = 100;
    queue_t *p_queue = NULL;
    struct player_details *p_player_details = NULL;

    struct player_details {
        long player_id;
        long player_score;
    };

    printf("************Queue************************\n");

    for(player_id=0; player_id < max_length; player_id++) {
        struct player_details *p_player_details = (struct player_details *) calloc(1,sizeof(struct player_details));
        p_player_details->player_id = player_id;
        p_player_details->player_score = player_score++;
        enqueue(&p_queue,p_player_details);
    }
    printf("queue size = %d.\n",count_queue_size(p_queue));
    printf("print_queue:\n");
    print_queue(p_queue);

    while(dequeue(&p_queue,(void *)&p_player_details)) {
        if (p_player_details != NULL) {
            printf("player_id=%ld and player_score=%ld.\n",p_player_details->player_id,
                   p_player_details->player_score);
            free(p_player_details);
        }
    }
    printf("queue size = %d.\n",count_queue_size(p_queue));

    free(p_queue);
}