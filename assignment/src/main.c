#include <stdio.h>
#include <stdlib.h>

#include "Solving.h"
#include "Z3Tools.h"
#include "Graph.h"
#include "Parsing.h"

int main (int argc, char *argv[])
{
    Graph graph0 = getGraphFromFile(argv[1]) ;  
    Graph graph1 = getGraphFromFile(argv[2]) ;
    Graph *p = (Graph *)malloc(sizeof(Graph)*2);
    //p[0] = malloc(sizeof(Graph));
    //p[1] = malloc(sizeof(Graph));

    p[0] = graph0; p[1] = graph1;
    Z3_context ctx = makeContext();
    printf("Noe Creating the context. Must be destroyed at the end of the program.\n");
    
    unsigned int numGraphes = 2;
    unsigned int pathLengt = 3;
    Z3_ast formula = graphsToPathFormula(ctx, p, numGraphes, pathLengt);
    return 0;
}