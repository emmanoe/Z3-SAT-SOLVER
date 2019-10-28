/**
 * @file Graph.h
 * @author Vincent Penelle (vincent.penelle@u-bordeaux.fr)
 * @brief  Structure to store a graph statically, and to access to its informations easily.
  		   Includes source and target node informations, and supports several of them.
 * @version 1
 * @date 2018-11-18, 2019-07-23, 2019-08-02
 * 
 * @copyright Creative Commons.
 * 
 */


#ifndef COCA_GRAPH_H_
#define COCA_GRAPH_H_



/** @brief: the graph type. The first four fields are needed to represent a directed graph. The rest depends on needs. Here, the rest represents initial and final states of an automaton.*/
typedef struct {
	int numNodes; ///< The number of nodes of the graph.
	int numEdges; ///< The number of edges of the graph.
	char** nodes; ///< The names of nodes of the graphs.
	int* edges;	  ///< The edges of the graph.

//This is only for dealing with automata. May be changed according to needs.
	bool *initial;	///< Array of source nodes.
	bool *final;	///< Array of target nodes.
} Graph;

/**
 * @brief Displays a graph with a list of nodes and a matrix of edges.
 * 
 * @param graph the graph to display.
 */
void printGraph(Graph graph);

/**
 * @brief Frees all memory occupied by a graph.
 * 
 * @param graph The graph to delete.
 */
void deleteGraph(Graph graph);

/**
 * @brief Returns the number of nodes of @p graph.
 * 
 * @param graph A graph.
 * @return int Its number of nodes.
 */
int orderG(Graph graph);

/**
 * @brief Returns the number of edges of @p graph.
 * 
 * @param graph A graph.
 * @return int Its number of edges.
 */
int sizeG(Graph graph);

/**
 * @brief Tells if (@p source, @p target) is an edge in @p graph.
 * 
 * @param graph A graph.
 * @param source The source of the edge.
 * @param target The target of the edge.
 * @return true If the edge is present in @p graph.
 * @return false Otherwise.
 */
bool isEdge(Graph graph, int source, int target);

/**
 * @brief Tells if @p node is source in @p graph.
 * 
 * @param graph A graph.
 * @param node A node.
 * @return true If @p node is a source.
 * @return false Otherwise.
 */
bool isSource(Graph graph, int node);

/**
 * @brief Tells if @p node is target in «graph».
 * 
 * @param graph A graph.
 * @param node A node.
 * @return true If @p node is a target.
 * @return false Otherwise.
 */
bool isTarget(Graph graph, int node);

/**
 * @brief Returns the name of a node given its identifier.
 * 
 * @param graph A graph.
 * @param node A node identifier. Must be lower than orderG(@p graph).
 * @return char* The name of @p node.
 */
char* getNodeName(Graph graph, int node);


#endif /* DOT_PARSER_GRAPH_H_ */
