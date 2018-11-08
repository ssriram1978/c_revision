//
// Created by sriramsridhar on 10/31/18.
//

#ifndef C_REVISION_QUEUE_H
#define C_REVISION_QUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>       /* time */
#include <sys/time.h>
#include <time.h>       /* time */
#include <sys/time.h>

typedef struct _node_t {
    void *p_node;
    struct _node_t *next;
} node;

typedef struct _queue_t {
    node *head;
    node *tail;
    long count;
}queue_t;

void enqueue(queue_t **pp_queue,void *p_node);
unsigned char dequeue(queue_t **pp_queue,void **pp_node);
long count_queue_size(queue_t *p_queue);
void print_queue(queue_t *p_queue);
void release_queue(queue_t **pp_queue);
void revise_queue();
#endif //C_REVISION_QUEUE_H
