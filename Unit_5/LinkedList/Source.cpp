// Unit_5.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <memory>
#include <iostream>
#include <exception>


template <typename T>
class Node
{
private:
	//double value;
	T &value;
	Node *next;
	Node *previous;

public:
	//Node(double value);
	Node(T&);
	Node(const Node&);
	~Node();
	//double getValue() const;
	T& getValue() const;
	void setNext(Node *node);
	void setPrevious(Node*);
	Node *getNext() const;
	Node *getPrevious() const;
};

template <typename T>
class LinkedList
{
public:
	LinkedList();

	LinkedList(const LinkedList&);
	~LinkedList();
	LinkedList& operator=(const LinkedList& src);
	bool isEmpty();

	void pushback(T&);
	void removeAt(size_t);
	void removeAllNodes();
	T& operator[](size_t)const;
	size_t getSize() const;

private:
	Node<T> *head;
	size_t size;
	void pushback(const Node<T>*);
	Node<T>* getNode(size_t) const;
	void copyNodes(const LinkedList&);
};

template <typename T>
Node<T>::Node(T &value) :value(value), next(nullptr), previous(nullptr) {}
template <typename T>
Node<T>::Node(const Node& src):Node(src.getValue()){
	std::cout << "Node Kopierkonstruktor" << std::endl;
}
template <typename T>
Node<T>::~Node() {
	//std::cout << "Delete: " << value << std::endl;
	delete(&value);
}
template <>
Node<int>::~Node() {}
template <>
Node<double>::~Node() {}
template <>
Node<long>::~Node() {}
template <>
Node<char>::~Node() {}

template <typename T>
void Node<T>::setNext(Node<T> *node)
{
	next = node;
}
template <typename T>
void Node<T>::setPrevious(Node<T> *node)
{
	previous = node;
}
template <typename T>
T& Node<T>::getValue() const
{
	return value;
}
template <typename T>
Node<T> *Node<T>::getNext() const
{
	return next;
}
template <typename T>
Node<T> *Node<T>::getPrevious() const
{
	return previous;
}



template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), size(0) {}
template <typename T>
LinkedList<T>::~LinkedList() {
	if (!isEmpty())
		removeAllNodes();	
}template <typename T>
LinkedList<T>::LinkedList(const LinkedList& src) : LinkedList() {
	std::cout << "CopyConstructor" << std::endl;
	copyNodes(src);
}
template <typename T>
bool LinkedList<T>::isEmpty() {
	if (head != nullptr)
		return false;
	return true;
}
template <typename T>
void LinkedList<T>::copyNodes(const LinkedList& src) {
	for (int i = src.getSize() - 1; i >= 0; --i) {
		this->pushback(src[i]);
	}
}
template <typename T>
void LinkedList<T>::pushback(T &value) {
	if (!isEmpty())
	{
		Node<T> *newNext = head;
		head = new Node<T>(value);
		newNext->setPrevious(head);
		head->setNext(newNext);
	}
	else {
		head = new Node<T>(value);
	}
	++size;
}
template <typename T>
void LinkedList<T>::pushback(const Node<T> *node){ 
	pushback(node->getValue());
}
template <typename T>
void LinkedList<T>::removeAt(size_t index) {
	Node<T> *removeNode = getNode(index);
	Node<T> *previous = removeNode->getPrevious();
	Node<T> *next = removeNode->getNext();

	if (next != nullptr)
		next->setPrevious(previous);
	if (previous != nullptr)
		previous->setNext(next);
	else
		head = next;
	delete(removeNode);
	--size;
}
template <typename T>
void LinkedList<T>::removeAllNodes() {
	if (!isEmpty()) {
		Node<T> *lastNode = getNode(size-1);
		while (lastNode->getPrevious() != nullptr) {
			Node<T> *prevNode = lastNode->getPrevious();
			delete(lastNode);
			lastNode = prevNode;
		}
		delete(lastNode);
		head = nullptr;
		size = 0;
	}
}
template <typename T>
T& LinkedList<T>::operator[](size_t index) const {
	return getNode(index)->getValue();
}
template <typename T>
Node<T>* LinkedList<T>::getNode(size_t index) const {
	if (index >= size && index > 0)
		throw std::out_of_range("OUT OF RANGE");
	Node<T> *currentNode = head;
	for (size_t i = 0; i < index; ++i) {
		currentNode = currentNode->getNext();
	}
	return currentNode;
}
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& src) {
	std::cout << "Zuweisungsoperator" << std::endl;
	removeAllNodes();
	copyNodes(src);
	return *this;
}
template <typename T>
size_t LinkedList<T>::getSize() const {
	return size;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list)
{
	for (size_t i = 0; i < list.getSize(); ++i) {
		out << "Index " << i << " = " << list[i] << "\n";
	}
	return out;
}


class Dummy {
public:
	Dummy::Dummy(int value):value(value){}
	int Dummy::getValue() const {
		return value;
	}
private:
	int value;
};

std::ostream& operator<<(std::ostream& out, const Dummy &dummy)
{
	out << dummy.getValue();
	return out;
}

void deleteList(LinkedList<int> &list) {

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
		LinkedList<Dummy> *list1Ptr = new LinkedList<Dummy>();
		LinkedList<Dummy> &list1 = *list1Ptr;
		for (int i = 0; i < 20; ++i) {
			list1.pushback(*new Dummy(i));
		}
		std::cout << list1 << std::endl;
		delete (list1Ptr);
		
		LinkedList<int> *list2Ptr = new LinkedList<int>();
		LinkedList<int> &list2 = *list2Ptr;
		for (int i = 0; i < 20; ++i) {
			list2.pushback(i);
		}
		std::cout << list2 << std::endl;
		delete (list2Ptr);
		/*LinkedList<int> *list1Ptr = new LinkedList<int>();
		LinkedList<int>& list1 = *list1Ptr;
		list1.pushback(1);
		list1.pushback(2);
		list1.pushback(3);

		std::cout << list1 << std::endl;

		LinkedList<int> list2 = list1;
		std::cout << "List1\n" << list1 << std::endl;
		std::cout << "List2\n" << list2 << std::endl;

		LinkedList<int> *list3Ptr = new LinkedList<int>();
		LinkedList<int> &list3 = *list3Ptr;
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

		LinkedList<int> *list4Ptr = new LinkedList<int>();
		LinkedList<int> &list4 = *list4Ptr;
		for (double i = 0; i < 500; ++i) {
			list4.pushback(i);
		}
		std::cout << "List4\n" << list4 << std::endl;
		int a = 0;
		for (int i = 0; a<250; i+2) {
			++a;
			list4.removeAt(i);
		}
		list4.removeAllNodes();
		delete(list4Ptr);
		*/

	}
	
	if (_CrtDumpMemoryLeaks())
		std::cout << "Memory Leak!" << std::endl;
}