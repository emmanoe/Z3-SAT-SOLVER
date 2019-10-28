/*
 * @file Graph.c
 * @author Vincent Penelle (vincent.penelle@u-bordeaux.fr)
 * @brief  Structure to store a graph statically, and to access to its informations easily.
  		   Includes unary automata informations (initial and final nodes).
		   Does not contain acces functions for now.
 * @version 0.5
 * @date 2018-11-18, 2019-07-23
 * 
 * @copyright Creative Commons.
 * 
 */


#include "Graph.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printGraph(Graph graph){
	printf("nodes:\n");
	for(int i = 0; i<graph.numNodes;i++) printf("%d : %s, ",i,graph.nodes[i]);
	printf("\ninitial:\n");
	for(int i = 0; i<graph.numNodes;i++) printf("%d ",graph.initial[i]);
	printf("\nfinal:\n");
	for(int i = 0; i<graph.numNodes;i++) printf("%d ",graph.final[i]);
	printf("\nEdges:\n");
	for(int i = 0; i<graph.numNodes;i++){
		for(int j = 0; j<graph.numNodes;j++){
			printf("%d ",graph.edges[i*graph.numNodes+j]);
		}
		printf("\n");
	}
}

void deleteGraph(Graph graph){
	if(graph.edges!=NULL) free(graph.edges);
	if(graph.nodes!=NULL){
		for(int i = 0; i<graph.numNodes; i++) {
			if(graph.nodes[i]!=NULL) free(graph.nodes[i]);
		}
		free(graph.nodes);
	}

	//Pour les automates.
	if(graph.initial!=NULL) free(graph.initial);
	if(graph.final!=NULL) free(graph.final);

	graph.numEdges=0;
	graph.numNodes=0;
}

int orderG(Graph graph){
	return graph.numNodes;
}

int sizeG(Graph graph){
	return graph.numEdges;
}

bool isEdge(Graph graph, int source, int target){
	return graph.edges[(source*graph.numNodes)+target];
}

bool isSource(Graph graph, int node){
	return graph.initial[node];
}

bool isTarget(Graph graph, int node){
	return graph.final[node];
}

char* getNodeName(Graph graph, int node){
	return graph.nodes[node];
}

