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
    void AddToEnd(int data);
    void AddToHead(int data);
    int Size(){ return _size; }
    Node* At(int index);
    int ReadFrom(int index, Node* N);
    void PopBack();
<<<<<<< HEAD
    void MergeList(ArrayAndLinkedList &linkedlist, int start, int middle, int end); //the type of the sorting is not decided yet. 
    void SortList(ArrayAndLinkedList &linkedlist, int begin, int end); //DevideLinkedList can be removed depending on what sorting algorithm  we are going to use
=======
    void RemoveAt(int index);
    void MergeList(ArrayAndLinkedList linkedlist, int start, int middle, int end); //the type of the sorting is not decided yet. 
    void SortList(ArrayAndLinkedList linkedlist, int begin, int end); //DevideLinkedList can be removed depending on what sorting algorithm  we are going to use
>>>>>>> 89a01c2fb14aff8d7571542f84e68d2c7734c15e
    //operator overloading
    int& operator [] (const int index);
    //copy constructor

  
    
private:
    int _size{};
    Node* head = nullptr;
    Node* tail = nullptr;
    
};
