#include <stdio.h>
#include "pointers.h"
#include "array.h"
#include "datastructures/singly_linked_list.h"
#include "datastructures/doubly_linked_list.h"
#include "datastructures/hash_table.h"
#include "datastructures/queue.h"
#include "datastructures/binary_tree.h"
#include "datastructures/circular_ring_buffer.h"

int max_length = 10;

int main() {
    printf("Hello, World!\n");
    revise_pointers();
    revise_arrays();
    revise_queue();
    singly_linked_list_revise();
    doubly_linked_list_revise();
    revise_circular_buffer();
    return 0;
}