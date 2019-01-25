//
// Created by sriramsridhar on 1/25/19.
//

#include "preprocessors.h"


#define	MAX(X,Y) (((X) > (Y)) ? (X) : (Y))

int add(int x) {
    return x + 1;
}

#define SNAP(X) printf("variable "#X"=%d.\n",X);
#define GLUE(X,Y) X##Y
//register int len=0;

void revise_preprocessors() {
    int var1 = 100, var2 = 200, var;
    float v1 = -1.0, v2 = 1.0, v;
    int i = 0;

    var = MAX(var1,var2);
    v = MAX(v1,v2);
    printf("var = %d.\n",var);
    printf("v = %f.\n",v);

    i = 100;
    i = add(i);
    printf("add function call.\n");
    SNAP(i)
#define add(x)    (2 * (x))
    i = 100;
    i = add(i);
    printf("add preprocessed call.\n");
    SNAP(i)
#undef add
    i = 100;
    i = add(i);
    printf("add function call.\n");
    SNAP(i)
    //printf("Glue of %s and %s = %s.\n","Hello", "World", GLUE(Hello,World));
}