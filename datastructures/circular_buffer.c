//
// Created by sriramsridhar on 11/2/18.
//

#include "circular_buffer.h"

typedef struct {
    uint8_t * buffer;
    int head;
    int tail;
    int maxlen;
} circ_buf_t;


static int enqueue(circ_buf_t *p_circ_buf, uint8_t value);
static int dequeue(circ_buf_t *p_circ_buf, uint8_t *p_value);
static void print_circular_buff(circ_buf_t *p_circ_buf);

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
    if ((p_circ_buf->head == 0) && (p_circ_buf->tail == p_circ_buf->maxlen-1)) {
        return success;
    }

    p_circ_buf->buffer[p_circ_buf->tail++] = value;

    //Reset the tail to 0 when it goes beyond the max size.
    if (p_circ_buf->tail == p_circ_buf->maxlen) {
        //If you reached the end and the head is still at 0, keep tail at the end.
        if (p_circ_buf->head == p_circ_buf->tail) {
            p_circ_buf->tail = p_circ_buf->maxlen-1;
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

    *p_value = p_circ_buf->buffer[p_circ_buf->head++];

    //Reset the head to 0 when it goes beyond the max size.
    if (p_circ_buf->head == p_circ_buf->maxlen) {
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
    if (p_circ_buf->tail == p_circ_buf->head) {
        printf("Queue is empty");
    } else if (p_circ_buf->tail < p_circ_buf->head) {
        for (index = p_circ_buf->head; index < p_circ_buf->maxlen; index++) {
            printf("Next value = %u.\n", p_circ_buf[index]);
        }
        for (index = 0; index <= p_circ_buf->tail; index++) {
            printf("Next value = %u.\n", p_circ_buf[index]);
        }
    } else {
        for (index = p_circ_buf->head; index <= p_circ_buf->tail; index++) {
            printf("Next value = %u.\n", p_circ_buf[index]);
        }
    }
}

void revise_circular_buffer()
{
    circ_buf_t *p_circ_buf = NULL;
    uint8_t index = 0;

    p_circ_buf = calloc(1, sizeof(circ_buf_t));
    p_circ_buf->maxlen = 8;
    p_circ_buf->buffer = (unsigned char *) calloc(8,sizeof(uint8_t));

    for(index=0; index < 10; index++) {
        printf("Enqueuing %d was %d.\n",index,enqueue(p_circ_buf, index));
    }

    print_circular_buff(p_circ_buf);

    for(index=0; index < 10; index++) {
        uint8_t value = -1;
        printf("Dequeued %d from the ring buffer was %d.\n",value, dequeue(p_circ_buf, &value));
    }

    free(p_circ_buf->buffer);
    free(p_circ_buf);
}