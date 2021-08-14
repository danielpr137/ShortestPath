
#include "Graph.h"
#include "Queue.h"


/************************************* Graph Methods**********************************/

void Graph::readGraph(int n) {

	int u;  //origin vertex
	int v;  //destination vertex

	makeEmptyGraph(n);

	while (cin >> u)    //check if input is eof (^Z)
	{
		checkInput(u, n);
		if (cin >> v)
		{
			checkInput(v, n);
		}
		else
		{
			cout << "invalid input" << endl;
			exit(1);
		}

		this->addEdge(u, v);
	}
}

void Graph::makeEmptyGraph(int n){
	if (adjList != NULL) {
		releaseGarph();
	}

	adjList = new NeighborsList[size_t(n) + 1];
	vSize = n;
	for (int i = 1; i <= n; i++) {
		adjList[size_t(i)].setHead(i);
	}
}


void Graph::releaseGarph() {

	delete[] adjList;
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

Graph* Graph::getGTranspose(const Graph& g) {
	Graph* gt = new Graph(g.vSize);

	for (int u = 1; u <= g.vSize; u++) {
		Vertex* pv = g.adjList[u].getList();
		while (pv != nullptr) {
			gt->addEdge(pv->getV(), u);
			pv = pv->getNext();
		}
	}
	return gt;
}

int Graph::getSize() {
	return vSize;
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
	if (current != NULL)
		delete current;
	firstNeighbor = lastNeighbor = NULL;
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
		
	}
	else {
		Vertex* prev = temp;
		while (temp->getV() != v) {
			prev = temp;
			temp = temp->getNext();
		}
		prev->setNext(temp->getNext());
	}
	temp->setNext(NULL);
	delete temp;
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

/************************************* ShortestPath Methods**********************************/

int* Graph::BFS(Vertex s)
{
	int vSize = getSize();
	int* d = new int[vSize + 1];
	Queue Q;
	for (int i = 1; i <= vSize; i++)
	{
		d[i] = -1;
	}
	Q.enqueue(s.getV());
	d[s.getV()] = 0;
	Vertex* v;
	int vValue;
	int uValue;
	while (!Q.isEmpty())
	{
		uValue = Q.dequeue();
		v = getAdjList(uValue);
		while (v!=NULL)
		{
			vValue = v->getV();
			if (d[vValue] == -1)
			{
				d[vValue] = d[uValue] + 1;
				Q.enqueue(vValue);
			}	
			v = v->getNext();
		}

	}
	return d;
}

Graph* Graph::getGs(const Graph& g, int* d) {
	Graph* gs = new Graph(g.vSize);

	for (int u = 1; u <= g.vSize; u++) {
		Vertex* pv = g.adjList[u].getList();
		while (pv != nullptr) {
			if (d[pv->getV()] == d[u] + 1)
			{
				gs->addEdge(u, pv->getV());
			}
			pv = pv->getNext();
		}
	}
	return gs;
}