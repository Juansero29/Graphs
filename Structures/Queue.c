#include "Queue.h"

Queue newQueue(void)
{
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    return q;
}

bool isQueueEmpty(Queue q)
{
    return (bool) (q.head == NULL && q.tail == NULL);
}

int queueLength(Queue q)
{
    int count = 0;
    Link *l;
    l = q.head;
    while (l != NULL) {
        count++;
        l = l->next;
    }
    return count;
}

Queue addToQueue(Queue q, int value)
{

    // We create a link to be added to the queue.
    Link *l;
    l = (Link *) malloc(sizeof(Link));

    // We verify if the malloc was succesful.
    if (l == NULL) {
        printf("MALLOC PROBLEM. FORCE QUITTING...");
        exit(1);
    }


    // If it was, we can put data inside it...
    l->value = value;
    l->next = NULL;

    // If the list is empty, we point the head and tail to the new link.
    if (isQueueEmpty(q)) {
        q.head = l;
        q.tail = l;
        return q;
    }

    // If it isn't empty, we have to point the last link's next pointer to the new link and
    // then point the tail to the new link.

    q.tail->next = l;
    q.tail = l;
    return q;
}


Queue removeQueueHead(Queue q)
{

    // If the queue is empty, it has no sense to delete anything at all...

    if (isQueueEmpty(q)) {
        printf("The list is empty. Forbidden operation. FORCE QUITTING. \n");
        exit(1);
    }

    // If the queue contains only one element, we free it and we return a new queue...

    if (q.head == q.tail) {
        free(q.head);
        return newQueue();
    }

    // If the queue contains more than one element, we save the head element adress, 
    // we point the head to the saved element's next pointer (to have a new head) 
    // and we free the saved element (freeing as well the ex-head element).

    Link *l;
    l = q.head;
    q.head = q.head->next;
    free(l);
    return q;
}

int getQueueHeadValue(Queue q)
{
    if (isQueueEmpty(q)) {
        printf("ERROR: Can't get the head value of an empty queue! EXITING. ");
        exit(1);
    }
    return (q.head)->value;
}

void printQueue(Queue q)
{
    Link *current;
    current = q.head;
    while (current != NULL) {
        printf("%d \n", current->value);
        current = current->next;
    }
}

