#pragma once
#include "List.h"

class IntList : public List {

	struct IntListNode {
		int data_;
		IntListNode* next;

		IntListNode(int);
	};

	IntListNode* head;
	IntListNode* tail;

public:

	IntList();

	IntList(int);

	IntList(int*, int);

	IntList(const IntList&);

	~IntList();

	void print(ostream&) const;

	bool isEmpty() const;

};