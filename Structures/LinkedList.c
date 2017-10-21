#include "LinkedList.h"


List newList() {
    Link *m;
    m = NULL;
    return m;
}

bool isListEmpty(List l) {
    return (bool) (l == NULL);
}

List addHead(List l, int value) {

    Link *m;
    m = (Link *) malloc(sizeof(Link));
    if (m == NULL) {
        printf("Malloc problem !\n");
        exit(1);
    }

    m->value = value;
    m->next = l;

    l = m;
    return l;
}

List removeHead(List l) {

    if (isListEmpty(l)) {
        printf("ERROR : FORBIDDEN OPERATION. \nThe list is already empty ! \n");
        exit(1);
    }
    Link *m;
    m = l;
    l = m->next;
    free(m);

    return l;
}


void printList(List l) {

    Link *m;
    m = l;
    while (m != NULL) {
        printf("%d\t", m->value);
        m = m->next;
    }
    printf("\n");
}
