#pragma once

#include "Vertex.h"


class Graph {
private:

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

		void setHead(int u);

		int getHead();

		void deleteList();

		bool addNeighbor(int v);

		bool deleteNeighbor(int v);

		bool findNeighbor(int v);

		Vertex* getList();
	};


	NeighborsList* adjList;
	int vSize;

public:
	Graph(int n){
		makeEmptyGraph(n);
	}

	Graph():vSize(0),adjList(NULL) {}

	~Graph() {
		if (adjList != NULL)
			releaseGarph();
	}

	void makeEmptyGraph(int n);

	void releaseGarph();

	bool isAdjacent(int u, int v);

	Vertex* getAdjList(int u);

	bool addEdge(int u, int v);

	bool removeEdge(int u, int v);

	bool isEmpty();

	static Graph* getGTranspose(Graph g);

};



