#include "Structures/Graph.h"

int main(void)
{
    Graph g;
    g = newGraph();
    g = addNode(g, 3);
    g = deleteNode(g, 3);


    g = addNode(g, 4);
    g = addNode(g, 5);
    g = addArc(g, 4, 5);

    g = deleteArc(g, 4 , 5);
}