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

void manipulate_pointer_to_array(int array[]) {
    array[0] = 11;
    array[1] = 12;
    array[2] = 13;
    array[3] = 14;
    array[4] = 15;
}

void strcat_example() {
    char *ptr = calloc(20,sizeof(char));
    char ptr2[] = " \n";
    char *ptr3 = NULL;
    printf("*******strcat example ************.\n");
    memcpy(ptr,"Hello",strlen("Hello"));
    strcat(ptr,ptr2);
    printf("ptr=%s.",ptr);
    if ((ptr3 = strstr(ptr, "llo")) != NULL) {
        printf("Found %s at index %d in %s.\n",ptr3, (int) abs(ptr-ptr3), ptr);
    }
    free(ptr);
}

void strtok_example() {
    char str[] ="- This, \r\n a sample string.\n";
    char * pch;
    char *p_str2 = NULL;

    printf("*******strtok example ************.\n");
    p_str2 = (char *) calloc(strlen(str)+1,sizeof(char));
    strncpy(p_str2,str,strlen(str));

    printf ("Splitting string \"%s\" into tokens:\n",p_str2);
    pch = strtok (p_str2," ,.-\r\n");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-\r\n");
    }

    printf ("Second iteration. Splitting string \"%s\" into tokens:\n",p_str2);
    strncpy(p_str2,str,strlen(str));
    pch = strtok (p_str2," ,.-\r\n");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-\r\n");
    }
    free(p_str2);
}

void const_pointers_example() {
    char array[] = "Hello";
    const char *ptr = (unsigned char *) calloc(10,sizeof(char)); //value pointed by ptr cannot be changed but the pointer can be changed.
    unsigned char * const ptr2 = (unsigned char *) calloc(10,sizeof(char));
    //in this char * const ptr2; is a constant pointer to a character array.
    // characters can be changed but the pointer cannot be changed.

    printf("****** const char * pointer example ****\n");
    memcpy((void *)ptr,(void *)array,strlen(array));
    printf("const char *ptr = %s.\n",ptr);
    //*(ptr + 2) ='x'; error: assignment of read-only location ‘*(ptr + 2)’
    ptr = array;
    printf("const char *ptr = %s.\n",ptr);

    printf("****** unsigned char * const ptr2 pointer example ****\n");
    memcpy(ptr2,"world",sizeof("world"));
    printf("ptr2=%s.\n",ptr2);
    memcpy(ptr2,"universe",sizeof("universe"));
    printf("ptr2=%s.\n",ptr2);
    //ptr2 = "123"; //error: assignment of read-only variable ‘ptr2’
    free(ptr2);
}
/*
void *ptr3 = (void *) calloc(10,sizeof(void *));
head= 0;
void add_elements_to_a_list(void *item) {
    *(ptr3+head) = (void *) item;
    head++;
}
*/
void **ptr3 = NULL;
int head = 0;
int tail = 0;
int max_q_length = 10;

void void_enqueue(void *item) {
    if(ptr3 == NULL) {
        ptr3 = calloc(max_q_length,sizeof(void *));
    }

    if ((head-tail == 1)||((head==0) && (tail==max_q_length-1))) {
        printf("Queue is full.\n");
        return;
    }

    ptr3[tail] = item;
    printf("ptr3[%d]=%p.\n",tail,ptr3[tail]);
    tail+=1;

    if (tail == max_q_length) {
        if (head == 0) {
            printf("Queue is full.\n");
            tail-=1;
            return;
        } else {
            tail=0;
            printf("Rotating tail to 0.\n");
        }
    }
}

void *void_dequeue() {
    void *node = NULL;
    if (head == tail) {
        if (!ptr3[head]) {
            printf("Queue is empty.\n");
            return NULL;
        }
    }

    node = ptr3[head];
    ptr3[head] = NULL;
    head++;
    if (head == max_q_length) {
        if (head-1 != tail) {
            head=0;
            printf("Rotating head to 0.\n");
        } else {
            head-=1; //Stay right there.
        }
    }
    return node;
}


#if 0
int main() {
    void *ptr5 = "Sriram";

    typedef struct {
        int ss;
        int ss3;
    } ss_t;
    ss_t struct_t = {1,2};

    int i = 0;
    printf("The size of void * is %ld.\n",sizeof(void*));
    printf("Address of ptr5 * is %p.\n",ptr5);
    void_enqueue(ptr5);
    printf("Address of struct_t * is %p.\n",&struct_t);
    void_enqueue(&struct_t);

    return 0;
}
#endif

void revise_pointers() {
    char *ptr = NULL, *ptr1 = NULL, *ptr2 = NULL;
    int array1[] = {1,2,3,4,5};
    char i=10;
    int index = 0;
    printf("************Pointers************************\n");
    printf("&ptr = %p.\n",&ptr);
    printf("************Wrong way of passing unallocated pointers into a function.************************\n");
    ptr = wrong_way(ptr1);
    printf("ptr1 = %s.\n",ptr1);
    printf("ptr = %s.\n",ptr);
    free(ptr);
    printf("************Correct way of passing unallocated pointers into a function.************************\n");
    pass_by_reference(&ptr2);
    printf("ptr2 = %s.\n",ptr2);
    free(ptr2);
    printf("**********Static value manipulation.**************\n");
    ptr=&i;
    printf("i = %d.\n",i);
    static_value_manipulation(ptr);
    printf("i = %d.\n",i);
    free(ptr1);
    printf("********Constant pointers and pointers to constant memory examples **********\n");
    const_pointers_example();
    printf("******** Manipulating arrays examples **********\n");
    printf("******** Before invoking manipulate_pointer_to_array **********\n");
    for(index=0; index < 5; index++) {
        printf("At index %d, value = %d.\n",index, array1[index]);
    }
    manipulate_pointer_to_array(array1);
    printf("******** After invoking manipulate_pointer_to_array **********\n");
    for(index=0; index < 5; index++) {
        printf("At index %d, value = %d.\n",index, array1[index]);
    }
    printf("**********strcat example.**************\n");
    strcat_example();
    printf("**********strtok example.**************\n");
    strtok_example();
    void *ptr5 = "Sriram";

    typedef struct {
        int ss;
        int ss3;
    } ss_t;
    ss_t struct_t = {1,2};

    printf("The size of void * is %ld.\n",sizeof(void*));
    printf("Address of ptr5 * is %p.\n",ptr5);
    void_enqueue(ptr5);
    printf("Address of struct_t * is %p.\n",&struct_t);
    void_enqueue(&struct_t);

    /*
    *(unsigned long *)ptr3++ = (unsigned long *)ptr5;
    printf("ptr3=%p,*ptr3 =%p, address of ptr5=%p \n",ptr3,
            *((unsigned long *)ptr3),
            ptr5);
    *(unsigned long *)ptr3++ = (unsigned long *)&struct_t;
    printf("ptr3=%p,*ptr3 =%p, address of struct struct_t=%p \n",ptr3,
            *((unsigned long *)ptr3),
            &struct_t);

    for (i=2; i < 10; i++) {
        //(int)(*ptr3) = i;
        *((unsigned long *)ptr3) = (unsigned long *)i;
        printf("ptr3=%p,*ptr3 =%p \n",ptr3,*((unsigned long *)ptr3));
        (unsigned long *)ptr3++;
    }
    ptr3=ptr4;
    for (i=0; i < 10; i++) {
        printf("ptr3=%p,*ptr3=%p \n",ptr3,*((unsigned long *)ptr3));
        (unsigned long *)ptr3++;
    }
     */


}