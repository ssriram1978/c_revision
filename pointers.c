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

void strcat_example() {
    char *ptr = calloc(20,sizeof(char));
    char ptr2[] = " \n";
    printf("*******strcat example ************.\n");
    memcpy(ptr,"Hello",strlen("Hello"));
    strcat(ptr,ptr2);
    printf("ptr=%s.",ptr);
    free(ptr);
}

void const_pointers_example() {
    char array[] = "Hello";
    const char *ptr = array; //value pointed by ptr cannot be changed but the pointer can be changed.
    unsigned char * const ptr2 = (unsigned char *) calloc(10,sizeof(char));
    //in this char * const ptr2; is a constant pointer to a character array.
    // characters can be changed but the pointer cannot be changed.

    printf("****** const char * pointer example ****\n");
    printf("const ptr = %s.\n",ptr);
    //*(ptr+2) = 'b'; //error: assignment of read-only location ‘*(ptr + 2)’
    array[2] = 'b';
    printf("const ptr = %s.\n",ptr);

    printf("****** char * const pointer example ****\n");
    memcpy(ptr2,"world",sizeof("world"));
    printf("ptr2=%s.\n",ptr2);
    memcpy(ptr2,"universe",sizeof("universe"));
    printf("ptr2=%s.\n",ptr2);
    //ptr2 = "123"; //error: assignment of read-only variable ‘ptr2’
    free(ptr2);
}

void revise_pointers() {
    char *ptr = NULL, *ptr1 = NULL, *ptr2 = NULL;
    char i=10;
    printf("************Pointers************************\n");
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
    const_pointers_example();
    strcat_example();

}