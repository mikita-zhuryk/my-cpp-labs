#include "DoubleList.h"

DoubleList::DoubleListNode::DoubleListNode(double data) {
	data_ = data;
	next = nullptr;
}

DoubleList::DoubleList() {
	head = nullptr;
}

DoubleList::DoubleList(double data) {
	DoubleListNode* temp = new DoubleListNode(data);
	head = temp;
}

DoubleList::DoubleList(double* arr, double length) {
	if (!arr || !length) {
		throw invalid_argument("Array is corrupted.\n");
	}
	DoubleListNode* tempInsert = new DoubleListNode(arr[0]);
	tempInsert->next = nullptr;
	head = tempInsert;
	for (int i = 1; i < length; i++) {
		tempInsert->next = new DoubleListNode(arr[i]);
		tempInsert = tempInsert->next;
	}
}

DoubleList::DoubleList(const DoubleList& origin) {
	if (!origin.empty()) {
		DoubleListNode* temp = origin.head;
		DoubleListNode* tempInsert = new DoubleListNode(temp->data_);
		temp = temp->next;
		head = tempInsert;
		while (temp) {
			tempInsert->next = new DoubleListNode(temp->data_);
			temp = temp->next;
			tempInsert = tempInsert->next;
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

bool DoubleList::empty() const
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
