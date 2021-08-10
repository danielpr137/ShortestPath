
#pragma once

#include <iostream>

using namespace std;

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
	~Vertex() {
	}

	void setV(int u) {
		this->value = u;
	}

	void setNext(Vertex* next) {
		this->next = next;
	}

	int getV() {
		return value;
	}

	Vertex* getNext() {
		return next;
	}

	friend ostream& operator<<(ostream& out, const Vertex& vertex)
	{
		return out << vertex.value;
	}

};


