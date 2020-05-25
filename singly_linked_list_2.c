//
// Created by Sridhar, Sriram on 5/14/20.
//

#include "singly_linked_list_2.h"

typedef struct _singlyLinkedList2 {
    int value;
    struct _singlyLinkedList2 *p_next;
} singlyLinkedList;

singlyLinkedList  *p_head = NULL;
singlyLinkedList  *p_tail = NULL;

void add_to_tail(int value) {
        if (p_head == NULL) {
            p_head = calloc(1, sizeof(singlyLinkedList));
            p_head->value = value;
            p_tail = p_head;
            printf("Creating list with %d.\n",value);
        } else {
            //Add the node to the tail of the list.
            singlyLinkedList  *p_node = calloc(1, sizeof(singlyLinkedList));
            p_node->value = value;
            p_tail->p_next = p_node;
            p_tail = p_node;
            printf("Appending %d to tail of the list.\n",value);
        }
}

int remove_from_head() {
    int value = -1;
    //Dequeue the first node from p_head
    if (p_head) {
        singlyLinkedList  *p_node = p_head;
        p_head = p_head->p_next;
        value = p_node->value;
        printf("Read %d from the head of the list.\n",value);
        free(p_node);
    }
    return value;
}

int delete_a_value(int value) {
    int successfully_deleted = 0;
    if (!p_head || !p_tail) {
        return successfully_deleted;
    }
    singlyLinkedList  *p_node = p_head;
    singlyLinkedList  *p_prev_node = NULL;

    while(p_node->p_next) {
        if (p_node->value == value) {
            if (p_prev_node) {
                p_prev_node->p_next = p_node->p_next;
            } else if (p_node == p_head) {
                p_head = p_head->p_next;
            }
            if(p_node == p_tail) {
                p_tail = p_prev_node;
            }
            free(p_node);
            successfully_deleted = 1;
            break;
        }
        p_prev_node = p_node;
        p_node = p_node->p_next;
    }
    if (p_node && p_prev_node && p_node == p_tail && p_node->value == value) {
        p_prev_node->p_next = NULL;
        free(p_tail);
        p_tail = p_prev_node;
        successfully_deleted = 1;
    }
    return successfully_deleted;
}

void reverse_the_list() {
    printf("Reversing the list.\n");

    if(!p_head || !p_tail) {
        return;
    }
    singlyLinkedList *p_prev = NULL;
    singlyLinkedList *p_curr = p_head;
    p_tail = p_head;
    while(p_curr) {
        singlyLinkedList  *p_temp = p_curr->p_next;
        p_curr->p_next = p_prev;
        p_prev = p_curr;
        if (!p_temp) {
            p_head = p_curr;
        }
        p_curr = p_temp;
    }
    printf("Reversing the list done.\n");
}

int is_cycle_in_linked_list(singlyLinkedList *p_l_head) {
    singlyLinkedList *p_slow = p_l_head;
    singlyLinkedList  *p_fast = NULL;
    int is_cycle_found = 0;

    if (!p_slow) {
        return is_cycle_found;
    }
    p_fast = p_slow->p_next;

    while(p_slow) {
        if(p_slow == p_fast) {
            is_cycle_found = 1;
            break;
        }
        p_slow = p_slow->p_next;
        if (!p_fast || !p_fast->p_next)
            break;
        p_fast = p_fast->p_next->p_next;
    }
    return is_cycle_found;
}

void print_list() {
    singlyLinkedList *p_node = p_head;
    while (p_node) {
        printf("%d --> ",p_node->value);
        p_node = p_node->p_next;
    }
    printf("\n");
}

void test_add_to_tail() {
    int index = 0;
    for (index=0; index < 10; index++) {
        add_to_tail(index);
    }
}

void test_remove_from_head() {
    int index=0;
    for (index=0; index < 11; index++) {
        printf("The remove_from_head returned value = %d.\n",remove_from_head());
    }
}

void test_delete_a_value() {
    int index=0;
    for (index=0; index < 11; index+=2) {
        printf("The delete_a_value(%d) returned value = %d.\n",index,delete_a_value(index));
        print_list();
    }
    for (index=9; index > 0; index-=2) {
        printf("The delete_a_value(%d) returned value = %d.\n",index,delete_a_value(index));
        print_list();
    }
}

singlyLinkedList* prepare_cycle_in_linked_list() {
    singlyLinkedList  *p_l_head = NULL, *p_l_tail = NULL, *p_current=NULL;
    int index = 0;
    for (index=0; index < 10; index++) {
        p_current = (singlyLinkedList *) calloc(1, sizeof(singlyLinkedList));
        p_current->value = index;
        if (!p_l_head) {
            p_l_head = p_current;
            p_l_tail = p_l_head;
        } else {
            p_l_tail->p_next = p_current;
            p_l_tail = p_l_tail->p_next;
        }
    }
    p_l_tail->p_next = p_l_head;
    return p_l_head;
}

void test_cycle_in_linked_list() {
    printf("is_cycle_in_linked_list = %d.\n",is_cycle_in_linked_list(p_head));
    singlyLinkedList  *p_linked_list_with_cycle = prepare_cycle_in_linked_list();
    printf("After introducing a cycle, is_cycle_in_linked_list = %d.\n",
            is_cycle_in_linked_list(p_linked_list_with_cycle));
}

void test_singly_linked_list2() {
    test_add_to_tail();
    print_list();
    test_remove_from_head();
    test_add_to_tail();
    print_list();
    test_delete_a_value();
    print_list();
    test_add_to_tail();
    print_list();
    reverse_the_list();
    print_list();
    test_cycle_in_linked_list();
}