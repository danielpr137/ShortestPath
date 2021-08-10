#pragma once

#include "Vertex.h"


class Queue {
private :
	Vertex* head;
	Vertex* tail;

public:
	Queue(){}
	~Queue() { makeEmpty(); }

	void makeEmpty() {
		Vertex* temp;
		while (head != nullptr){
			temp = dequeue();
			delete temp;
		}
	}

	Vertex* dequeue() {
		if (isEmpty())
			return nullptr;
		Vertex* first = head;
		head = head->getNext();
		first->setNext(nullptr);
		return first;
	}

	void enqueue(Vertex* pv) {
		if (head == NULL) {
			head = tail = pv;
		}
		else {
			tail->setNext(pv);
			pv->setNext(NULL);
			tail = pv;
		}
	}

	void enqueue(int val) {
		Vertex* newNode = new Vertex(val);
		enqueue(newNode);
	}

	int front() {
		return head->getV();
	}

	bool isEmpty() {
		return (head == NULL);
	}

};