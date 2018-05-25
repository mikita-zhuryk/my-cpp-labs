#pragma once
#include "Container1.h"
#include "Container2.h"
#include "Container3.h"
#include <iostream>
#include <ctime>
#include <initializer_list>
#include <iterator>

template <class T>
class CONTAINER {

	T* _vec;
	size_t _length;

public:

	CONTAINER();

	CONTAINER(T*, size_t);

	CONTAINER(std::initializer_list<T>);

	~CONTAINER();

	CONTAINER& operator=(const CONTAINER&);

	size_t getLength();

	const T& operator[](size_t) const;

	void diff(CONTAINER<Container1>&, CONTAINER<Container2>&);

	void sort();

	template<class T>
	friend std::ostream& operator<<(std::ostream&, const CONTAINER<T>&);

	template<class T>
	friend std::istream& operator>>(std::istream&, CONTAINER<T>&);

};

template<class T>
inline CONTAINER<T>::CONTAINER() {
	_vec = nullptr;
	_length = 0;
}

template<class T>
inline CONTAINER<T>::CONTAINER(T* vec, size_t length) {
	if ((length < 1) || (vec == nullptr)) {
		throw std::invalid_argument("Bad array in CONTAINER(T*, size_t).");
	}
	_length = length;
	_vec = new T[_length];
	for (size_t i = 0; i < length; i++) {
		_vec[i] = vec[i];
	}
}

template<class T>
inline CONTAINER<T>::CONTAINER(std::initializer_list<T> il) {
	if (il.size() == 0) {
		throw std::invalid_argument("Initlist is empty.");
	}
	_length = il.size();
	_vec = new T[_length];
	size_t i = 0;
	for (std::initializer_list<T>::iterator it = il.begin(); it != il.end(); it++) {
		_vec[i] = *it;
		i++;
	}
}

template<class T>
inline CONTAINER<T>::~CONTAINER() {
	delete[] _vec;
}

template<class T>
inline CONTAINER<T>& CONTAINER<T>::operator=(const CONTAINER<T>& obj) {
	_length = obj._length;
	delete[] _vec;
	_vec = new T[_length];
	for (size_t i = 0; i < _length; i++) {
		_vec[i] = obj._vec[i];
	}
	return *this;
}

template<class T>
inline size_t CONTAINER<T>::getLength() {
	return _length;
}

template <class T>
inline const T& CONTAINER<T>::operator[](size_t index) const {
	if (index > _length) {
		throw std::out_of_range("Index was greater than container length.");
	}
	return _vec[index];
}

template<>
inline void CONTAINER<Container3>::diff(CONTAINER<Container1>& cont1, CONTAINER<Container2>& cont2) {
	size_t cross = 0;
	for (size_t i = 0; i < cont1.getLength(); i++) {
		for (size_t j = 0; j < cont2.getLength(); j++) {
			if (!_strcmpi(cont1[i]._name, cont2[i]._name)) {
				cross++;
			}
		}
	}
	_length = cont1.getLength() - cross;
	bool found;
	for (size_t i = 0; i < cont1.getLength(); i++) {
		found = false;
		for (size_t j = 0; j < cont2.getLength(); j++) {
			if (!_strcmpi(cont1[i]._name, cont2[i]._name)) {
				found = true;
			}
		}
		if (!found) {
			strcpy_s(_vec[i]._addr, cont1[i]._addr);
			strcpy_s(_vec[i]._name, cont1[i]._name);
			_vec[i]._price = 0;
		}
	}
}

template<class T>
std::ostream& operator<<(std::ostream& out, const CONTAINER<T>& obj) {
	if (!out) {
		throw std::invalid_argument("Bad output stream.");
	}
	for (size_t i = 0; i < obj._length; i++) {
		out << obj[i] << std::endl;
	}
	return out;
}

template<class T>
std::istream& operator>>(std::istream& in, CONTAINER<T>& obj) {
	if (!in) {
		throw std::invalid_argument("Bad input stream");
	}
	in.peek();
	if (in.eof()) {
		throw std::invalid_argument("Input file is empty");
	}
	for (size_t i = 0; i < obj._length; i++) {
		in >> obj[i];
	}
}