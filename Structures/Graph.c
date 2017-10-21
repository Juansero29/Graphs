

Graphe graphenouv()
{

    Graphe g;
    g->l = newList();
    g->suiv = NULL;
    return g;
}

Graphe adjs(Graphe g, int x){

    Maillong *m;
    m = (Maillong*) malloc sizeof(Maillong);
    if (m == NULL) { printf("Malloc problem in adj sommet"); }
} 

Graphe adjst(Graphe g, int x);
Graphe sups(Graphe g, int x);
Graphe supa(Graphe g, int x, int y);
bool exs(Graphe g, int x);
bool exa(Graphe g, int x, int y);
Liste esuc(Graphe g, int x);
Liste esg(Graphe g);
int de(Graphe g);
int di(Graphe g);
void afficher();
