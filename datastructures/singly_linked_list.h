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
    void *p_value;
    struct _single_linked_list *next;
} single_linked_list;

void add_node_to_linked_list(void *p_node);
void delete_node_from_linked_list(void *p_node);
long count_total_nodes_in_linked_list();
void print_nodes_in_linked_list();
void reverse_linked_list();
void linked_list_revise();

#endif //C_REVISION_SINGLY_LINKED_LIST_H
