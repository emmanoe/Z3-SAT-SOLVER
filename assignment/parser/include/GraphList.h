/**
 * @file GraphList.h
 * @author Vincent Penelle (vincent.penelle@u-bordeaux.fr)
 * @brief  Structure to store a graph that can be dynamically modified. Used as a temporary structure during parsing before translating into a more static structure.
 * @version 1
 * @date 2019-07-22
 * 
 * @copyright Creative Commons.
 * 
 */

#ifndef COCA_GRAPHLIST_H_
#define COCA_GRAPHLIST_H_

#include "EdgeList.h"
#include "NodeList.h"

/**
 * @brief The EdgeList structure. Contains a list of nodes and a list of edges.
 */
typedef struct tagGraphList
{
	SNodeList *nodes;
    SEdgeList *edges;
} GraphList;


#endif /* DOT_PARSER_GRAPHLIST_H_ */
