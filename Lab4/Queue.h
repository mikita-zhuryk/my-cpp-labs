#pragma once

//TODO: Add struct House containing street, house, ...

#define STRING_SIZE 30

struct Address {
	char* street;
	int house;
	int building;
	int flat;

	Address();

	Address(const char*, int, int, int);

	Address(const Address&);

	~Address();
};

class Queue {

	struct QueueNode {
		Address address;
		QueueNode* prevNode;
		QueueNode* nextNode;

		QueueNode(Address, QueueNode* = nullptr, QueueNode* = nullptr);

		QueueNode(const QueueNode&);

		~QueueNode();

		/*friend ostream& operator<<(ostream& out, const QueueNode& obj) {
			out << obj.street << ", " << obj.house << ", " << obj.building << ", " << obj.flat << ".\n";
		}*/
	};

	QueueNode* head;

	QueueNode* tail;

public:

	Queue();

	//Queue(const char* = "\0", int = 0, int = 0, int = 0);

	Queue(Address);

	Queue(const Queue&);

	~Queue();

	bool isEmpty();

	void showState();

	void addElem(Address);

	QueueNode popElem();

};