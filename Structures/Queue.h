#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef DEF_LINK

#include "Link.h"

#endif

#ifndef DEF_QUEUE
#define DEF_QUEUE
typedef struct
{
    Link *head;
    Link *tail;
} Queue;
#endif


Queue newQueue(void);

Queue addToQueue(Queue q, int value);

Queue removeQueueHead(Queue q);

int getQueueHeadValue(Queue q);

int queueLength(Queue q);

bool isQueueEmpty(Queue q);

void printQueue(Queue q);
