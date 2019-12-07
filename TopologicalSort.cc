//Liulan Zheng
/*
 This file reads a graph file and store graph into a list
 prints order of vertices after topological sortings, 
 prints "Cycle found" if a cycle is detected
*/
 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <iterator>
#include "graph.h"
#include "vertex.h"
#include "dsexceptions.h"
#include "binary_heap.h"
using namespace std;

/*
 * Sort vertices using topologicalSort
 * prints ordered vertices or print "Cycle Found" if a cycle is found
 */
void topologicalSort(vector <Vertex> & v, list<Graph> adj_list[], const int & num)
{
	BinaryHeap<Vertex> q;
	// topological sort algorithm
	int counter = 0;
	for(unsigned int i = 0; i < v.size(); i++)
	{
		Vertex* tmp = & v[i];
		// Only vertex that has 0 indegree and unvisited can be inserted into binary heap
		if(tmp->GetIndegree() == 0 && ! (tmp->visited())) 
		{
			q.insert(*tmp);
			tmp->IsVisited();
		}
		while(!q.isEmpty())
		{
			if(counter > 0)
				cout << ", ";
			Vertex vex = q.findMin();
			q.deleteMin();
			cout << vex.GetVertex();
			counter++;
			list<Graph>::iterator itr;
			int index = vex.GetVertex() -1;
			for(itr = adj_list[index].begin(); itr != adj_list[index].end();++itr)
			{
				int j = itr->GetVertex()-1;
				Vertex* m = &v[j];
				m->DecrementIndegree();
				if(m->GetIndegree() == 0 && ! (m->visited()))
				{
					q.insert(*m);
					m->IsVisited();
				}
			}
		}
		if(counter != num)
		{
			cout << "Cycle found" << endl;
			throw CycleFoundException { };
		}
	}
	cout << "." << endl;	
}

// Helper function to create graph in a list
void addEdge(list<Graph> adjacent_list[], int vertex, const Graph & edge)
{
	vertex--;
	adjacent_list[vertex].push_back(edge);
}

// Reads graph file and store graph in a list, and vertices in binary heap (priority queue)
void CreateGraph(const string & graph_filename)
{
	ifstream file;
	string line;
	int num, vertex, adjacentV;
	double weight;
	vector<Vertex> tmp_v;
	// Reading graph file
	file.open(graph_filename);
	if(file.is_open())
	{
		getline(file, line);
		stringstream s(line);
		s >> num; 
		// store vertices in vector first then store in binary heap
		for(int i = 1; i <= num; i++)
		{
			Vertex v(i);
			tmp_v.push_back(v);
		}
		list<Graph> adjacent_list[num];
		for(int i = 0; i < num; i++)
		{
			getline(file, line);
			stringstream ss(line);
			ss >> vertex; 
			while( ss >> adjacentV >> weight)
			{
				int index = adjacentV - 1;
				tmp_v[index].IncrementIndegree(); // adjacentV has a new incoming edge
				Graph edge(adjacentV, weight);
				addEdge(adjacent_list, vertex, edge);
			}
		}
		file.close();
		
		topologicalSort(tmp_v, adjacent_list, num);
	}
	else
		cout << "Error. Unable to open graph filename." << endl;
}

int main(int argc, char **argv) 
{
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <graphfilename> " << endl;
		return 0;
	}
	
	const string graph_filename(argv[1]);
	cout << "Graph file is " << graph_filename << endl;
	CreateGraph(graph_filename);
	return 0;
}