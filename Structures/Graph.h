#include <stdbool.h>
#include "Link.h"

#ifndef DEF_GRAPH
#define DEF_GRAPH


typedef struct gLink
{
    int v;
    List l;
    struct gLink *next;
} GLink, *Graph;


// Initializes a new graph
Graph newGraph(); // graphnouv

// Returns whether a graph 'g' is empty or not.
bool isEmpty(Graph g); //vide

// Adds a head node to a graph
Graph addHeadNode(Graph g, int x); //adjTeteSommet

// Adds a node to a graph, we suppose the node doesn't exist already in the graph
Graph addNode(Graph g, int x); //adjsommet

// Adds an arc to a graph that link values 'x' and 'y'
Graph addArc(Graph g, int x, int y); //adja

// Deletes the head node from the graph g
Graph deleteHeadNode(Graph g); //spst

// Deletes a node from the graph g containing value 'x'
Graph deleteNode(Graph g, int x); //sups

// Deletes an arc from the graph g linking values 'x' and 'y'
Graph deleteArc(Graph g, int x, int y); //supa

// Returns whether a node with this value exists or not
bool doesNodeExist(Graph g, int x); //exs

// Returns whether an arc linking values 'x' and 'y' exists or not
bool doesArcExist(Graph g, int x, int y);//exa

// Returns the set of successors of the node containing value 'x'.
List getSuccessors(Graph g, int x); //esuc

// Returns the set of nodes of the graph
List getNodes(Graph g); //ess

// Returns number of successors.
int getNumberOfSuccesors(Graph g, int x); //di (degrée interieur)

int getNumberOfPredecessors(Graph g, int x); //de (degrée exterieur)

void printGraph(Graph g); //afficher

List depthFirstSearch(Graph g, List e, List l); //parcours en profondeur

bool path(Graph g, int x, int y); //chemin, tells if there's a path between values x, y






#endif //DEF_GRAPH




