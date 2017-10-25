#include "Graph.h"
#include "LinkedList.h"

Graph newGraph()
{

    Graph g;
    g->l = newList();
    g->v = NULL;
    g->next = NULL;
    g = NULL;
    return g;
}

bool isEmpty(Graph g)
{
    return g == NULL;
}

// Adds a node to a graph, we suppose the node doesn't exist already in the graph
Graph addHeadNode(Graph g, int x)
{
    GLink *gLink1;
    gLink1 = (GLink *) malloc(sizeof(GLink));
    if (gLink1 == NULL)
    {
        printf("MALLOC problem in 'addNode' function when adding value %d", x);
        exit(1);
    }
    gLink1->v = x;
    gLink1->l = newList();
    gLink1->next = g;
    return gLink1;
} //adjTetesommet



Graph addNode(Graph g, int x)
{
    if (isEmpty(g))
    { return addHeadNode(g, x); }
    if (x < g->v)
    { return addHeadNode(g, x); }
    if (x == g->v)
    { return g; }

    g->next = addNode(g->next, x);

    return g;
}

Graph addArc(Graph g, int x, int y)
{
    if (!doesNodeExist(g, x) || !doesNodeExist(g, y))
    {
        return g;
    }

    Graph aux;
    aux = g;
    while (aux->v != x)
    {
        aux = aux->next;
    }

    aux->l = addHead(aux->l, y);
    return g;
}

Graph deleteHeadNode(Graph g)
{
    GLink *gl;
    if (isEmpty(g))
    {
        printf("FORBIDDEN OPERATION in function 'deleteHeadNode'. Can't delete the head of an empty graph. EXITING.");
        exit(1);
    }

    gl = g;
    g = g->next;
    free(gl);
    return g;
} //supst

// Deletes a node from the graph g containing value 'x'
Graph deleteNode(Graph g, int x)
{
    if (!doesNodeExist(g, x))
    { return g; }
    if (getNumberOfSuccesors(g, x) != 0 || getNumberOfPredecessors(g, x) != 0)
    { return g; }

    // The node exists and it's isolated.

    if (x == g->v)
    { return deleteHeadNode(g); }

    g->next = deleteNode(g->next, x);

    return g;
} //sups

// Deletes an arc from the graph g linking values 'x' and 'y'
Graph deleteArc(Graph g, int x, int y)
{
    GLink *gl;
    if (!doesArcExist(g, x, y))
    { return g; }

    gl = g;

    while (gl->v != x)
    {
        gl = gl->next;
    }

    gl->l = removeValue(gl->l, y);
    return gl;
} //supa

// Returns whether a node with this value exists or not
bool doesNodeExist(Graph g, int x)
{
    if (isEmpty(g))
    { return false; }
    if (x < g->v)
    { return false; }
    if (x == g->v)
    { return true; }
    return doesNodeExist(g->next, x);
} //exs

// Returns whether an arc linking values 'x' and 'y' exists or not
bool doesArcExist(Graph g, int x, int y)
{
    if (!doesNodeExist(g, x) || !doesNodeExist(g, y))
    {
        return false;
    }

    while (g->v != x)
    { g = g->next; }

    return contains(g->l, x);
}//exa

// Returns the set of successors of the node containing value 'x'.
List getSuccessors(Graph g, int x)
{
    if (!doesNodeExist(g, x))
    {
        printf("The specified node doesn't exist. \n ");
        return newList();
    }
    while (g->v != x)
    {
        g = g->next;
    }

    return g->l;
}//esuc

// Returns the set of values of the nodes of the graph
List getNodes(Graph g)
{
    List l;
    l = newList();
    while (!isEmpty(g))
    {
        l = addHead(l, g->v);
        g = g->next;
    }
    return l;
} //ess

// Returns number of successors.
int getNumberOfSuccesors(Graph g, int x)
{
    int i = 0;
    while (!isEmpty(g))
    {
        if (contains(g->l, x))
        {
            i++;
        }
        g = g->next;
    }
    return i;
} //di (degrée interieur)

// Returns number of predecessors
int getNumberOfPredecessors(Graph g, int x)
{
    if (!doesNodeExist(g, x))
    {
        return 0;
    }

    while (g->v != x)
    {
        g = g->next;
    }

    return getCount(g->l);
} //de (degrée exterieur)

void printGraph(Graph g)
{
    FILE *f;
    Graph aux;
    aux = g;
    f = fopen("../graph.txt", "w");
    if (f == NULL)
    {
        printf("Probleme when opening file 'graph.txt'. Does the file exist inside the Graphs folder? Path should be: Graphs/graph.txt. EXITING. \n");
        exit(1);
    }
    fprintf(f, "digraph family\n{\n");

    while(!isEmpty(g))
    {
        fprintf(f, "%d[label = \"Node%d\"]\n", g->v, g->v);
        g = g->next;
    }

    int y = 0;
    while(!isEmpty(aux))
    {
        List l1 = copy(aux->l);
        while(!isListEmpty(l1))
        {
            y = getListHeadValue(l1);
            l1 = removeHead(l1);
            fprintf(f, "%d->%d\n", aux->v, y);
        }
        aux = aux->next;
    }
    fprintf(f, "}\n");
    fclose(f);
    system("dotty graph.txt");
}

List depthFirstSearch(Graph g, List e, List l)
{
    List l1 = newList();
    int z;

    if(isListEmpty(e)) { return l;}

    z = getListHeadValue(e);

    if(contains(l, z)) { l1 = l; }

    else { l1 = depthFirstSearch(g, getSuccessors(g, z), addHead(l, z));}

    return depthFirstSearch(g, removeValue(l, z), l1);
}

bool path(Graph g, int x, int y)
{
    List l, l1;

    l1 = newList();
    l1 = addHead(l, x);
    l = depthFirstSearch(g, l1, newList());
    return contains(l, y);
}
//afficher

