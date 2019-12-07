/*
 * Liulan Zheng
 * This file is used with CreateGraphAndTest.cc and TopologicalSort.cc
 * Graph only stores weight and vertex # for each vertex
*/
#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>
using namespace std;
class Graph
{
 public:
	Graph():vertex_(0), weights_(0){};
	Graph(int vertex):vertex_(vertex), weights_(0){};
	Graph(int vertex, double weight):vertex_(vertex), weights_(weight){};
	const double GetWeight() {return weights_;}
	const int GetVertex() {return vertex_;}

 private:
	int vertex_;
	double weights_;

};

#endif