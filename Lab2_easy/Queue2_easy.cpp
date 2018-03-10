#include "Queue2_easy.h"
#include <cassert>

#define MAX_SIZE 100

Queue::Queue(size_t size_)
{
	this->size_ = (size_ < MAX_SIZE) ? MAX_SIZE : size_;
	queue_ = new int[size_];
	if (queue_ == nullptr) { throw 5; }
	head = 0;
	tail = 1;
}

Queue::~Queue()
{
	if (queue_ != nullptr) {
		delete[] queue_;
	}
}

int* Queue::add(int data) {
	if (++tail > size_) { throw OutOfBounds(); }
	queue_[tail] = data;
	return queue_ + tail;
}

void Queue::remove() {
	head++;
}

int* Queue::addToPos(int data, size_t position)
{
	if ((position < 0) || (position > tail - head - 1)) { throw 1; }
	position--;
	tail++;
	for (size_t i = tail; i > position; i--)
	{
		queue_[i] = queue_[i - 1];
	}
	queue_[position] = data;
	return queue_ + position;
}


size_t Queue::removeFromPos(size_t position)
{
	if ((position < 0) || (position > tail - head - 1)) { throw 1; }
	position--;
	for (size_t i = position; i < tail - 1; i++)
	{
		queue_[i] = queue_[i + 1];
	}
	tail--;
	return position;
}


bool Queue::operator==(const Queue& cmpObj)
{
	if (size_ != cmpObj.size_) { return false; }
	for (size_t i = head; i < tail; i++)
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
	for (size_t i = obj.head; i < obj.tail; i++)
	{
		outStream << obj.queue_[i] << ' ';
	}
	return outStream;
}

istream& operator>>(istream& inStream, Queue& obj)
{
	if (!inStream) { throw 3; }
	if (inStream.eof()) { throw 4; }
	int temp;
	for (size_t i = obj.head; i < obj.tail; i++)
	{
		inStream >> temp;
	}
	return inStream;
}