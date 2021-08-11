#pragma once

#include "Vertex.h"


class Queue {
private :
	Vertex* head;
	Vertex* tail;

public:
	Queue(): head(nullptr), tail(nullptr) {}
	~Queue() { makeEmpty(); }

	void makeEmpty() {
		Vertex* temp;
		while (head != nullptr){
			dequeue();
		}
	}

	int dequeue() {
		if (isEmpty())
			throw out_of_range("queue is empty");
		Vertex* temp = head;
		int first = temp->getV();
		head = head->getNext();
		
		temp->setNext(nullptr);
		delete temp;
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