#pragma once
#include <iostream>

using namespace std;

template <class T>
class Queue
{
	T* queue_;
	size_t size_;

public:

	Queue();

	Queue(size_t);

	~Queue();

	T* add(T, size_t);

	size_t remove(size_t);

	bool operator==(const Queue&);

	bool operator!=(const Queue&);

	friend ostream& operator<<(ostream&, const Queue<T>&);

	friend istream& operator>>(istream&, Queue<T>&);

};