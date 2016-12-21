#pragma once

class Node
{
private:
	double value;
	Node *next;
	Node *previous;

public:
	Node(double value);
	~Node();
	double getValue();
	void setNext(Node *node);
	void setPrevious(Node*);
	Node *getNext();
	Node *getPrevious();
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(double);
	~LinkedList();
	bool isEmpty();
	void pushback(double);
	void removeAt(size_t);
	Node* operator[](size_t)const;
	size_t getSize();

private:
	Node *head;
	size_t size;

};


