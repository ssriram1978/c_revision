//
// Created by sriramsridhar on 10/31/18.
//

#include "hash_table.h"
#include "singly_linked_list.h"

extern long max_length;

long compute_index_to_key_hash(void *p_key) {
    long index = -1;
    if (!p_key) {
        printf("Invalid input parameter.\n");
        return index;
    }
    index = (unsigned long)p_key % max_length;
    return index;
}

void add_entry_to_linked_list(singly_linked_list *p_current_row)
{
    if (!p_current_row) {
        printf("Invalid hash table row.\n");
        return;
    }

}

void add_to_hash_table(singly_linked_list *p_hash_table,
        void *p_key,
        void *p_data) {

    long hash_index = -1;
    singly_linked_list *p_current_row = NULL;

    if (!p_hash_table || !p_data || !p_key) {
        printf("Invalid Input parameters.\n");
        return;
    }

    hash_index = compute_index_to_key_hash(p_key);

    if (hash_index == -1) {
        printf("Invalid hash index.\n");
        return;
    }

    p_current_row = p_hash_table + hash_index;

    if (!p_current_row) {
        printf("Invalid entry.\n");
        return;
    }

    add_entry_to_linked_list(p_current_row);
}

void revise_hash_table()
{
    singly_linked_list *p_hash_table = calloc(max_length,sizeof(singly_linked_list));
    long index =0;
    typedef struct __player {
        char player_name[10];
        long player_id;
        long player_score;
    }player_t;

    for(index=100;index < max_length+100;index++) {
        player_t *p_player_t = (player_t *) calloc(1,sizeof(player_t));
        sprintf(p_player_t->player_name,"%s%ld","Hello",index);
        p_player_t->player_id = index;
        p_player_t->player_score = index+100;
        add_to_hash_table(p_hash_table,
                (void *)p_player_t->player_id,
                (void *)p_player_t);
    }
}