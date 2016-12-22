// Unit_5.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <memory>
#include <iostream>

Node::Node(double value):value(value), next(nullptr), previous(nullptr)
{
	
}
Node::~Node() {

}
void Node::setNext(Node *node)
{
	next = node;
}
void Node::setPrevious(Node *node)
{
	previous = node;
}
double Node::getValue()
{
	return value;
}
Node *Node::getNext()
{
	return next;
}
Node *Node::getPrevious()
{
	return previous;
}




LinkedList::LinkedList() : head(nullptr), size(0) {

}

LinkedList::~LinkedList() {
	if (head != nullptr)
	{
		Node *deleteNode = nullptr;
		while (head->getNext() != nullptr) {
			deleteNode = head;
			head = head->getNext();
			delete(deleteNode);
		}
		delete(head);
		head = nullptr;
	}

}
bool LinkedList::isEmpty() {
	if (head != nullptr)
		return false;
	return true;
}
void LinkedList::pushback(double value) {
	if (head != nullptr) {
		Node *newNext = head;
		head = new Node(value);
		newNext->setPrevious(head);
		head->setNext(newNext);
	}
	else {
		head = new Node(value);
	}
		
	++size;
}
void LinkedList::removeAt(size_t index) {
	Node *removeNode = this->operator[](index);

	Node *previous = removeNode->getPrevious();
	Node *next = removeNode->getNext();
	if (next != nullptr)
		next->setPrevious(previous);
		
	if (previous != nullptr)
		previous->setNext(next);
	else
		head = next;

	delete(removeNode);
}

Node* LinkedList::operator[](size_t index)const {
	Node *currentNode = head;
	for (int i = 0; i < index; ++i) {
		currentNode = currentNode->getNext();
	}
	return currentNode;
}


int main() {


}