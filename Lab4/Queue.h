#pragma once

#define STRING_SIZE 30

class Queue {

	struct QueueNode {
		char* street;
		int house;
		int building;
		int flat;
		QueueNode* prevNode;
		QueueNode* nextNode;

		QueueNode(const char* = "\0", int = 0, int = 0, int = 0, QueueNode* = nullptr, QueueNode* = nullptr);

		QueueNode(const QueueNode&);

		~QueueNode();

		/*friend ostream& operator<<(ostream& out, const QueueNode& obj) {
			out << obj.street << ", " << obj.house << ", " << obj.building << ", " << obj.flat << ".\n";
		}*/
	};

	QueueNode* head;

	QueueNode* tail;

public:

	Queue(const char* = "\0", int = 0, int = 0, int = 0);

	Queue(const Queue&);

	~Queue();

	bool isEmpty();

	void showState();

	void addElem(const char*, int, int, int);

	QueueNode popElem();

};