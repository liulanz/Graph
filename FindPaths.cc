//Liulan Zheng
/*
 This file reads a graph file and store vertices in list:
	first line of the graph file is a number that tells how many vertices are there,
	other lines are in a format of:
	<vertex> <connected	vertex 1> <weight 1> <connected	vertex 2> <weight 2> …
 This file reads a graph file and print all possible shortest path from 
	start_vertex to other vertices using Dijkstra’s	Algorithm, with priority_queue(binary heap
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <iterator>
#include <vector>
#include "graph2.h"
#include "binary_heap.h"
using namespace std;

// Printing all possible shortest path from start_vertex to other vertices and costs of the path in recursive call
void DisplayShortestPath(const vector<Graph2>& path, const int & start_vertex, const int & currentV, double & cost)
{
	int index ;
	for(unsigned int i =0; i < path.size(); i++)
	{
		Graph2 k= path[i];
		if(currentV==k.GetVertex())
		{
			index = i;
			break;
		}
	}
	Graph2 g = path[index];
	if(currentV == start_vertex)
	{
		cout << currentV << " ";
		return;
	}
	else if(g.GetPreviousV() == start_vertex)
	{
		cost = max(g.GetDistance() , cost);
		DisplayShortestPath(path, start_vertex, g.GetPreviousV(), cost );
		cout << currentV << " ";
	}
	else 
	{
		cost = max(g.GetDistance() ,cost);
		
		DisplayShortestPath(path, start_vertex, g.GetPreviousV(), cost );
		cout << currentV << " ";
	}
}

// If element is contains in visitedV return True else return false
bool Visited(const vector<int>& visitedV, const int & element)
{
	for(unsigned int i =0; i < visitedV.size(); i++)
	{
		if(visitedV[i] == element)
			return true;
	}
	return false;
}

/**
 * Storing shortest path using Dijkstra’s Algorithm
 */
void Path(list<Graph2> adj_list[], const int & start_vertex, const int & num)
{
	const double Infinity = 1e9+7;
	BinaryHeap<Graph2> graphHeap;
	Graph2 g(start_vertex);
	g.setDistance(0); // setting start_vertex distance to 0
	graphHeap.insert(g);
	vector<Graph2> shortestPath;
	vector<int> visitedV ;
	list<Graph2>::iterator itr;
	
	// Using priority_queue(binary heap) to store shortest path
	while(!graphHeap.isEmpty()) 
	{
		Graph2 g = graphHeap.findMin();
		graphHeap.deleteMin();
		int index = g.GetVertex()-1;
		if(!Visited(visitedV, index)) // Store unvisted vertex only
			shortestPath.push_back(g);
		visitedV.push_back(index);
		for(itr = adj_list[index].begin(); itr != adj_list[index].end();++itr)
		{
			int vertex = itr->GetVertex() -1;
			if(itr->GetDistance() == Infinity && !(Visited(visitedV, vertex)))
			{
				itr->setDistance(g.GetDistance() + itr->GetWeight());
				itr ->setPreviousV(g.GetVertex());
				graphHeap.insert(*itr);
			}
		}
	}
		for(unsigned int i = 0; i < shortestPath.size(); i++)
		{
			double cost = 0;
			cout << shortestPath[i].GetVertex() << ": ";
			DisplayShortestPath(shortestPath, start_vertex,shortestPath[i].GetVertex() , cost);
			cout << "(Cost: "<< cost <<")"<<endl;
		}
}

// Helper functon for creating list
void addEdge(list<Graph2> adjacent_list[], int vertex, const Graph2 & edge)
{
	vertex--;
	adjacent_list[vertex].push_back(edge);
}

/**
 * This function reads graph file and store into a list 
 */
void CreateGraph(const string & graph_filename, const int & start_vertex)
{
	ifstream file;
	string line;
	int num, vertex, adjacentV;
	double weight;
	
	// Read graph file
	file.open(graph_filename);
	if(file.is_open())
	{
		getline(file, line);
		stringstream s(line);
		s >> num; 
		list<Graph2> adjacent_list[num];
		for(int i = 0; i < num; i++)
		{
			getline(file, line);
			stringstream ss(line);
			ss >> vertex; 
			while( ss >> adjacentV >> weight)
			{
				Graph2 edge(adjacentV, weight);
				addEdge(adjacent_list, vertex, edge);
			}
		}
		file.close();
		
		// if start_vertex doesn't exit in list print invalid, else print paths
		if(start_vertex < 1 || start_vertex > num )
			cout << "Invalid start vertex. " << endl;
		else
			Path(adjacent_list, start_vertex, num);
	}
	else
		cout << "ERROR. Unable to open graph file. " << endl;
}

int main(int argc, char **argv) 
{
	if (argc != 3) {
		cout << "Usage: " << argv[0] << " <graphfilename> <starting_vertex> " << endl;
		return 0;
	}
    const string graph_filename = string(argv[1]);
	const int start_vertex = stoi(string(argv[2]));
	cout << "Graph file is " << graph_filename << endl;
	cout << "Starting vertex "<< start_vertex << endl;

	CreateGraph(graph_filename, start_vertex);
	return 0;
}
