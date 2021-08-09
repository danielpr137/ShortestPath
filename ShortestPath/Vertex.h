
#pragma once

#include <iostream>

using namespace std;

struct Vertex {
private:
	int v;
	Vertex* next;

public:
	Vertex(int v, Vertex* next = NULL) {
		setV(v);
		setNext(next);
	}
		
	Vertex(): next(NULL), v(0) {};
	~Vertex() {
	}

	void setV(int u) {
		this->v = u;
	}

	void setNext(Vertex* next) {
		this->next = next;
	}

	int getV() {
		return v;
	}

	Vertex* getNext() {
		return next;
	}

};


