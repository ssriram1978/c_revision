//
// Created by sriramsridhar on 10/31/18.
//

#include "array.h"


void print_array(int *p_array, int length) {
    int i = 0;
    for(i=0; i < length; i++) {
        printf("Element %d is %d.\n",i, p_array[i]);
    }
    for(i=0; i < length; i++) {
        printf("Element %d is %d.\n",i, *p_array++);
    }

}

void print_array_without_length(int p_array[]) {
    int i = 0;
    int length = sizeof(p_array)/sizeof(p_array[0]);
    //printf("sizeof(p_array)=%ld.\n",sizeof(p_array));
    //printf("sizeof(p_array[0])=%ld.\n",sizeof(p_array[0]));
#if 0
    for(i=0; i < length; i++) {
        printf("Element %d is %d.\n",i, *p_array++);
    }
#endif
}

void print_array2(int **pp_array, int length) {
    int i = 0;
    for(i=0; i < length; i++) {
        int *p_array= *(pp_array +i);
        int j = 0;
        for (j=0; j < 10; j++) {
            printf("Element %d is %d.\n",j, *p_array++);
        }
    }
}




void revise_arrays() {
    int array1[] = {1,2,3,4,5,6,7,8,9,10};
    int array2[] = {11,12,13,14,15,16,17,18,19,20};
    int array3[] = {21,22,23,24,25,26,27,28,29,30};
    int array4[] = {31,32,33,34,35,36,37,38,39,40};
    int **pp_array= calloc(4,sizeof(int*));
    int *pp_array2[4];
    int length;

    printf("size of array1=%ld.\n",sizeof(array1));
    printf("len of array1=%d.\n",length=sizeof(array1)/sizeof(array1[0]));
    printf("************* print_array with length ************************.\n");
    print_array(array1, length);
    printf("**************print_array_without_length *****************.\n");
    print_array_without_length(array1);
    //printf("size of pp_array=%ld.\n",sizeof(pp_array));
    //printf("len of pp_array=%ld.\n",length=sizeof(pp_array)/sizeof(pp_array[0]));
    pp_array[0] = array1;
    pp_array[1] = array2;
    pp_array[2] = array3;
    pp_array[3] = array4;
    print_array2(pp_array, 4);
    free(pp_array);
    printf("********** integer array of pointers of type int.**********\n");
    printf("sizeof pp_array2 = %ld.\n",sizeof(pp_array2));
    pp_array2[0] = array1;
    pp_array2[1] = array2;
    pp_array2[2] = array3;
    pp_array2[3] = array4;
    print_array2(pp_array2, 4);

}