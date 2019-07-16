#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <algorithm>
#include <string>
#include "Node.h"

using namespace std;

template<typename T>
class LinkedList {
public:
    LinkedList();
    LinkedList(std::string);

    LinkedList(const LinkedList<T>&);
    LinkedList(LinkedList<T>&&);
    LinkedList& operator=(const LinkedList<T>&);
    LinkedList& operator=(LinkedList<T>&&);
    ~LinkedList();

    void set_name(std::string);
    std::string get_name() const;
    Node<T>* get_head() const;
    Node<T>* get_tail() const;

    bool is_empty() const;
    void insert_front(T);
    void insert_back(T);
    bool insert_after (T, T);
    void clear();

private:
    Node<T>* head;
    Node<T>* tail;
    std::string name;
    void null_head(bool);
    void null_tail(bool);
    void swap(LinkedList<T>& l1, LinkedList<T> l2);
    void log(const std::string& what) const;
};

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ll)
{
    os << ll.get_name() << " {";
    Node<T>* current = ll.get_head();
    if (current == nullptr) {
        os << " <Empty List>";
    }
    while (current != nullptr) {
        if (current != ll.get_head())
            os << ",";
        os << " " << current->value;
        current = current->next;
    }
    os << " }";
    //os << std::endl << ll.get_head() << '\t' << ll.get_tail() << std::endl;
    return os;
}

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template<typename T>
LinkedList<T>::LinkedList(string name) : head(nullptr), tail(nullptr), name(name) {}

template<typename T>
LinkedList<T>::~LinkedList()
{
    this->clear();
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& source)
{
    Node<T> * source_node = source.get_head();
    head = new Node<T>(source_node->value);
    Node<T> * current_node = head;
    tail = head;
    source_node = source_node->next;
    while (source_node) {
        current_node->next = new Node<T>(source_node->value);
        tail = current_node->next;
        current_node = current_node->next;
        source_node = source_node->next;
    }
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& source)
{
    head = source.get_head();
    tail = source.get_tail();
    source.null_head(true);
    source.null_tail(true);
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
    if (this != &rhs && !rhs.is_empty()) {
        this->swap(*this, rhs); // copy-and-swap idiom
    }
    return *this;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& source)
{
    if (this != &source) {
        Node<T>* next = nullptr;
        clear();
        head = source.get_head();
        tail = source.get_tail();
        source.null_head(true);
        source.null_tail(true);
    }
    return *this;
}

template<typename T>
void LinkedList<T>::set_name(string name)
{
    this->name = name;
}

template<typename T>
string LinkedList<T>::get_name() const
{
    return name;
}

template<typename T>
Node<T>* LinkedList<T>::get_head() const
{
    return head;
}

template<typename T>
Node<T>* LinkedList<T>::get_tail() const
{
    return tail;
}

template<typename T>
bool LinkedList<T>::is_empty() const
{
    if (head == nullptr && tail == nullptr)
        return true;
    else
        return false;
}

template<typename T>
void LinkedList<T>::insert_front(T value)
{
    Node<T>* newNode = new Node(value);
    if (head != nullptr)
        newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
}

template<typename T>
void LinkedList<T>::insert_back(T value)
{
    Node<T>* newNode = new Node<T>(value);
    if (tail != nullptr)
        tail->next = newNode;
    tail = newNode;
    if (head == nullptr) {
        head = tail;
    }
}

template<typename T>
bool LinkedList<T>::insert_after (T after_val, T insert_val)
{
    if (is_empty())
        return false;
    Node<T> * curr = head;
    while (curr != nullptr) {
        if (curr->value == after_val) {
            Node<T>* new_node = new Node(insert_val);
            new_node->next = curr->next;
            curr->next = new_node;
            if (curr == tail)
                tail = new_node;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template<typename T>
void LinkedList<T>::clear()
{
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* deleteNode = current;
        current = current->next;
        delete deleteNode;
    }
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void LinkedList<T>::null_head(bool i_am_sure) { if (i_am_sure) head = nullptr; }
template<typename T>
void LinkedList<T>::null_tail(bool i_am_sure) { if (i_am_sure) tail = nullptr; }

template<typename T>
void LinkedList<T>::swap(LinkedList& l1, LinkedList l2)
{
    // LinkedList l2 is passed-by-value to this function, so copy constructor creates the object that is put on the stack.
    std::swap(l1.head, l2.head); // swaps l1.head with l2.head
    std::swap(l1.tail, l2.tail); // swaps l1.tail with l2.tail
    // l2's goes out of scope as the function returns, causing l1's original nodes to be deleted (because l2's head now points to l1's orignal head)
}

template<typename T>
void LinkedList<T>::log(const string& what) const
{
    std::cout << "[" << this << "] " << what << std::endl;
}



#endif