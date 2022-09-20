#pragma once

class Node {
public:
    Node(int newData) {
        data = newData;
    }
    
    int data = -1;
    Node* next = nullptr;
    Node* prev = nullptr;
    
private:
    
};

class ArrayAndLinkedList
{
public:
    int staticArray[40]{};

    // array functions
    void PopulateArrayRand(int min, int max);
    void TransferDataToLinkedList();
    void PrintArray();
    
    // linked list functions
    void PrintLinkedList();
    void AddToTail(int data);
    void AddToHead(int data);
    void InsertAt (int data, int index);
    int Size(){ return _size; }
    Node* At(int index);
    int ReadFrom(int index, Node* N);
    void PopBack();

    void MergeList(ArrayAndLinkedList &linkedlist, int start, int middle, int end); //the type of the sorting is not decided yet. 
    void SortList(ArrayAndLinkedList &linkedlist, int begin, int end); //DevideLinkedList can be removed depending on what sorting algorithm  we are going to use

    void RemoveAt(int index);

    //operator overloading
    int& operator [] (const int index);
    //copy constructor

  
    
private:
    int _size{};
    Node* head = nullptr;
    Node* tail = nullptr;
    
};
