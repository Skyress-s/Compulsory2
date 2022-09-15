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
    for (size_t i = 0; i < std::size(staticArray); ++i)
    {
        std::cout << staticArray[i] << " ";
    }
    std::cout << std::endl;
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
