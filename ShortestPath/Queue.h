#pragma once

#include "Vertex.h"

//A class representation for the ADT Queue using a dynamic linked list of Vertex Nodes
class Queue {
private :
	Vertex* head;
	Vertex* tail;

public:
	Queue(): head(nullptr), tail(nullptr) {}
	~Queue() { 
		makeEmpty(); 
	}

	//this method clears the queue completely
	void makeEmpty() {
		while (head != nullptr){
			dequeue();
		}
	}

	//A method that returns the first item in the queue (the itm inserted the erliest)
	//and remove it from the queue
	int dequeue() {
		if (isEmpty())
			throw out_of_range("queue is empty");
		Vertex* temp = head;
		int first = temp->getV();
		head = head->getNext();
		if (head == nullptr)
			tail = nullptr;
		
		temp->setNext(nullptr);
		delete temp;
		return first;
	}

	//this method recieves A vertex node and insert it to the back of the queue 
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

	//overload to the methid above, recieving int value and create the corresponding node,
	//then add it to the back of the queue
	void enqueue(int val) {
		Vertex* newNode = new Vertex(val);
		enqueue(newNode);
	}

	//getter to the value of the first item in the queue
	int front() {
		return head->getV();
	}

	//boolean method that returns true only if the queu is completely empty,
	//and there is not a single node in it
	//elsewise return false
	bool isEmpty() {
		return (head == NULL);
	}

};