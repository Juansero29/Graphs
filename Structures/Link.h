//
// Created by Gerben on 17/09/2017.
//

#ifndef DEF_LINK
#define DEF_LINK

typedef struct link {
    int value;
    struct link *next;
} Link, *List;
#endif
