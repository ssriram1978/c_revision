//
// Created by sriramsridhar on 12/12/18.
//

#include "structure.h"

//
// Created by sriramsridhar on 12/12/18.
//

struct ss {
    int ss;
    char ss2;
};


void test_struct() {
    struct ss obj;
    printf("size of struct = %ld\n",sizeof(obj));
    printf("size of long = %ld\n",sizeof(long));
    printf("size of long int = %ld\n",sizeof(long int));
    printf("size of float = %ld\n",sizeof(float));
    printf("size of double = %ld\n",sizeof(double));

}