
#pragma once

#include <iostream>

struct Vertex {
private:
	std::string name;
	Vertex* next;

public:
	Vertex(std::string name, Vertex* next = NULL) {
		this->name = name;
		this->next = next;
	}
	~Vertex() {
	}
};


