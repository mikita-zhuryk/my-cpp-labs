#include "Queue2.h"
#include <cassert>

template <typename T>
Queue<T>::Queue()
{
	queue_ = nullptr;
	size_ = 0;
}

template <typename T>
Queue<T>::Queue(size_t size_)
{
	this->size_ = size_;
	this->queue_ = new T[size_];
}

template <typename T>
Queue<T>::~Queue()
{
	delete[] queue_;
}

template <typename T>
T* Queue<T>::add(T data, size_t position)
{
	size_++;
	queue_ = (T*)realloc(queue_, size_ * sizeof(T*));
	assert(queue_ != 0);
	for (size_t i = position + 1; i < size_; i++)
	{
		queue_[i] = queue_[i - 1];
	}
	queue_[position] = data;
	return queue_ + position;
}

template <typename T>
size_t Queue<T>::remove(size_t position)
{
	for (size_t i = position; i < size_ - 1; i++)
	{
		queue_[i] = queue_[i + 1];
	}
	size_--;
	queue_ = (T*)realloc(queue_, size_ * sizeof(T*));
	assert(queue_ != 0);
	return position;
}

template <typename T>
bool Queue<T>::operator==(const Queue<T>& cmpObj)
{
	if (size_ != cmpObj.size_) { return false; }
	for (size_t i = 0; i < size_; i++)
	{
		if (((T*)cmpObj.queue_[i]) != ((T*)queue_[i])) { return false; }
	}
	return true;
}

template<>
bool Queue<char*>::operator==(const Queue<char*>& cmpObj)
{
	if (size_ != cmpObj.size_) { return false; }
	for (size_t i = 0; i < size_; i++)
	{
		if (_strcmpi((char*)cmpObj.queue_[i], (char*)queue_[i])) { return false; }
	}
	return true;
}

template <typename T>
bool Queue<T>::operator!=(const Queue<T>& cmpObj)
{
	return !(*this == cmpObj);
}

template <typename T>
ostream& operator<<(ostream& outStream, const Queue<T>& obj)
{
	for (size_t i = 0; i < obj.size_; i++)
	{
		outStream << *((T*)obj.queue_[i]) << ' ';
	}
	return outStream;
}

//template<>
//ostream& operator<< <char*>(ostream& outStream, const Queue<char*>& obj)
//{
//	for (size_t i = 0; i < obj.size_; i++)
//	{
//		outStream << (char*)obj.queue_[i] << ' ';
//	}
//	return outStream;
//}

template <typename T>
istream& operator>>(istream& inStream, Queue<T>& obj)
{
	for (size_t i = 0; i < obj.size_; i++)
	{
		inStream >> obj.queue_[i];
	}
	return inStream;
}