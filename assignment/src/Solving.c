#include "Solving.h"
#include "Z3Tools.h"

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Generates a formula consisting of a variable representing the fact that @p node of graph number @p number is at position @p position of an accepting path.
 * 
 * @param ctx The solver context.
 * @param number The number of the graph.
 * @param position The position in the path.
 * @param k The mysterious k from the subject of this assignment.
 * @param node The node identifier.
 * @return Z3_ast The formula.
 */
Z3_ast getNodeVariable(Z3_context ctx, int number, int position, int k, int node)
{
  char buff[32];
  snprintf(buff,32,"x%d.%d.%d.%d", number, position, k, node); 
  return mk_bool_var(ctx,buff);
}

/**
 * @brief Generates a SAT formula satisfiable if and only if all graphs of @p graphs contain an accepting path of length @p pathLength.
 * 
 * @param ctx The solver context.
 * @param graphs An array of graphs.
 * @param numGraphs The number of graphs in @p graphs.
 * @param pathLength The length of the path to check.
 * @return Z3_ast The formula.
 */
Z3_ast graphsToPathFormula( Z3_context ctx, Graph *graphs,unsigned int numGraphs, int pathLength)
{
    // arrays that store literals, clause and subformulas for generate formula to the path formula
    Z3_ast subphi1 [numGraphs]; 
    Z3_ast literalj [pathLength+1]; // verify variable for each path value
    Z3_ast literall [pathLength+1];
    Z3_ast clause [pathLength+1]; // compare each variable 2 by 2 clause
    Z3_ast clause_array [pathLength+1];
    Z3_ast cnf [pathLength+1];

	// subformula phi1 : for each graphs, for each node in graphs path, node can't be at position j and l at the same time
    for (int i = 0; i<numGraphs; i++){
        int index=0;
        for (int q=0; q<orderG(graphs[i]); q++){
            for (int j=0; j<=pathLength; j++){ // for node q at pos j
                literalj[j] = Z3_mk_not(ctx,getNodeVariable(ctx,i,j,pathLength,q)); 
                for (int l=0; l<=pathLength; l++){ // check if q is at pos l
                    if(l!=j){ // if j not equl l
                        literall[l] = Z3_mk_not(ctx,getNodeVariable(ctx,i,l,pathLength,q));
                        Z3_ast or_set[2] = {literalj[j],literall[l]};
                        clause[l] = Z3_mk_or(ctx, 2, or_set);
                        }
                    else if(l==j){
                        Z3_ast True = mk_bool_var(ctx,"True");
                        literall[l] = True;
                        Z3_ast or_set[2] = {True,True};
                        clause[l] = Z3_mk_or(ctx, 2, or_set);
                    }
                }
                clause_array[j] = Z3_mk_and(ctx, pathLength+1, clause);
            }
            //for (int cpt=0; cpt<index; cpt++)
            //   printf("clause_array[%d]: %s \n",cpt,Z3_ast_to_string(ctx,clause_array[cpt]));            
            cnf[q] = Z3_mk_and(ctx,pathLength+1,clause_array);
            printf("cnf[%d]: %s \n",q,Z3_ast_to_string(ctx,cnf[q]));   
        }
        subphi1[i] = Z3_mk_and(ctx,numGraphs,cnf); 
        printf("subphi1: %s \n",Z3_ast_to_string(ctx,subphi1[i]));  
        //Other phi formulas to write
        //    }
    }
    return 0;
}

/**
 * @brief Generates a SAT formula satisfiable if and only if all graphs of @p graphs contain an accepting path of common length.
 * 
 * @param ctx The solver context.
 * @param graphs An array of graphs.
 * @param numGraphs The number of graphs in @p graphs.
 * @return Z3_ast The formula.
 */
Z3_ast graphsToFullFormula( Z3_context ctx, Graph *graphs,unsigned int numGraphs)
{
    return 0;
}

/**
 * @brief Gets the length of the solution from a given model.
 * 
 * @param ctx The solver context.
 * @param model A variable assignment.
 * @param graphs An array of graphs.
 * @return int The length of a common simple accepting path in all graphs from @p graphs.
 */ 
int getSolutionLengthFromModel(Z3_context ctx, Z3_model model, Graph *graphs)
{
    return 0;
}

/**
 * @brief Displays the paths of length @p pathLength of each graphs in @p graphs described by @p model.
 * 
 * @param ctx The solver context.
 * @param model A variable assignment.
 * @param graphs An array of graphs.
 * @param numGraph The number of graphs in @p graphs.
 * @param pathLength The length of path.
 */
void printPathsFromModel(Z3_context ctx, Z3_model model, Graph *graphs, int numGraph, int pathLength)
{
    return ;
}

/**
 * @brief Creates the file ("%s-l%d.dot",name,pathLength) representing the solution to the problem described by @p model, or ("result-l%d.dot,pathLength") if name is NULL.
 * 
 * @param ctx The solver context.
 * @param model A variable assignment.
 * @param graphs An array of graphs.
 * @param numGraph The number of graphs in @p graphs.
 * @param pathLength The length of path.
 * @param name The name of the output file.
 */
void createDotFromModel(Z3_context ctx, Z3_model model, Graph *graphs, int numGraph, int pathLength, char* name)
{
    return ;
}