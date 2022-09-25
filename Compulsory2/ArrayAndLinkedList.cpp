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
        AddToTail(staticArray[i]);
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
    count = 0;
    Node* t = tail;   
    while (t != NULL) {
        std::cout << t->data << " ";
        t = t->prev;
        count++;
    }
    std::cout << std::endl;
    std::cout << "Number of elements in linked list: " << count << std::endl;
}

void ArrayAndLinkedList::AddToTail(int data) {
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

void ArrayAndLinkedList::InsertAt(int data, int index)
{
    Node* newNode = new Node(data);
    Node* tmp = head;
    int count = 1;

    if (index == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        _size++;
        head = newNode;
        return;
    }
    while (count < index)
    {
        if (tmp->next != nullptr)
            tmp = tmp->next;
        else
        {
            std::cout << "Given index was out of range" << std::endl;
            return;
        }
        count++;
    }
    Node* tmp2 = tmp->next;
    tmp->next = newNode;
    newNode->prev = tmp;
    newNode->next = tmp2;
    tmp2->prev = newNode;

    std::cout << "Node created at index " << index << " with data: " << data << std::endl;
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

int ArrayAndLinkedList::ReadFrom(int index, Node* N)
{
    return N->data;
}


void ArrayAndLinkedList::PopBack()
{
    tail = tail->prev;
    delete tail->next;
    tail = nullptr;
    _size--;
}

void ArrayAndLinkedList::RemoveAt(int index) {
    // bail checks
    if (index < 0 || index > _size - 1) {
        std::cout << "ERROR INDEX AT REMOVE AT WAS OUT OF RANGE: " << index << std::endl;
        return;
    }

    // special case if size is 1
    if (_size == 1) {
        delete head;
        head = tail = nullptr;
    }

    // logic for remove at
    Node* searchNode = head;
    for (int i = 0; i < _size; ++i) {
        if (i == index) {
            Node* oldNext = searchNode->next;
            Node* oldPrev = searchNode->prev;

            if (oldNext != nullptr) {
                oldNext->prev = oldPrev;
            }
            else {
                tail = oldPrev;
            }
            if (oldPrev != nullptr) {
                oldPrev->next = oldNext;
            }
            else {
                head = oldNext;
            }
            
            delete(searchNode);
            break;
        }
        searchNode = searchNode->next;
    }

    _size--;
}

void ArrayAndLinkedList::SortList(ArrayAndLinkedList &linkedlist,int begin, int end)
{
    if (begin>=end)
    {
        return; 
    }


    int middle = begin + (end-begin) / 2;

   

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





void ArrayAndLinkedList::MergeList(ArrayAndLinkedList &linkedlist, int start, int middle, int end)
{
    const int size_sub_list_1{ middle+1- start};
    const int size_sub_list_2{ end - middle};

    ArrayAndLinkedList* linked_list_1 = new ArrayAndLinkedList[size_sub_list_1];
    ArrayAndLinkedList* linked_list_2 = new ArrayAndLinkedList[size_sub_list_2];

    //copy data from the main linked list to the sublists
    for(int i{}; i < size_sub_list_1; i++) {
        linked_list_1->AddToHead(linkedlist.At(start+i)->data); //copying starts from "start" for the first sublink
      
    }
    for(int i{}; i < size_sub_list_2; i++ ) {
        linked_list_2->AddToHead(linkedlist.At(middle + i+1)->data);
    }

    int start_index_list_1{ 0 };
    int start_index_list_2{ 0 };
    int start_index_merged_list{ 0 };

    do {
        if (linked_list_1->At(start_index_list_1) < linked_list_2->At(start_index_list_2)) {
            linkedlist.At(start_index_merged_list)->data = linked_list_1->At(start_index_list_1)->data;
            start_index_list_1++;
        }
        else  {
            linkedlist.At(start_index_merged_list)->data = linked_list_2->At(start_index_list_2)->data;
            start_index_list_2++;
        }
        start_index_merged_list++;
    } while (start_index_list_1 < size_sub_list_1
        && start_index_list_2 < size_sub_list_2);

    while (start_index_list_1 < size_sub_list_1) {
        linkedlist.At(start_index_merged_list)->data = linked_list_1->At(start_index_list_1)->data;
        start_index_list_1++;
        start_index_merged_list++;
    }
    while (start_index_list_1 < size_sub_list_1) {
        linkedlist.At(start_index_merged_list)->data = linked_list_1->At(start_index_list_1)->data;
        start_index_list_1++;
        start_index_merged_list++;
    }
    while (start_index_list_2 < size_sub_list_2) {
        linkedlist.At(start_index_merged_list)->data = linked_list_2->At(start_index_list_2)->data;
        start_index_list_2++;
        start_index_merged_list++;
    }
    
   


}

void ArrayAndLinkedList::BubbleSort(ArrayAndLinkedList& linkedlist, int size_list)
{
    int i{};
    int j{};
    for (i = 0; i < size_list; i++) {
        for (j = 0; j < size_list - 1; j++) {
            if (linkedlist[j] > linkedlist[j + 1]) {
                swap_n(linkedlist.At(j), linkedlist.At(j + 1));
            }
        }
    }
}

void ArrayAndLinkedList::swap_n(Node* a, Node* b)
{
    Node* temp = new Node(0);
    temp->data = a->data;
    a->data = b->data;
    b->data = temp->data;
}

void ArrayAndLinkedList::SelectionSort(ArrayAndLinkedList& list, int size_n)
{
    int i{ 0 }, j{ 0 }, min_elem{};
    for (i = 0; i < size_n; i++) {
        min_elem = i;
        for (j = i+1; j < size_n; j++) {
            if (list[min_elem] > list[j]) 
            min_elem = j;
            
        }
        if(min_elem!=i)
        swap_n(list.At(min_elem), list.At(i));
    }
}
