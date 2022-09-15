#include <iostream>

#include "ArrayAndLinkedList.h"

int main()
{
    ArrayAndLinkedList arrLink;
    arrLink.PopulateArrayRand(0, 99);
    arrLink.PrintArray();
    arrLink.TransferDataToLinkedList();
    arrLink.PrintLinkedList();

    arrLink.AddToHead(3);
    arrLink.AddToHead(4);
    arrLink.AddToHead(5);
    arrLink.PrintLinkedList();
    
    return 0;
}
