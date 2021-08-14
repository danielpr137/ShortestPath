#pragma once

#include "Vertex.h"
#include "Util.h"


//A Class to represent the ADT Graph using an adjacency list
class Graph {
private:

	//An inner wrapper Class in Graph that represent the Adjacency list for each vertex in the Graph
	class NeighborsList {
	private:
		int head;
		Vertex* firstNeighbor;
		Vertex* lastNeighbor;

	public:
		NeighborsList() :firstNeighbor(NULL), lastNeighbor(NULL), head(0) {}
		~NeighborsList() {
			if (firstNeighbor != NULL) {
				deleteList();
				firstNeighbor = lastNeighbor = NULL;
			}
		}

		//setter for the value of the vertex, all the other vertexes in the list are adjacent to.
		void setHead(int u);

		//getter for the value of the vertex, all the other vertexes in the list are adjacent to.
		int getHead();

		//this method deletes the correspondent adjacency list for a certain vertex
		void deleteList();

		//a method that adds another vertex node v to the end of the list
		//returns true if operation was successful, and false if failed
		bool addNeighbor(int v);

		//search and removes vertex v from the list if exists
		//returns true if operation was successful, and false if failed
		bool deleteNeighbor(int v);

		//search if the vertex node exists in the list
		//returns true if it is, and false if isn't
		bool findNeighbor(int v);

		//getter for the linked list represnting th adjacency list for the main vertex (head)
		Vertex* getList();


		//print operator overloading
		friend ostream& operator<<(ostream& out, const NeighborsList& neighbors) {
			Vertex* temp = neighbors.firstNeighbor;
			while (temp != NULL) {
				out << neighbors.head << " " << *temp << endl;
				temp = temp->getNext();
			}
			return out;
		}
	};


	NeighborsList* adjList;
	int vSize;

public:
	//constructor to builed a new edge-free graph with n vertexes (1,2,3,...,n)
	Graph(int n){
		makeEmptyGraph(n);
	}

	Graph():vSize(0),adjList(NULL) {}

	~Graph() {
		if (adjList != NULL)
			releaseGarph();
	}

	//this method recieves the number of vertexes that would be in the graph
	//then procceeds to get the edges information from stdin
	void readGraph(int n);

	//this method builed/re-builed an edge-free graph with n vertexes (1,2,3,...,n)
	void makeEmptyGraph(int n);

	//handle and deletes the graph inner members
	void releaseGarph();

	//boolean methid that recieve vertex u and vertex v, 
	//return true only if the edge (u,v) exist in the graph
	//elsewise return false
	bool isAdjacent(int u, int v);

	//returns the linked list represnting the adjacency list for the vertex u
	Vertex* getAdjList(int u);
	
	//add the edge (u,v) to the graph
	//returns true if operation was successful, and false if failed
	bool addEdge(int u, int v);

	//removes the edge (u,v) to the graph
	//returns true if operation was successful, and false if failed
	bool removeEdge(int u, int v);
	 
	//returns true only if the graph has no vretexes in it (hence empty)
	//elsewise return false
	bool isEmpty();

	//getter for the amount of vertexes listed in the graph
	int getSize();


	//print operator overloading
	friend ostream& operator<<(ostream& out, const Graph& graph) {
		for (int u = 1; u <= graph.vSize; u++) {
			if(graph.adjList[u].getList()!=NULL)
				out << graph.adjList[u] ;
		}
		return out;
	}

	//a method that recieves a vertex s in the graph,
	//and returns an int array d[] that reprsents for each vertex on the graph its distance from s
	//i.e. if s=1 and the edge (1,2) is in the graph => d[1] == 0; d[2] == 1;
	//the method utilizes the BFS algorithm, hence it's name
	int* BFS(Vertex s);

	//static functiong the recieves Graph g, and build it's transpose version 'Gt'
	//returns the pointer to Gt
	static Graph* getGTranspose(const Graph& g);

	//this static method recieves a Graph g and and array d[] (the oucome of g.BFS(s))
	//and returns the spanning tree of g that has shortest paths from s to every other vertex in g
	static Graph* getGs(const Graph& g, int* d);
};



