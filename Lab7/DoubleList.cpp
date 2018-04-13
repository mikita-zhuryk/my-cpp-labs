#include "DoubleList.h"

DoubleList::DoubleListNode::DoubleListNode(double data) {
	data_ = data;
	next = nullptr;
}

DoubleList::DoubleList() {
	head = tail = nullptr;
}

DoubleList::DoubleList(double data) {
	DoubleListNode* temp = new DoubleListNode(data);
	head = tail = temp;
}

DoubleList::DoubleList(double* arr, double length) {
	if (!arr || !length) {
		throw invalid_argument("Array is corrupted.\n");
	}
	DoubleListNode* temp = new DoubleListNode(arr[0]);
	head = tail = temp;
	for (int i = 1; i < length; i++) {
		temp = new DoubleListNode(arr[i]);
		tail->next = temp;
		tail = temp;
	}
}

DoubleList::DoubleList(const DoubleList& origin) {
	if (!origin.isEmpty()) {
		DoubleListNode* temp = origin.head;
		head = new DoubleListNode(temp->data_);
		temp = temp->next;
		while (temp != origin.tail) {
			DoubleListNode* create = new DoubleListNode(temp->data_);
			tail->next = create;
			tail = create;
			temp = temp->next;
		}
	}
	else {
		DoubleList();
	}
}

DoubleList::~DoubleList() {
	DoubleListNode* temp;
	while (head) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

bool DoubleList::isEmpty() const
{
	return !head;
}

void DoubleList::print(ostream& out) const {
	DoubleListNode* temp = head;
	while (temp) {
		out.precision(8);
		out << temp->data_ << " ";
		temp = temp->next;
	}
}
