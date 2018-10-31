//
// Created by sriramsridhar on 10/31/18.
//

#ifndef C_REVISION_SINGLY_LINKED_LIST_H
#define C_REVISION_SINGLY_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>       /* time */
#include <sys/time.h>
#include <time.h>       /* time */
#include <sys/time.h>


typedef struct _single_linked_list
{
    long player_score;
    long player_id;
    struct _single_linked_list *next;
} single_linked_list;

void add_node_to_linked_list(long player_id, long player_score);
void delete_node_from_linked_list(long player_id);
long count_total_nodes_in_linked_list();
single_linked_list *return_nodes_belonging_to_this_percentile(unsigned char percentile);
void print_nodes_in_linked_list();
void reverse_linked_list();

#endif //C_REVISION_SINGLY_LINKED_LIST_H
