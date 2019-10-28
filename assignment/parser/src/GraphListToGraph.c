#include "GraphListToGraph.h"
#include "EdgeList.h"
#include "NodeList.h"
#include <stdlib.h>
#include <string.h>

/*
 * @brief Auxilary function to determine the index of a node name.
 * 
 * @param list the array of node to search in.
 * @param size the size of list.
 * @param target the node to search
 * @return int the index of target in list.
 */
int findNode(char **list,int size,char *target){
	for(int i = 0; i<size;i++){
		if(strcmp(list[i],target)==0) return i;
	}
	return -1;
}

Graph createGraph(GraphList source){
	Graph res;

	res.numNodes=0;
	res.numEdges=0;
	SNodeList *explore = source.nodes;

	int count = 0;
	while(explore!=NULL){
		count++;
		explore = explore->next;
	}
	res.numNodes=count;

	//printf("nodes: %d\n",count);

	res.edges = (int *)malloc(res.numNodes*res.numNodes*sizeof(int));
	res.nodes = (char **)malloc(res.numNodes*sizeof(char*));

	//Ajout pour les automates.
	res.initial = (bool *)malloc(res.numNodes*sizeof(bool));
	res.final = (bool *)malloc(res.numNodes*sizeof(bool));

	count=0;
	explore = source.nodes;
	while(explore != NULL){
		res.nodes[count] = (char *)malloc((strlen(explore->node)+1)*sizeof(char));
		strcpy(res.nodes[count],explore->node);

		//Pour les automates.
		res.initial[count] = explore->initial;
		res.final[count] = explore->final;

		count++;
		explore = explore->next;
	}

	/*for(int i = 0; i<res.numNodes;i++){
		printf("%s,",res.nodes[i]);
	}
	printf("\n");
	*/

	for(int i = 0; i<res.numNodes;i++)
		for(int j = 0; j<res.numNodes;j++)
			res.edges[i*res.numNodes+j] = 0;


	SEdgeList *exploreBis = source.edges;
	while(exploreBis != NULL){
		int n1,n2;
		n1=findNode(res.nodes,res.numNodes,exploreBis->node1);
		n2=findNode(res.nodes,res.numNodes,exploreBis->node2);
		res.edges[n1*res.numNodes+n2] = 1;
		exploreBis = exploreBis->next;
		res.numEdges++;
	}

	return res;
}