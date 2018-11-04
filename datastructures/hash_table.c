//
// Created by sriramsridhar on 10/31/18.
//

#include "hash_table.h"
#include "singly_linked_list.h"

extern long max_length;

long compute_index_to_key_hash(void *p_key) {
    long index = -1;
    if (!p_key) {
        printf("Invalid input parameter.p_key is NULL.\n");
        return index;
    }
    index = (unsigned long)p_key % max_length;
    return index;
}

void add_to_hash_table(singly_linked_list_t *p_hash_table,
        void *p_key,
        void *p_data) {

    long hash_index = -1;
    singly_linked_list_t *p_current_row = NULL;

    if (!p_hash_table || !p_data || !p_key) {
        printf("Invalid Input parameters.\n");
        return;
    }

    hash_index = compute_index_to_key_hash(p_key);

    if (hash_index == -1) {
        printf("Invalid hash index.\n");
        return;
    }

    printf("Hash index = %ld.\n",hash_index);

    p_current_row = (singly_linked_list_t *) p_hash_table + hash_index;

    if (!p_current_row) {
        printf("Unable to find a row for the key (%ld).\n",((long)p_key));
        return;
    }

    printf("Adding node with key = %ld, value = (%s,%ld,%ld) to %p linked list.\n",
           ((long)p_key),
           ((player_t *)p_data)->player_name,
           ((player_t *)p_data)->player_id,
           ((player_t *)p_data)->player_score,
            p_current_row);

    add_node_to_linked_list(p_current_row,p_key,p_data);
}

void print_hash_table(singly_linked_list_t *p_hash_table)
{
    long index = 0;
    for (index=0; index < max_length; index++)
    {
        singly_linked_list_t *p_list = NULL;
        node_t *p_node = NULL;

        p_list = (singly_linked_list_t *)p_hash_table + index;

        if (!p_list) {
            printf("Invalid plist.\n");
            return;
        }

        p_node = p_list->head;

        printf("***************Key = %ld**********************.\n",index);

        while(p_node) {
            printf("key = %ld,player_name=%s,id=%ld,score=%ld.\n",
                   (long)p_node->p_key,
                   ((player_t *)(p_node->p_value))->player_name,
                   ((player_t *)(p_node->p_value))->player_id,
                   ((player_t *)(p_node->p_value))->player_score);
            p_node = p_node->next;
        }
    }
}

void revise_hash_table()
{
    singly_linked_list_t *p_hash_table = calloc(max_length,sizeof(singly_linked_list_t));
    long index =0;

    void *p_data = NULL;
    void *p_key = NULL;

    printf("************ Hash Table************************\n");

    //Prepare data.
    prepare_data(&p_data, &p_key);

    for(index=0; index < max_length; index++)
    {
        printf("Key = %ld, Player name = %s, player_id=%ld, player_score=%ld.\n",
               *(((long *)p_key+index)),
               (((player_t *)p_data+index))->player_name,
               (((player_t *)p_data+index))->player_id,
               (((player_t *)p_data+index))->player_score);
    }

    for (index = 0; index < max_length; index++)
    {
        add_to_hash_table(p_hash_table,
                          (void *)*((long *)p_key+index),
                          (void *)((player_t *)p_data+index));
    }

    print_hash_table(p_hash_table);

    free(p_data);
    free(p_key);
    free(p_hash_table);

}