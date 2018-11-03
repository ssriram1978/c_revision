//
// Created by sriramsridhar on 10/31/18.
//

#include "hash_table.h"
#include "singly_linked_list.h"

typedef struct _single_linked_list
{
    void *p_value;
    struct _single_linked_list *next;
} single_linked_list;

typedef struct _hash_table_t{
    single_linked_list *head;
    single_linked_list *tail;
    long count;
} hash_table_t;


extern long max_length;


void revise_hash_table()
{
    hash_table_t *p_hash_table = calloc(max_length,sizeof(hash_table_t));
    long index =0;
    for(index=0;index < max_length;index++) {

    }
}