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

		friend ostream& operator<<(ostream& out, const NeighborsList& neighbors) {
			Vertex* temp = neighbors.firstNeighbor;
			while (temp != NULL) {
				out << neighbors.head << "," << *temp << " ";
				temp = temp->getNext();
			}
			return out;
		}
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

	int getSize();

	static Graph* getGTranspose(const Graph& g);

	friend ostream& operator<<(ostream& out, const Graph& graph) {
		for (int u = 1; u <= graph.vSize; u++) {
			out << graph.adjList[u] << endl;
		}
		return out;
	}

	int* BFS(Vertex s);

	static Graph* getGs(const Graph& g, int* d);
};



