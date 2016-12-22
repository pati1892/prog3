// Unit_5.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <memory>
#include <iostream>
#include <exception>



class Node
{
private:
	double value;
	Node *next;
	Node *previous;

public:
	Node(double value);
	Node(const Node&);
	~Node();
	double getValue() const;
	void setNext(Node *node);
	void setPrevious(Node*);
	Node *getNext() const;
	Node *getPrevious() const;
};

class LinkedList
{
public:
	LinkedList();
	LinkedList(double);
	LinkedList(const LinkedList&);
	~LinkedList();
	LinkedList& operator=(const LinkedList& src);
	bool isEmpty();
	void pushback(double);
	void pushback(Node*);
	void removeAt(size_t);
	Node* operator[](size_t)const;

	size_t getSize() const;

private:
	Node *head;
	size_t size;

};


Node::Node(double value) :value(value), next(nullptr), previous(nullptr) {}
Node::Node(const Node& src):Node(src.getValue()){
	std::cout << "Node Kopierkonstruktor" << std::endl;
}
Node::~Node() {
	//std::cout << "Delete: " << value << std::endl;
}
void Node::setNext(Node *node)
{
	next = node;
}
void Node::setPrevious(Node *node)
{
	previous = node;
}
double Node::getValue() const
{
	return value;
}
Node *Node::getNext() const
{
	return next;
}
Node *Node::getPrevious() const
{
	return previous;
}




LinkedList::LinkedList() : head(nullptr), size(0) {

}

LinkedList::~LinkedList() {
	if (!isEmpty())
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

LinkedList::LinkedList(const LinkedList& src) :LinkedList() {
	std::cout << "CopyConstructor" << std::endl;
	for (int i = src.getSize() - 1; i >= 0; --i) {
		this->pushback(src[i]->getValue());
	}

}
bool LinkedList::isEmpty() {
	if (head != nullptr)
		return false;
	return true;
}
void LinkedList::pushback(double value) {
	if (!isEmpty()) {
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
	Node *removeNode = (*this)[index];
	Node *previous = removeNode->getPrevious();
	Node *next = removeNode->getNext();

	if (next != nullptr)
		next->setPrevious(previous);

	if (previous != nullptr)
		previous->setNext(next);
	else
		head = next;

	delete(removeNode);
	--size;
}

Node* LinkedList::operator[](size_t index) const {
	if (index >= this->size)
			throw std::out_of_range("OUT OF RANGE");
	Node *currentNode = head;
	for (size_t i = 0; i < index; ++i) {
		currentNode = currentNode->getNext();
	}
	return currentNode;
}
LinkedList& LinkedList::operator=(const LinkedList& src) {
	std::cout << "Zuweisungsoperator" << std::endl;
	while (size > 0) {
		removeAt(0);
	}
	for (int i = src.getSize() - 1; i >= 0; --i) {
		this->pushback(src[i]->getValue());
	}
	return *this;
}
size_t LinkedList::getSize() const {
	return size;
}

std::ostream& operator<<(std::ostream& out, const LinkedList& list)
{
	for (size_t i = 0; i < list.getSize(); ++i) {
		out << "Index " << i << " = " << list[i]->getValue() << "\n";
	}
	return out;
}

void deleteList(LinkedList &list) {

	std::cout << "DeleteList:\n" << list << std::endl;
	list.removeAt(1);
	std::cout << "DeleteList:\n" << list << std::endl;
	list.removeAt(1);
	std::cout << "DeleteList:\n" << list << std::endl;
	list.removeAt(0);
	std::cout << "DeleteList:\n" << list << std::endl;
}

int main() {
	{
		LinkedList *list1Ptr = new LinkedList();
		LinkedList& list1 = *list1Ptr;
		list1.pushback(1);
		list1.pushback(2);
		list1.pushback(3);

		std::cout << list1 << std::endl;

		LinkedList list2 = list1;
		std::cout << "List1\n" << list1 << std::endl;
		std::cout << "List2\n" << list2 << std::endl;

		LinkedList *list3Ptr = new LinkedList();
		LinkedList &list3 = *list3Ptr;
		list3.pushback(10);
		list3.pushback(11);
		list3.pushback(12);
		list3.pushback(13);
		std::cout << "List3\n" << list3 << std::endl;
		list3 = list1;
		std::cout << "List3\n" << list3 << std::endl;
		deleteList(list3);

		delete(list1Ptr);
		delete(list3Ptr);
	}
	

	if (_CrtDumpMemoryLeaks())
		std::cout << "Memory Leak!" << std::endl;


}