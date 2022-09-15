#include <iostream>

#include "ArrayAndLinkedList.h"

int main()
{
    ArrayAndLinkedList arrLink;
    arrLink.PopulateArrayRand(0, 99);
    arrLink.PrintArray();
    arrLink.TransferDataToLinkedList();
    
    return 0;
}
