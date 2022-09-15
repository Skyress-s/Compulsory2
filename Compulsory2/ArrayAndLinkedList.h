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
    
    void PopulateArrayRand(int min, int max);
    void TransferDataToLinkedList();
    void PrintArray();
    void PrintLinkedList();

    // linked list functions
    void AddToEnd(int data);
    int Size(){ return _size; }
    Node* At(int index);
    
private:
    int _size{};
    Node* head = nullptr;
    Node* tail = nullptr;
    
};
