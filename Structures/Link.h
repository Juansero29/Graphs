
#ifndef DEF_LINK
#define DEF_LINK

typedef struct link
{
    int value;
    struct link *next;
} Link, *List;
#endif
