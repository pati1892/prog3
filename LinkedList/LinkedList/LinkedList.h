#pragma once

class Node
{
private:
	double value;
	Node *next;

public:
	Node(double value);
	~Node();
	double getValue();
	void setNext(Node *node);
	Node *getNext();
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(double);
	~LinkedList();
	bool isEmpty();
	void add(double);
	Node* operator[](size_t index)const;
	size_t getSize();

private:
	Node *head;
	size_t size;

};


