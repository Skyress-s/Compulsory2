﻿#include "ArrayAndLinkedList.h"
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
    head->prev = newNode;
    _size++;
    
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


void ArrayAndLinkedList::PopBack()
{

}

void ArrayAndLinkedList::SortList(ArrayAndLinkedList linkedlist,int begin, int end)
{
    if (begin >= end)
        return;

    int middle = (begin + (end - begin)) / 2;
   

    SortList(linkedlist,  begin,  middle);
    SortList(linkedlist,  middle+1,  end);
    MergeList(linkedlist, begin, middle, end);
}


int& ArrayAndLinkedList::operator[](const int index)
{
    Node* current_node = this->head;
    int count{ 0 };
    while (current_node != nullptr) {
        if (count == index)
            return current_node->data;

        current_node = current_node->next;
        count++;
    }
}





void ArrayAndLinkedList::MergeList(ArrayAndLinkedList linkedlist, int start, int middle, int end)
{
    const int size_sub_list_1{ middle+1- start};
    const int size_sub_list_2{ middle - start};

    ArrayAndLinkedList* linked_list_1 = new ArrayAndLinkedList[size_sub_list_1];
    ArrayAndLinkedList* linked_list_2 = new ArrayAndLinkedList[size_sub_list_2];

    //copy data from the main linked list to the sublists
    for(int i{}; i < size_sub_list_1; i++) {
        linked_list_1[i] = linked_list_1[start+i]; //copying starts from "start" for the first sublink
    }
    for(int i{}; i < size_sub_list_2; i++ ) {
        linked_list_2[i] = linked_list_2[(middle+1) + i];
    }

    int start_index_list_1{ 0 };
    int start_index_list_2{ 0 };
    int start_index_merged_list{ 0 };

    do {
        if (linked_list_1->At(start_index_list_1) < linked_list_2->At(start_index_list_2)) {
            linkedlist[start_index_merged_list] = linked_list_1->At(start_index_list_1);
        }

    } while (start_index_list_1 < size_sub_list_1
        && start_index_list_2 < size_sub_list_2);
}