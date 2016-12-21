// Unit_5.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <memory>
#include <iostream>

Node::Node(double value) :value(value)
{
	
}
void Node::setNext(Node *node)
{
	next = node;
}
double Node::getValue()
{
	return value;
}
Node *Node::getNext()
{
	return next;
}




LinkedList::LinkedList() : head(nullptr), size(0) {

}

LinkedList::~LinkedList() {

}
bool LinkedList::isEmpty() {
	if (head != nullptr)
		return false;
	return true;
}
void LinkedList::add(double value) {
	Node *tmp = head;
	head = new Node(value);
	head->setNext(tmp);
	++size;
}

Node* LinkedList::operator[](size_t index)const {
	Node *currentNode = head;
	for (int i = 0; i < index; ++i) {
		currentNode = currentNode->getNext();
	}
	return currentNode;
}


int main() {

	LinkedList *l = new LinkedList;
	l->add(3);
	l->add(2);
	l->add(1);
	Node *node = (*l)[1];
	node = new Node(4);
	std::cout << (*l)[1]->getValue() << std::endl;
	std::cout<< "hallo" << std::endl;
}