#include <iostream>

#include "ArrayAndLinkedList.h"

int main()
{
    ArrayAndLinkedList arrLink;
    arrLink.PopulateArrayRand(0, 99);
    arrLink.PrintArray();
    arrLink.TransferDataToLinkedList();
    arrLink.PrintLinkedList();
    
    return 0;
}
