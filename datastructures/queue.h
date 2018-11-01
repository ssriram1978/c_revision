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


typedef struct _queue
{
    void *p_node;
    struct _queue *next;
} queue;

void enqueue(void *p_node);
void dequeue(long **pp_node);
long count_queue_size();
void print_queue();
void revise_queue();
#endif //C_REVISION_QUEUE_H
