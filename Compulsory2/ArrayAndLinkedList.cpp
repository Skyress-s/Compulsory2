#include "ArrayAndLinkedList.h"
#include <iostream>
#include "Random.h"

void ArrayAndLinkedList::PopulateArrayRand(int min, int max)
{
    std::uniform_int_distribution<> intDistribution{min, max};
    for (size_t i = 0; i < std::size(staticArray); ++i) {
        const int d = intDistribution(gen64);
        staticArray[i] = d;
    }
}

void ArrayAndLinkedList::TransferDataToLinkedList() {
    for (int i = 0; i < std::size(staticArray); ++i) { // 
        AddToEnd(staticArray[i]);
    }
}

void ArrayAndLinkedList::PrintArray()
{
    std::cout << "Printing array" << std::endl;
    for (size_t i = 0; i < std::size(staticArray); ++i)
    {
        std::cout << staticArray[i] << " ";
    }
    std::cout << std::endl;
}

void ArrayAndLinkedList::PrintLinkedList()
{
    std::cout << "Printing linked list from head:" << std::endl;
    int count = 0;
    Node* h = head;   
    while (h != NULL) {
        std::cout << h->data << " ";
        h = h->next;
        count++;
    }
    std::cout << std::endl;
    std::cout << "Printing linked list from tail:" << std::endl;
    Node* t = tail;   
    while (t != NULL) {
        std::cout << t->data << " ";
        t = t->prev;
        count++;
    }
    std::cout << std::endl;
    std::cout << "Number of elements in linked list: " << count << std::endl;
}

void ArrayAndLinkedList::AddToEnd(int data) {
    // if size is zero
    Node* newNode = new Node(data);
    if (_size == 0) { // if size zero
        tail = head = newNode;
        _size++;
        return;
    }

    Node* prevTail = tail;
    tail = newNode;
    prevTail->next = tail;
    tail->prev = prevTail;
    _size++;
}

void ArrayAndLinkedList::AddToHead(int data)
{
    Node* newNode = new Node(data);
    // if size zero
    if (_size == 0) {
        tail = head = newNode;
        _size++;
        return;
    }

    newNode->next = head;

    head = newNode;
}

/**
 * \brief 
 * \param index finds and returns element of index, return nullptr if out of range
 * \return 
 */
Node* ArrayAndLinkedList::At(int index) {
    // bail check
    if (index < 0 || index >= _size) 
        return nullptr;

    
    Node* searchNode = head;
    for (int i = 0; i < index; ++i) {
        searchNode = searchNode->next;
    }
    return searchNode;
}
