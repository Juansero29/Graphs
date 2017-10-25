#include "LinkedList.h"


List newList()
{
    Link *m;
    m = NULL;
    return m;
}

bool isListEmpty(List l)
{
    return (bool) (l == NULL);
}

List addHead(List l, int value)
{

    Link *m;
    m = (Link *) malloc(sizeof(Link));
    if (m == NULL)
    {
        printf("Malloc problem !\n");
        exit(1);
    }

    m->value = value;
    m->next = l;

    l = m;
    return l;
}

List removeHead(List l)
{

    if (isListEmpty(l))
    {
        printf("ERROR : FORBIDDEN OPERATION. \nThe list is already empty ! \n");
        exit(1);
    }
    Link *m;
    m = l;
    l = m->next;
    free(m);

    return l;
}


void printList(List l)
{

    Link *m;
    m = l;
    while (m != NULL)
    {
        printf("%d\t", m->value);
        m = m->next;
    }
    printf("\n");
}

List removeValue(List l, int value)
{
    if (isListEmpty(l))
    { return l; }

    if (!contains(l, value))
    { return l; }

    Link *m;
    m = l;
    while (m->value != value)
    {
        m = m->next;
    }
    l = addHead(m->next, m->next->value);
    free(m);
    return l;

    //TODO THIS CAN BE SOURCE OF PROBLEMS
}

bool contains(List l, int x)
{
    if (isListEmpty(l))
    { return false; }

    if(l->value == x)
    {return true;}

    return contains(l->next, x);

}

int getCount(List l)
{
    int count = 0;  // Initialize count
    Link* current = l;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

List copy(List l)
{
    if(isListEmpty(l))
    {
        return newList();
    }

    List copy;
    copy = l;
    return copy;
}

int getListHeadValue(List l)
{
    if(isListEmpty(l))
    {
        printf("ERROR: Can't get the head value of an empty list! EXITING. ");
        exit(1);
    }
    return l->value;
}
