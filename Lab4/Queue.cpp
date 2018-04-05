#include "..\Lab4\Queue.h"
#include <cstring>
#include <iostream>

using namespace std;

Queue::Queue() {
	head = nullptr;
	tail = nullptr;
}

Queue::Queue(const char* str, int house, int building, int flat) {
	head = new QueueNode(str, house, building, flat);
	tail = head;
}

Queue::Queue(const Queue& origin) {
	QueueNode* tmpPtr = origin.head;
	head = new QueueNode(*tmpPtr);
	tail = head;
	for (; tmpPtr < origin.tail; tmpPtr++) {
		tail = new QueueNode(tmpPtr->street, tmpPtr->house, tmpPtr->building, tmpPtr->flat, tail, nullptr);
	}
}

Queue::~Queue() {
	QueueNode* tmpPtr = head;
	while (tmpPtr)
	{
		head = head->nextNode;
		delete tmpPtr;
		tmpPtr = head;
	}
}

Queue::QueueNode::QueueNode(const char* street, int house, int building, int flat, QueueNode* prevNode, QueueNode* nextNode) {
	this->street = new char[STRING_SIZE];
	strcpy_s(this->street, STRING_SIZE, street);
	this->house = house;
	this->building = building;
	this->flat = flat;
	this->prevNode = prevNode;
	this->nextNode = nextNode;
}

Queue::QueueNode::QueueNode(const QueueNode& origObj) {
	street = new char[STRING_SIZE];
	strcpy_s(street, STRING_SIZE, origObj.street);
	house = origObj.house;
	building = origObj.building;
	flat = origObj.flat;
	prevNode = origObj.prevNode;
	nextNode = origObj.nextNode;
}

Queue::QueueNode::~QueueNode() {
	delete[] street;
}

bool Queue::isEmpty() {
	return (!head);
}

void Queue::showState() {
	if (isEmpty()) { cout << "Queue is empty.\n"; }
	else {
		QueueNode* tmpPtr = head;
		size_t count = 0;
		while (tmpPtr)
		{
			cout << count + 1 << ". " << tmpPtr->street << ", " << tmpPtr->house << ", " << tmpPtr->building << ", " << tmpPtr->flat << ".\n";
			count++;
			tmpPtr = tmpPtr->nextNode;
		}
		printf("Queue contains %d records.\n", count);
	}
}

void Queue::addElem(const char* street, int house, int building, int flat) {
	if (isEmpty()) {
		head = new QueueNode(street, house, building, flat, tail);
		tail = head;
	}
	else {
		QueueNode* tmp = tail;
		tail = new QueueNode(street, house, building, flat, tail);
		tmp->nextNode = tail;
	}
}

Queue::QueueNode Queue::popElem() {
	if (isEmpty()) { 
		cout << "Error. Queue is empty, nothing to delete.\n";
		return QueueNode("\0", 0, 0, 0, 0, 0);
	}
	else {
		QueueNode tmp(*head);
		QueueNode* tmpPtr = head;
		head = head->nextNode;
		delete tmpPtr;
		return tmp;
	}
}