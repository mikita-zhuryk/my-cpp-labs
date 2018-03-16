#include "Queue2_easy.h"
#include <cassert>

#define MAX_SIZE 100

Queue::Queue(int size_)
{
	this->size_ = (size_ < MAX_SIZE) ? MAX_SIZE : size_;
	queue_ = new int[size_];
	if (queue_ == nullptr) { throw 5; }
	head = 0;
	tail = 0;
	n = 0;
}

Queue::Queue(const Queue& q) {
	size_ = q.size_;
	queue_ = new int[size_];
	for (int i = 0; i < size_; i++) {
		queue_[i] = q.queue_[i];
	}
	head = q.head;
	tail = q.tail;
	n = q.n;
}

Queue::~Queue()
{
	if (queue_ != nullptr) {
		delete[] queue_;
	}
}

int* Queue::add(const int& data) {
	if (++tail >= size_) { throw OutOfBounds(); }
	queue_[tail] = data;
	if (n == 0) { head = tail; }
	n++;
	return queue_ + tail;
}

void Queue::remove() {
	head++;
}

int* Queue::addToPos(int data, int position)
{
	if ((position < 0) || (position > tail - head - 1)) { throw 1; }
	position--;
	tail++;
	for (int i = tail; i > position; i--)
	{
		queue_[i] = queue_[i - 1];
	}
	queue_[position] = data;
	return queue_ + position;
}


int Queue::removeFromPos(int position)
{
	if ((position < 0) || (position > tail - head - 1)) { throw 1; }
	position--;
	for (int i = position; i < tail - 1; i++)
	{
		queue_[i] = queue_[i + 1];
	}
	tail--;
	return position;
}


bool Queue::operator==(const Queue& cmpObj)
{
	if (size_ != cmpObj.size_) { return false; }
	for (int i = head; i < tail; i++)
	{
		if (queue_[i] != cmpObj.queue_[i]) { return false; }
	}
	return true;
}


bool Queue::operator!=(const Queue& cmpObj)
{
	return !(*this == cmpObj);
}

ostream& operator<<(ostream& outStream, const Queue& obj)
{
	if (!outStream) { throw 2; }
	for (int i = obj.head; i < obj.tail; i++)
	{
		outStream << obj.queue_[i] << ' ';
	}
	return outStream;
}

istream& operator>>(istream& inStream, Queue& obj)
{
	if (!inStream) { throw 3; }
	if (inStream.eof()) { throw 4; }
	int num = 0;
	cout << "Input number of elements.\n";
	cin >> num;
	obj.tail += num;
	for (int i = obj.head; i < obj.tail; i++)
	{
		inStream >> obj.queue_[i];
	}
	return inStream;
}