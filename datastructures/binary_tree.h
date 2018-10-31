//
// Created by sriramsridhar on 10/31/18.
//

#ifndef C_REVISION_BINARY_TREE_H
#define C_REVISION_BINARY_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>       /* time */
#include <sys/time.h>
#include <time.h>       /* time */
#include <sys/time.h>


typedef struct _binary_tree
{
    long player_score;
    long player_id;
    struct _binary_tree *leftchild;
    struct _binary_tree *rightchild;
} binary_tree;

binary_tree* get_player_score_bt();
binary_tree* get_player_id_bt();
void add_to_player_score_btree(binary_tree **p_bt, long player_id, long player_score);
void add_to_player_id_btree(binary_tree **p_bt, long player_id, long player_score);
void return_the_largest_player_score_from_player_score_btree(binary_tree *p_bt, long *p_player_score);
void return_player_id_from_binary_tree_that_matches_this_player_score(binary_tree *p_bt, long *p_player_id, long player_score);
void return_player_id_from_binary_tree_that_belongs_to_this_percentile(long *p_player_id, unsigned char percentile);
void read_player_score_from_player_id_btree(binary_tree *p_bt, long player_id, long *p_player_score);
void count_binary_tree_size(binary_tree *p_bt, long *p_count);
void print_binary_tree(binary_tree *p_bt);
binary_tree** get_player_score_bt_address();
binary_tree** get_player_id_bt_address();
void delete_from_btree(binary_tree **p_bt, long p_player_id);
void find_depth_of_binary_tree(binary_tree *p_bt, long *p_bt_length);


#endif //C_REVISION_BINARY_TREE_H
