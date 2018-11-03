//
// Created by sriramsridhar on 10/31/18.
//

#include "hash_table.h"
#include "singly_linked_list.h"

typedef struct _single_linked_list
{
    void *p_key;
    void *p_value;
    struct _single_linked_list *next;
} single_linked_list;

typedef struct _hash_table_t{
    single_linked_list *head;
    single_linked_list *tail;
    long count;
} hash_table_t;


extern long max_length;

long compute_index_to_key_hash(void *p_key) {
    long index = -1;
    if (!p_key) {
        printf("Invalid input parameter.\n");
        return index;
    }
    index = *p_key%max_length;
    return index;
}

void add_to_hash_table(void *p_key, void *p_data) {
    if (!p_data || !p_key) {
        printf("Invalid Input parameters.\n");
        return;
    }
}

void revise_hash_table()
{
    hash_table_t *p_hash_table = calloc(max_length,sizeof(hash_table_t));
    long index =0;
    typedef struct __player {
        char player_name[10];
        long player_id;
        long player_score;
    }player_t;

    for(index=100;index < ;index++) {
        player_t *p_player_t = (player_t *) calloc(1,sizeof(player_t));
        sprintf(p_player_t->player_name,"%s%ld","Hello",index);
        p_player_t->player_id = index;
        p_player_t->player_score = index+100;

    }
}