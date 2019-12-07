/*
 * Liulan Zheng
 * Class Vertex stores a vertex #, vertex's indegree, and if vertex is visited or not1
 * This file is used with TopologicalSort.cc
 */
#ifndef VERTEX_H
#define VERTEX_H
#include <string>
#include <vector>

using namespace std;
class Vertex
{
 public:
	Vertex():vertex_(0), indegree_(0), visited_(false) {};
	Vertex(int vertex):vertex_(vertex), indegree_(0), visited_(false) {};
	const int GetVertex() { return vertex_; }
	void IncrementIndegree() { indegree_++; }
	void DecrementIndegree() { indegree_--; }
	void IsVisited() { visited_ = true; }
	const bool visited() { return visited_; }
	const int GetIndegree() { return indegree_; }
	
	// overloading operator < 
	friend bool operator<(const Vertex &lhs, const Vertex& rhs) 
	{
		if(lhs.indegree_< rhs.indegree_)
			return true; 
		else 
			return false;
	}
	
	// Move assignment
	Vertex& operator=(const Vertex &rhs) 
	{
		this->vertex_ = rhs.vertex_;
		this->indegree_ = rhs.indegree_;
		return *this;
	}
 private:
	int vertex_;
	int indegree_;
	bool visited_;
	
	
		
		

};
#endif