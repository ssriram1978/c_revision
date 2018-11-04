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

typedef struct __player {
    char player_name[20];
    long player_id;
    long player_score;
}player_t;

typedef struct _node
{
    void *p_key;
    void *p_value;
    struct _node *next;
} node_t;

typedef struct _singly_linked_list {
    node_t *head;
    node_t *tail;
    long count;
} singly_linked_list;


void add_node_to_linked_list(singly_linked_list *p_list,
                             void *p_key,
                             void *p_value);
int find_node_in_linked_list(singly_linked_list *p_list,
                             void *p_key,
                             void **p_data);
void delete_node_from_linked_list(singly_linked_list *p_list,
                                  void *p_key);

void singly_linked_list_revise();

#endif //C_REVISION_SINGLY_LINKED_LIST_H
