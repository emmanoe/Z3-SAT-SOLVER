Assignment for the Complexité and Calculabilité course of the M1 informatique from University of Bordeaux.
Author: Vincent Penelle (vincent.penelle@u-bordeaux.fr)

To build: 'make'
To build only program: 'make equalPath'
To build only the doc: 'make doc'

To launch the program: './equalPath'

A working executable is given. It was compiled at CREMI, so it is wiser to use it only there. To use it: './working-equalPath'. The usage is given by the program.

Two example files are given, one to manipulate the graph structure, one to manipulate Z3, they are in the examples folder. You may play with them at your leisure.
To build the Z3 example: 'make Z3Example'
To build the graph example: 'make graphParser'

Instruction:
    You have to implement the file in Solving.c, alongside a main program in main.c using these function to solve the "Distance Commune" problem. You should add more functions than the ones given in Solving.h.
    Steps:
        - Bare minimum requirements: implement the getNodeVariable, getPathFormula and getFullFormula functions, alongside with a main using it to solve the problem with the byDepth algorithm.
        It might display the formula and the graphs parsed with the relevant option.
        - To get average: Get the model and display it on the terminal, by implementing printPathFromModels.
        - First improvement: Implement the function getFullFormula, and modify the main to use it in order to only get the answer to the problem (yes/no).
        - Second improvement: Modify the getFullFormula function in order that the model obtained only contains the paths witnessing the solution. You will need the getSolutionLengthFromModel function.
        - Third improvement: Implement the createDotFromModel to print the solution path in dot format (as done in the working executable). The .dot produced should contain the source and target information.
        You are free to use the colors you wish, but staying consistent with the examples given is great.
        - Fourth improvement: produce an executable with all the improvements, and with a behaviour similar than the working-equalPath (i.e., treating options on the terminal to choose which version of the algorithm
        to use and which information to display).
    
    The third improvement being independent from the first two, it can actually be implemented as first or second improvement if desired. The fourth improvement might be implemented alongside the program, i.e., you might
    implement the treatment of option even if your program is not supporting them all.

