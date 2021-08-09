
#include "Graph.h"


/************************************* Graph Methods**********************************/
void Graph::makeEmptyGraph(int n){
	if (adjList != NULL) {
		releaseGarph();
	}

	adjList = new NeighborsList[n + 1];
	vSize = n;
	for (int i = 1; i <= n; i++) {
		adjList[i].setHead(i);
	}
}


void Graph::releaseGarph() {
	for (int i = 0; i < vSize + 1; i++) {
		adjList[i].deleteList();
	}
	delete adjList;
	adjList = NULL;
	vSize = 0;
}

bool Graph::isAdjacent(int u, int v) {
	return adjList[u].findNeighbor(v);
}

Vertex* Graph::getAdjList(int u) {
	return adjList[u].getList();
}

bool Graph::addEdge(int u, int v) {
	return adjList[u].addNeighbor(v);
}

bool Graph::removeEdge(int u, int v) {
	return adjList[u].deleteNeighbor(v);
}

bool Graph::isEmpty() {
	return (vSize == 0);
}

/************************************* NeighborsList Methods**********************************/

void Graph::NeighborsList::setHead(int u) {
	head = u;
}

int Graph::NeighborsList::getHead() {
	return head;
}

void Graph::NeighborsList::deleteList(){
	Vertex* current = firstNeighbor;
	if (current == NULL)
		return;

	Vertex* next = current->getNext();
	while (next != NULL) {
		delete current;
		current = next;
		next = current->getNext();
	}
}

bool Graph::NeighborsList::addNeighbor(int v) {

	Vertex* newNeighbor = new Vertex(v);

	if (firstNeighbor == NULL) {
		firstNeighbor = lastNeighbor = newNeighbor;
	}
	else {
		if (firstNeighbor == lastNeighbor) {
			firstNeighbor->setNext(newNeighbor);
		}
		else {	//firstNeighbor != lastNeighbor
			lastNeighbor->setNext(newNeighbor);
			
		}
			lastNeighbor = newNeighbor;
	}
	return true;
}

bool Graph::NeighborsList::deleteNeighbor(int v) {

	//if v isn't an adjacant vertex to head, we can't delete it
	if (!findNeighbor(v))
		return false;

	Vertex* temp = firstNeighbor;
	if (v == firstNeighbor->getV())	{
		
		firstNeighbor = firstNeighbor->getNext();
		delete temp;
	}
	else {
		Vertex* prev = temp;
		while (temp->getV() != v) {
			prev = temp;
			temp = temp->getNext();
		}
		prev->setNext(temp->getNext());
		delete temp;
	}
	return true;
}

bool Graph::NeighborsList::findNeighbor(int v) {
	Vertex* itr = firstNeighbor;
	while (itr != NULL) {
		if (itr->getV() == v)
			return true;
	}
	return false;
}

Vertex* Graph::NeighborsList::getList() {
	return firstNeighbor;
}
