#include <stdio.h>
#include <stdlib.h>

#include "Solving.h"
#include "Z3Tools.h"
#include "Graph.h"
#include "Parsing.h"

int main (int argc, char *argv[])
{
    Graph graph[argc];
    int number = 0;
    bool DisplayFormula = false;

    if(argc>1){
        for(int i=1; i<argc;i++){
            char option=*(argv[i]+1);
            switch (option)
            {
                case 'F':
                    DisplayFormula = true;
                    break;
                default:
                    graph[number] = getGraphFromFile(argv[i]) ;  
                    number ++;
                    break;
            }
        }
    }

    Graph *p = (Graph *)malloc(sizeof(Graph)*2);
    p[0] = graph[0]; p[1] = graph[1];
    Z3_context ctx = makeContext();
    printf("Noe Creating the context. Must be destroyed at the end of the program.\n");
    
    unsigned int numGraphes = 2;
    unsigned int pathLength = 3;
    Z3_ast formula = graphsToPathFormula(ctx, p, numGraphes, pathLength);
    if(DisplayFormula){
        printf("Formula is: %s \n",Z3_ast_to_string(ctx,formula));
    }
    
    Z3_lbool isSat = isFormulaSat(ctx, formula); 

    switch (isSat)
        {
        case Z3_L_FALSE:
            printf("%s is not satisfiable.\n",Z3_ast_to_string(ctx,formula));
            break;

        case Z3_L_UNDEF:
            printf("We don't know if %s is satisfiable.\n",Z3_ast_to_string(ctx,formula));
            break;

        case Z3_L_TRUE:
            printf("formula is satisfiable.\n");
            Z3_model model = getModelFromSatFormula(ctx,formula);
            
            printf("Pour un chemin de longueur %d:\n",pathLength);

            for(int i = 0; i < numGraphes; ++i){
                int index = 0;
                Graph G = p[i];
                printf("coucou\n");
                int * path = (int*)malloc(pathLength*sizeof(int)); // path is the y of the verificator(X,y)
                for(int j = 0; j < pathLength; ++j){
                    for(int q = 0; q < orderG(G); ++q){
                        Z3_ast var = getNodeVariable(ctx,i, j, pathLength, q);
                            if(valueOfVarInModel(ctx,model,var)){
                                path[index]=q;
                                printf("path[%d]: q[%d]\n", index, path[index]);
                                index++;
                            }
                            else printf("var is null\n");
                        }
                    }
                free(path);
                }
            break;
        }
    return 0;
}