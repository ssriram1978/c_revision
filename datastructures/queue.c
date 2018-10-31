//
// Created by sriramsridhar on 10/31/18.
//

#include "queue.h"

static queue *head = NULL;
static queue *tail = NULL;
static long count = 0;
extern int max_length;

void enqueue(long player_id, long player_score)
{
    queue *ptr = NULL;

    ptr = (queue *) calloc(1,sizeof(queue));
    ptr->player_id = player_id;
    ptr->player_score = player_score;
    ptr->next = NULL;

    if(tail == NULL)
    {
        tail = ptr;
        count++;

        if(head == NULL)
        {
            head = tail;
        }
        //printf("Adding player id =%ld for the first time, count=%ld \n",player_id, count);
    }
    else
    {
        tail->next = ptr;
        tail = ptr;
    }
}

void dequeue(long *p_player_id, long *p_player_score)
{
    queue *node = head;

    if(!node || !p_player_id || !p_player_score)
    {
        return;
    }

    head = node->next;

    *p_player_id = node->player_id;

    *p_player_score = node->player_score;

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
        printf("Node at index =%ld has player id =%ld,score=%ld\n",count,node->player_id,node->player_score);
        node = node->next;
        count++;
    }
}

void revise_queue() {
    long player_id = 0, player_score = 100;
    for(player_id=0; player_id < max_length; player_id++) {
        enqueue(player_id,player_score++);
    }
    printf("queue size = %d.\n",count_queue_size());
    printf("print_queue:\n");
    print_queue();
    for(player_id=0; player_id < max_length; player_id++) {
        long player_id = 0;
        long player_score = 0;
        dequeue(&player_id,&player_score);
        printf("player_id=%d and player_score=%d.\n",player_id,player_score);
    }
    printf("queue size = %d.\n",count_queue_size());
}