//Liulan Zheng
/*
 This file reads a graph file and store vertices in list:
	first line of the graph file is a number that tells how many vertices are there,
	other lines are in a format of:
	<vertex> <connected	vertex 1> <weight 1> <connected	vertex 2> <weight 2> …
	
 This file will read an adjacency file to test if the list is correct
	each line of adjacency file contains two vertex #
	Program will print "Connected" if two vertices are adjacent; otherwise print "not Connected"
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <iterator>
#include "graph.h"
using namespace std;

/**
 * Check if v1 and v2 are adjacent vertices
 * Print "Connected" and the distance between two vertices if they are adjacent
 * Otherwise print "Not connected"
 */
void VerticesConnection(list<Graph> adj_list[], int v1, const int & v2)
{
	list<Graph>::iterator itr;
	v1--;
	for(itr = adj_list[v1].begin(); itr != adj_list[v1].end();++itr)
	{
		if(itr -> GetVertex() == v2)
		{
			cout << " Connected, weight of edge is " << itr -> GetWeight() << endl;
			return;
		}
	}
	cout << "Not connected" << endl;
}

// Updating list by pushing new Graph object in list 
void addEdge(list<Graph> adjacent_list[], int vertex, const Graph & edge)
{
	vertex--;
	adjacent_list[vertex].push_back(edge);
} 

/**
 * Creating a list from graph file and test list
 * @num: total number of vertices 
 * @vertex: vertex number (e.g. V1 as a vertex of 1)
 * @adjacentV: an adjacent vertex of vertex
 * @vertex2: second vertex in adjacent file
 * 
 */ 
void CreateGraph(const string & graph_filename, const string & adjacency_filename)
{
	ifstream file, adj_file;
	string line;
	int num, vertex, adjacentV, vertex2;
	double weight;
	
	// Reading graph file
	file.open(graph_filename);
	if(file.is_open())
	{
		getline(file, line);
		stringstream s(line);
		s >> num; // reading first number from graph file, which tells how many vertices there are
		list<Graph> adjacent_list[num];
		for(int i = 0; i < num; i++)
		{
			getline(file, line); 
			stringstream ss(line);
			ss >> vertex;   
			while( ss >> adjacentV >> weight)
			{
				Graph edge(adjacentV, weight); // Create Graph object and store into the list
				addEdge(adjacent_list, vertex, edge);
			}
		}
		file.close();
		
		// Reading adjacent file
		adj_file.open(adjacency_filename);
		if(adj_file.is_open())
		{
			while(getline(adj_file, line))
			{
				stringstream s2(line);
				s2 >> vertex >> vertex2;   
				cout << vertex << " " << vertex2 << ":";
				if(vertex < num)
					VerticesConnection(adjacent_list, vertex, vertex2); 
				else
					cout << "Not connected" << endl;	
			}
			adj_file.close();
		}
		else
			cout << "Error. Unable to open adjacency file. " << endl;
	}
	else
		cout << "ERROR. Unable to open graph file. " << endl;
}

int main(int argc, char **argv) 
{
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <graphfilename> <adjacencyfilename> " << endl;
		return 0;
	}
	const string graph_filename(argv[1]);
	const string adjacency_filename(argv[2]);
	cout << "Graph file is " << graph_filename << ", and adjacency file is " << adjacency_filename << endl;
	CreateGraph(graph_filename, adjacency_filename);
	return 0;
}
