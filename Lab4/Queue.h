#pragma once

#define STRING_SIZE 30

struct Address {
	char* street;
	int house;
	int building;
	int flat;

	Address();

	Address(const char*, int, int, int);

	Address(const Address&);

	Address& operator=(const Address&);

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
	};

	QueueNode* head;

	QueueNode* tail;

public:

	Queue();

	Queue(Address);

	Queue(const Queue&);

	~Queue();

	bool empty();

	void show();

	void add(Address);

	QueueNode pop();

};