//
// Created by sriramsridhar on 10/31/18.
//

#include "queue.h"


typedef struct _node_t {
    void *p_node;
    struct _node_t *next;
} node;

typedef struct _queue_t {
    node *head;
    node *tail;
    long count;
}queue_t;

static void enqueue(queue_t *p_queue,void *p_node);
static void dequeue(queue_t *p_queue,void **pp_node);
static long count_queue_size(queue_t *p_queue);
static void print_queue(queue_t *p_queue);

extern int max_length;

static void enqueue(queue_t *p_queue,void *p_node)
{
    node *ptr = NULL;

    if (!p_queue || !p_node) {
        printf("Invalid input parameters.\n");
        return;
    }

    ptr = (node *) calloc(1,sizeof(node));
    ptr->p_node = p_node;
    ptr->next = NULL;

    if(p_queue->tail == NULL)
    {
        p_queue->tail = ptr;
        p_queue->count++;

        if(p_queue->head == NULL)
        {
            p_queue->head = p_queue->tail;
        }
    }
    else
    {
        p_queue->tail->next = ptr;
        p_queue->tail = ptr;
    }
}

static void dequeue(queue_t *p_queue,void **pp_node)
{
    node *node = p_queue->head;

    if (!p_queue || !pp_node) {
        printf("Invalid input parameters.\n");
        return;
    }
    node = p_queue->head;

    if(!node)
    {
        printf("Invalid node.\n");
        return;
    }

    p_queue->head = node->next;

    *pp_node = node->p_node;

    free(node);
}

static long count_queue_size(queue_t *p_queue)
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

static void print_queue(queue_t *p_queue)
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

void revise_queue() {
    long player_id = 0, player_score = 100;
    queue_t queue = {0};

    struct player_details {
        long player_id;
        long player_score;
    };

    printf("************Queue************************\n");

    for(player_id=0; player_id < max_length; player_id++) {
        struct player_details *p_player_details = (struct player_details *) calloc(1,sizeof(struct player_details));
        p_player_details->player_id = player_id;
        p_player_details->player_score = player_score++;
        enqueue(&queue,p_player_details);
    }
    printf("queue size = %d.\n",count_queue_size(&queue));
    printf("print_queue:\n");
    print_queue(&queue);

    for(player_id=0; player_id < max_length; player_id++) {
        struct player_details *p_player_details = NULL;
        dequeue(&queue,(void *)&p_player_details);
        if (p_player_details != NULL) {
            printf("player_id=%ld and player_score=%ld.\n",p_player_details->player_id,
                   p_player_details->player_score);
            free(p_player_details);
        }
    }
    printf("queue size = %d.\n",count_queue_size(&queue));
}