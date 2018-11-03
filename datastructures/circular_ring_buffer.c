//
// Created by sriramsridhar on 11/2/18.
//

#include "circular_ring_buffer.h"

typedef struct {
    uint8_t * buffer;
    int head;
    int tail;
    int maxlen;
} circ_buf_t;

extern long max_length;

static int enqueue(circ_buf_t *p_circ_buf, uint8_t value);
static int dequeue(circ_buf_t *p_circ_buf, uint8_t *p_value);
static void print_circular_buff(circ_buf_t *p_circ_buf);
static int enqueue_overwrite_data(circ_buf_t *p_circ_buf, uint8_t value);

static int enqueue_overwrite_data(circ_buf_t *p_circ_buf, uint8_t value)
{
    //Overwrite data if the data is not dequeued on time.
    //This is desired in cases where the consumer is not quick enough to consume the head.
    //Keep discarding items from head and keep adding new data to tail.
    //[1--head,2,3,4,5--tail], when new data comes in [6,7,8,9,10],
    //if 1 is not dequeued by the consumer on time,
    //the producer will push 6 to the tail and discard 1. In other words,
    //the sliding window of max elements, shall be moved to the latest consumer data available.
    // In this case it would be [2--head,3,4,5,6--tail]

}

static int enqueue(circ_buf_t *p_circ_buf, uint8_t value)
{
    int success = 0;

    if (!p_circ_buf) {
        return success;
    }
    //Return 0 when tail is before head.
    if (p_circ_buf->head-p_circ_buf->tail == 1) {
        return success;
    }
    //Return 0 if head is at 0 and tail is at end of the buffer.
    if ((p_circ_buf->head == 0) && (p_circ_buf->tail == p_circ_buf->maxlen)) {
        return success;
    }

    p_circ_buf->buffer[p_circ_buf->tail++] = value;

    //Reset the tail to 0 when it goes beyond the max size.
    if (p_circ_buf->tail == p_circ_buf->maxlen+1) {
        //If you reached the end and the head is still at 0, keep tail at the end.
        if (p_circ_buf->head == 0) {
            p_circ_buf->tail--;
        } else {
            //Rotate and go back to 0.
            p_circ_buf->tail = 0;
        }
    }
    success = 1;
    return success;
}

static int dequeue(circ_buf_t *p_circ_buf, uint8_t *p_value)
{
    int success = 0;

    if (!p_circ_buf || !p_value) {
        return success;
    }

    //Return 0 when the queue is empty.
    if (p_circ_buf->head == p_circ_buf->tail) {
        return success;
    }

    *p_value = p_circ_buf->buffer[p_circ_buf->head];
    p_circ_buf->buffer[p_circ_buf->head++] = (unsigned char) -1;

    //Reset the head to 0 when it goes beyond the max size.
    if (p_circ_buf->head == p_circ_buf->maxlen+1) {
        p_circ_buf->head = 0;
    }
    success = 1;
    return success;
}

static void print_circular_buff(circ_buf_t *p_circ_buf) {
    int index = 0;
    if (!p_circ_buf) {
        return;
    }
#if 0
    if (p_circ_buf->tail == p_circ_buf->head) {
        printf("Queue is empty");
    } else if (p_circ_buf->tail < p_circ_buf->head) {
        for (index = p_circ_buf->head; index <= p_circ_buf->maxlen; index++) {
            printf("Next value = %u.\n", p_circ_buf->buffer[index]);
        }
        for (index = 0; index < p_circ_buf->tail; index++) {
            printf("Next value = %u.\n", p_circ_buf->buffer[index]);
        }
    } else {
        for (index = p_circ_buf->head; index < p_circ_buf->tail; index++) {
            printf("Next value = %u.\n", p_circ_buf->buffer[index]);
        }
    }
#endif
    printf("Head = %d, Tail = %d, buffer: ",p_circ_buf->head,
            p_circ_buf->tail);
    for (index=0; index <= p_circ_buf->maxlen;index++) {
        printf("%d ",p_circ_buf->buffer[index]);
    }
    printf("\n");
}

void revise_circular_buffer()
{
    circ_buf_t *p_circ_buf = NULL;
    uint8_t index = 0, value = (unsigned char) -1;

    p_circ_buf = calloc(1, sizeof(circ_buf_t));
    p_circ_buf->maxlen = max_length;
    p_circ_buf->buffer = (unsigned char *) calloc(max_length+1,sizeof(uint8_t));

    printf("***************Circular ring buffer*************\n");

    index = 10;
    while (enqueue(p_circ_buf, index)) {
        printf("Enqueuing %d.\n",index++);
    }

    print_circular_buff(p_circ_buf);

    while (dequeue(p_circ_buf, &value)) {
        printf("Dequeued %d from the ring buffer.\n",value);
        value = (unsigned char) -1;
    }

    print_circular_buff(p_circ_buf);

    for(index=0; index < 5; index++) {
        printf("Enqueuing %d was %d.\n",index,enqueue(p_circ_buf, index));
    }

    print_circular_buff(p_circ_buf);

    for(index=0; index < 3; index++) {
        value = (unsigned char) -1;
        printf("Dequeued %d from the ring buffer was %d.\n",value, dequeue(p_circ_buf, &value));
    }

    print_circular_buff(p_circ_buf);

    for(index=0; index < 8; index++) {
        printf("Enqueuing %d was %d.\n",index,enqueue(p_circ_buf, index));
    }

    print_circular_buff(p_circ_buf);

    for(index=0; index < 3; index++) {
        value = (unsigned char) -1;
        printf("Dequeued %d from the ring buffer was %d.\n",value, dequeue(p_circ_buf, &value));
    }

    print_circular_buff(p_circ_buf);

    for(index=0; index < 5; index++) {
        printf("Enqueuing %d was %d.\n",index,enqueue(p_circ_buf, index));
    }

    print_circular_buff(p_circ_buf);

    free(p_circ_buf->buffer);
    free(p_circ_buf);
}