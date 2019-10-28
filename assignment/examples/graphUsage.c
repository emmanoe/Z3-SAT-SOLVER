#include <stdio.h>
#include <Graph.h>
#include <Parsing.h>

void usage(){
    printf("Usage: graphParser file\n");
    printf(" Displays information on the graph discribed by file. It should be provided with a .dot file\n");
}

int main(int argc, char* argv[]){

    if(argc<2) {
        usage();
        return 0;
    }

    Graph graph;
    graph = getGraphFromFile(argv[1]);

    printGraph(graph);

    printf("detailed informations:\n");

    printf(" There are %d vertices.\n",orderG(graph));
    printf(" There are %d edges.\n",sizeG(graph));

    printf("\n Note: all graphs provided will have a single source and single target.\n");
    int node;
    for(node=0;node<orderG(graph) && !isSource(graph,node);node++);
    printf(" The source is %s.\n",getNodeName(graph,node));

    for(node=0;node<orderG(graph) && !isTarget(graph,node);node++);
    printf(" The target is %s.\n",getNodeName(graph,node));

    if(isEdge(graph,0,1)) printf(" There is an edge between %s and %s.\n",getNodeName(graph,0),getNodeName(graph,1));
    else printf("\n There is no edge between %s and %s.\n",getNodeName(graph,0),getNodeName(graph,1));

    deleteGraph(graph);
    printf("Graph successfully deleted.\n");
    return 0;
}