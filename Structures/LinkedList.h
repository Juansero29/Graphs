#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef DEF_LINK

#include "Link.h"

#endif

#ifndef DEF_LINKEDLIST
#define DEF_LINKEDLIST
/* To start building a List, we have to define a data structure (struct) and
    a head-pointer (*). This pointer needs to be initialized to the value 'NULL', since
    the List is empty when we create it.
*/

bool isListEmpty(List l);

List addHead(List l, int value);

List removeHead(List l);

List removeValue(List l, int value);

List newList();

bool contains(List l, int x);

void printList(List l);

int getCount(List l);

List copy(List l);

int getListHeadValue(List l);

#endif
