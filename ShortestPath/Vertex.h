
#pragma once

#include <iostream>

using namespace std;

//struct to represent a vertex in the ADT graph
//each vertex composed on int value (vertex's "name") 
//and a pointer to the next vertex if needed (i.e. the Adjacency list in Graph)
struct Vertex {
private:
	int value;
	Vertex* next;

public:
	Vertex(int value, Vertex* next = NULL) {
		setV(value);
		setNext(next);
	}
		
	Vertex(): next(NULL), value(0) {};
	~Vertex() {}

	//setter for the value of the vretex
	void setV(int u) {
		this->value = u;
	}

	//setter for the pointer of the next vertex linked to 'this'
	void setNext(Vertex* next) {
		this->next = next;
	}

	//getter for the value of the vretex
	int getV() {
		return value;
	}

	//getter for the pointer of the next vertex linked to 'this'
	Vertex* getNext() {
		return next;
	}

	//print operator overloading
	friend ostream& operator<<(ostream& out, const Vertex& vertex)
	{
		return out << vertex.value;
	}

};


