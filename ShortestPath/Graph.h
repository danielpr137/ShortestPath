#pragma once

#include "Vertex.h"

class Graph {
private:
	Vertex* AdjList;
	int vSize;

public:
	Graph(int n){
		makeEmptyGraph(n);
	}

	Graph() :Graph(0) {}

	~Graph() {
		for (int i = 0; i < vSize; i++) {
			releaseVList(i);
		}
	}

	void makeEmptyGraph(int n);

	void releaseVList(int index);
};


