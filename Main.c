#include "Structures/Graph.h"
#include <stdio.h>

int main(void)
{
    Graph g;
    g = newGraph();
    g = addNode(g, 3);
    g = deleteNode(g, 3);

    g = addNode(g, 4);
    g = addNode(g, 5);
    g = addNode(g, 3);


    g = addArc(g, 4, 5);
    g = addArc(g, 3, 4);

    bool b;

    b = path(g, 3, 5);
    if(b){ printf("There's a path between 3 and 5");} else { printf("There's no path between 3 and 5");}

    printGraph(g);
}