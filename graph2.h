/*
 * Liulan Zheng
 * This file is used with FindPaths.cc
 * Graph2 keeps track of vertex's distance, weight, previous vertex, and vertex #
*/
#ifndef GRAPH2_H
#define GRAPH2_H
#include <string>
#include <vector>
using namespace std;
class Graph2
{
 public:
	const double INFINITY = 1e9+7;
	void defaultValue()
	{
		previous_vertex_ =0;
		distance_ = INFINITY;
	}
	// Constructors
	Graph2():vertex_(0), weights_(0){ defaultValue(); }
	Graph2(int vertex): vertex_(vertex), weights_(0){ defaultValue(); }
	Graph2(int vertex, double weight): vertex_(vertex), weights_(weight){ defaultValue(); }
	
	
	void setDistance(double distance){ distance_ = distance; }
	void setPreviousV(int previous_vertex){ previous_vertex_ = previous_vertex; }
	const double GetWeight() { return weights_; }
	const int GetVertex() { return vertex_; }
	const double GetDistance() { return distance_; }
	const int GetPreviousV() { return previous_vertex_; }
	
	//Overloading < 
	friend bool operator<(const Graph2 &lhs, const Graph2& rhs) 
	{
		if(lhs.distance_ < rhs.distance_)
			return true; 
		else 
			return false;
	}
	// Move Assignmet
	Graph2& operator=(const Graph2 &rhs) 
	{
		this->vertex_ = rhs.vertex_;
		this->weights_ = rhs.weights_;
		this->distance_ = rhs.distance_;
		this->previous_vertex_ = rhs.previous_vertex_;
		return *this;
	}

 private:
	int vertex_;
	double weights_;
	double distance_;
	int previous_vertex_;
	
};

#endif