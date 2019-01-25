//
// Created by sriramsridhar on 1/25/19.
//

#include "function_pointers.h"

void print_number(int i) {
    printf("number i = %d.\n",i);
}

typedef struct __fp {
    int count;
    void (*function_pointer)(int);
} fp;


void invoke_function_pointer(fp *ptr) {
    if (!ptr) {
        return;
    }
    ptr->function_pointer(ptr->count);
}

void revise_function_pointers() {
    int i = 0;
    fp *p_fp = calloc(1,sizeof(fp));
    for(i=10; i <20; i++){
        p_fp->count = 10;
        p_fp->function_pointer = print_number;
    }
    invoke_function_pointer(p_fp);
    free(p_fp);
}