#include "IntList.h"

IntList::IntListNode::IntListNode(int data) {
	data_ = data;
	next = nullptr;
}

IntList::IntList() {
	head = tail = nullptr;
}

IntList::IntList(int data) {
	IntListNode* temp = new IntListNode(data);
	head = tail = temp;
}

IntList::IntList(int* arr, int length) {
	if (!arr || !length) {
		throw invalid_argument("Array is corrupted.\n");
	}
	IntListNode* temp = new IntListNode(arr[0]);
	head = tail = temp;
	for (int i = 1; i < length; i++) {
		temp = new IntListNode(arr[i]);
		tail->next = temp;
		tail = temp;
	}
}

IntList::IntList(const IntList& origin) {
	if (!origin.isEmpty()) {
		IntListNode* temp = origin.head;
		head = new IntListNode(temp->data_);
		temp = temp->next;
		while (temp != origin.tail) {
			IntListNode* create = new IntListNode(temp->data_);
			tail->next = create;
			tail = create;
			temp = temp->next;
		}
	}
	else {
		IntList();
	}
}

IntList::~IntList() {
	IntListNode* temp;
	while (head) {
		temp = head;
		head = head->next;
		delete temp;
	}
}

bool IntList::isEmpty() const
{
	return !head;
}

void IntList::print(ostream& out) const {
	IntListNode* temp = head;
	while (temp) {
		out << temp->data_ << " ";
		temp = temp->next;
	}
}
