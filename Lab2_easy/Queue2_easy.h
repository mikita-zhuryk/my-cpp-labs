#pragma once
#include <iostream>

using namespace std;

struct OutOfBounds {};

class Queue
{
	int* queue_;
	size_t size_;
	int head;
	int tail;
	int n;

public:

	Queue(size_t = 100);

	Queue(const Queue&);

	~Queue();

	int* add(const int&);

	void remove();

	int* addToPos(int, size_t);

	size_t removeFromPos(size_t);

	bool operator==(const Queue&);

	bool operator!=(const Queue&);

	friend ostream& operator<<(ostream&, const Queue&);

	friend istream& operator>>(istream&, Queue&);

};