# Graph

You can compile everything by typing "make clean" , "make all"

You can compile one program individually by just typing make <Program Name>, 
for example, "make CreateGraphAndTest"

By typing "make clean"
	You delete all .o files and executables.


For part I:

 Reads a graph file and store graph in a list, and test list with adjacency file
 
 
	You need a graph file such as "Graph1.txt"
	You also need an adjacency file such as "AdjacencyQueries1.txt"
	You will type "make CreateGraphAndTest"
	To execute the code you will type "./CreateGraphAndTest Graph1.txt	AdjacencyQueries.txt"
	
For part II

 Reads a graph from graph file, and print all possible shortest path to other vertices
 
 
	You need a graph file such as "Graph1.txt"
	You also need to type in a start vertex (integer)
	You will type "make FindPaths"
	To execute the code you will type "./FindPaths Graph2.txt 1"

For part III

 Reads a graph from graph file and print ordered vertices after topological sorting, or print "Cycle Found" if there's a cycle in the graph
 
 
	You need a graph file such as "Graph1.txt" 
	You will type "TopologicalSort
	To execute the code you will type "TopologicalSort Graph1.txt"
	
	

