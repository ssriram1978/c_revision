//
// Created by sriramsridhar on 10/31/18.
//

#ifndef C_REVISION_DOUBLY_LINKED_LIST_H
#define C_REVISION_DOUBLY_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>       /* time */
#include <sys/time.h>
#include <time.h>       /* time */
#include <sys/time.h>

#ifndef MAX_NUMBER_OF_ELEMENTS
#define MAX_NUMBER_OF_ELEMENTS 100000
#endif

#ifndef NUMBER_OF_MIDDLE_POINTERS
#define NUMBER_OF_MIDDLE_POINTERS 1000
#endif



typedef struct _doubly_linked_list
{
    long player_score;
    long player_id;
    struct _doubly_linked_list *next;
    struct _doubly_linked_list *prev;
} doubly_linked_list;

long add_node_to_doubly_linked_list2(long player_id, long player_score, long linkedlist_index);
void add_node_to_doubly_linked_list(long player_id, long player_score);
void delete_node_from_doubly_linked_list(long player_id);
long count_total_nodes_in_doubly_linked_list();
doubly_linked_list *return_nodes_from_doubly_linked_list_belonging_to_this_percentile(unsigned char percentile);
void print_nodes_in_doubly_linked_list();
void print_nodes_in_middle_doubly_linked_list();
void get_player_score_at_this_linkedlist_index(long linkedlist_index, long player_index, long *player_score);


#endif //C_REVISION_DOUBLY_LINKED_LIST_H
