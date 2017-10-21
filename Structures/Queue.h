#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef DEF_LINK
#include "Link.h"
#endif

#ifndef DEF_BOOL
#include "bool.h"
#endif

#ifndef DEF_QUEUE
#define DEF_QUEUE
typedef struct {
    Link *head;
    Link *tail;
} Queue;
#endif


Queue newQueue(void);

Queue addToQueue(Queue q, int value);

Queue removeQueueHead(Queue q);

int getHeadValue(Queue q);

int queueLength(Queue q);

bool isQueueEmpty(Queue q);

void printQueue(Queue q);
