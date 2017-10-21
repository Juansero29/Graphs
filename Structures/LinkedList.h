#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef DEF_BOOL
#include "bool.h"
#endif

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

List newList();

void printList(List l);

#endif
