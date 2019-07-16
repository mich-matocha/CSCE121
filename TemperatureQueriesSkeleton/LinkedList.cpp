#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() //default constructor
{
	head = nullptr;
}

LinkedList::~LinkedList() //destructor
{
	Node* next = nullptr;
    while (head)
    {
        next = head->next;
        delete head;
        head = next;
    }
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList& source) //copy constructor
{
	Node* n = source.head;

    Node* newN = new Node(source.head->data.id, source.head->data.year, source.head->data.month, source.head->data.temperature);
    head = newN;

    while (n->next != nullptr)
    {
        n = n->next;
        newN = new Node(n->data.id, n->data.year, n->data.month, n->data.temperature);
        insert(newN->data.id, newN->data.year, newN->data.month, newN->data.temperature);
    }
}

LinkedList& LinkedList::operator=(const LinkedList& source)//copy assignment operator
{
	Node* n = source.head;
    Node* newN = new Node(source.head->data.id, source.head->data.year, source.head->data.month, source.head->data.temperature);
    head = newN;
        
    while (n->next != nullptr)
    {
        n = n->next;
        newN = new Node(n->data.id, n->data.year, n->data.month, n->data.temperature);
        insert(newN->data.id, newN->data.year, newN->data.month, newN->data.temperature);
    }
}

//Inserting at wrong place so that means nothing works!!
void LinkedList::insert(string location, int year, int month, double temperature) //FIXME: insert at correct location!!!
{

	Node* n = new Node(location, year, month, temperature);
	bool inserted = false;

	if(head == nullptr && !inserted)
	{
		head = n;
		n->next = nullptr;
		inserted = true;
	}
	Node* curr = head;
	if(*n < *curr && !inserted) //checking if n needs to go before the head ***FIXME: THIS IS THE LINE THAT IS WRONG
	{
		n->next = curr;
		head = n;
		inserted = true;
	}

	while(curr->next != nullptr && !inserted && *curr->next < *n) //finding where exactly n needs to be inserted
	{
		curr = curr->next;
	}

	if(!inserted) //as long as it isn't still inserted
	{
		n->next = curr->next;
		curr->next = n;
	}
}

void LinkedList::clear()
{
	Node* next = nullptr;
    while (head)
    {
        next = head->next;
        delete head;
        head = next;
    }
    head = nullptr;
}

Node* LinkedList::getHead() const
{
	return this->head;
}

string LinkedList::print() const {
	stringstream ret;
	Node* n = head;

	if(n != nullptr)
	{
		ret << n->data.id << " " << n->data.year << " " << n->data.month << " " << n->data.temperature << endl;
	}

	while (n->next != nullptr)
	{
		ret << n->next->data.id << " " << n->next->data.year << " " << n->next->data.month << " " << n->next->data.temperature << endl;
		n = n->next;
	}

	return ret.str();
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
