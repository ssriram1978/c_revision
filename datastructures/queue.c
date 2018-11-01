//
// Created by sriramsridhar on 10/31/18.
//

#include "queue.h"

static queue *head = NULL;
static queue *tail = NULL;
static long count = 0;
extern int max_length;

void enqueue(void *p_node)
{
    queue *ptr = NULL;

    ptr = (queue *) calloc(1,sizeof(queue));
    ptr->p_node = p_node;
    ptr->next = NULL;

    if(tail == NULL)
    {
        tail = ptr;
        count++;

        if(head == NULL)
        {
            head = tail;
        }
    }
    else
    {
        tail->next = ptr;
        tail = ptr;
    }
}

void dequeue(long **pp_node)
{
    queue *node = head;

    if(!node || !pp_node)
    {
        return;
    }

    head = node->next;

    *pp_node = node->p_node;

    free(node);
}

long count_queue_size()
{
    long count = 0;
    queue *node = head;

    while(node)
    {
        count++;
        node = node->next;
    }

    return count;
}

void print_queue()
{
    long count = 0;
    queue *node = head;

    while(node)
    {
        printf("Node at index =%ld has p_node =%p\n",count,node->p_node);
        node = node->next;
        count++;
    }
}

void revise_queue() {
    long player_id = 0, player_score = 100;
    struct player_details {
        long player_id;
        long player_score;
    };
    printf("************Queue************************\n");
    for(player_id=0; player_id < max_length; player_id++) {
        struct player_details *p_player_details = (struct player_details *) calloc(1,sizeof(struct player_details));
        p_player_details->player_id = player_id;
        p_player_details->player_score = player_score++;
        enqueue(p_player_details);
    }
    printf("queue size = %d.\n",count_queue_size());
    printf("print_queue:\n");
    print_queue();
    for(player_id=0; player_id < max_length; player_id++) {
        struct player_details *p_player_details = NULL;
        dequeue(&p_player_details);
        if (p_player_details != NULL) {
            printf("player_id=%ld and player_score=%ld.\n",p_player_details->player_id,
                   p_player_details->player_score);
            free(p_player_details);
        }
    }
    printf("queue size = %d.\n",count_queue_size());
}