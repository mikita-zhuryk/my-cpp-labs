#pragma once
#include <iostream>

using namespace std;

struct OutOfBounds {};

class Queue
{
	int* queue_;
	int size_;
	int head;
	int tail;
	int n;

public:

	Queue(int = 100);

	Queue(const Queue&);

	~Queue();

	int* add(const int&);

	void remove();

	int* addToPos(int, int);

	int removeFromPos(int);

	bool operator==(const Queue&);

	bool operator!=(const Queue&);

	friend ostream& operator<<(ostream&, const Queue&);

	friend istream& operator>>(istream&, Queue&);

};