#include "IntList.h"

IntList::IntListNode::IntListNode(int data) {
	data_ = data;
	next = nullptr;
}

IntList::IntList() {
	head = nullptr;
}

IntList::IntList(int data) {
	IntListNode* temp = new IntListNode(data);
	head = temp;
}

IntList::IntList(int* arr, int length) {
	if (!arr || !length) {
		throw invalid_argument("Array is corrupted.\n");
	}
	IntListNode* tempInsert = new IntListNode(arr[0]);
	tempInsert->next = nullptr;
	head = tempInsert;
	for (int i = 1; i < length; i++) {
		tempInsert->next = new IntListNode(arr[i]);
		tempInsert = tempInsert->next;
	}
}

IntList::IntList(const IntList& origin) {
	if (!origin.empty()) {
		IntListNode* temp = origin.head;
		IntListNode* tempInsert = new IntListNode(temp->data_);
		temp = temp->next;
		head = tempInsert;
		while (temp) {
			tempInsert->next = new IntListNode(temp->data_);
			temp = temp->next;
			tempInsert = tempInsert->next;
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

bool IntList::empty() const
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
