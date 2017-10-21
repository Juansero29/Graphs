
#ifndef DEF_GRAPH
#define DEF_GRAPH

#include "Bool.h"
#include "Link.h"

typedef struct maillong{
    int v;
    Liste l;
    maillong *suiv;
} Maillong, *Graphe;

Graphe graphenouv();
void afficher();
Graphe adjs(Graphe g, int x);
Graphe adjst(Graphe g, int x);
Graphe sups(Graphe g, int x);
Graphe supa(Graphe g, int x, int y);
bool exs(Graphe g, int x);
bool exa(Graphe g, int x, int y);
Liste esuc(Graphe g, int x);
Liste esg(Graphe g);
int de(Graphe g);
int di(Graphe g);

#endif //DEF_GRAPH




