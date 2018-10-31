//
// Created by sriramsridhar on 10/31/18.
//
#include "pointers.h"

char *wrong_way(char *ptr) {
    ptr = (char *) calloc(20,sizeof(char));
    memcpy((void *)ptr,(void *)"hello world",strlen("hello world"));
    return ptr;
}

char *static_value_manipulation(char *ptr) {
    *ptr = 20;
}

void pass_by_reference(char **ptr) {
    if (!ptr) {
        printf("Invalid input");
        return;
    }
    *ptr = (char *) calloc(20,sizeof(char));
    memcpy((void *)*ptr,(void *)"hello world",strlen("hello world"));
}

void revise_pointers() {
    char *ptr = NULL, *ptr1 = NULL, *ptr2 = NULL;
    char i=10;
    printf("ptr = %p.\n",ptr);
    printf("&ptr = %p.\n",&ptr);
    ptr = wrong_way(ptr1);
    printf("ptr1 = %s.\n",ptr1);
    printf("ptr = %s.\n",ptr);
    free(ptr);
    pass_by_reference(&ptr2);
    printf("ptr2 = %s.\n",ptr2);
    ptr=&i;
    printf("i = %d.\n",i);
    static_value_manipulation(ptr);
    printf("i = %d.\n",i);
    free(ptr2);
    free(ptr1);
}