#include <iostream>

#include "ArrayAndLinkedList.h"

int main()
{
    ArrayAndLinkedList arrLink;
    arrLink.PopulateArrayRand(0, 99);
    // arrLink.PrintArray();
    arrLink.TransferDataToLinkedList();
    arrLink.PrintLinkedList();

    arrLink.InsertAt(10, 2);
    arrLink.PrintLinkedList();
   
     arrLink.AddToHead(3);
     arrLink.AddToHead(4);
     arrLink.AddToHead(5);
     arrLink.RemoveAt(1);
     arrLink.PrintLinkedList();
      std:: cout << "_" << arrLink.Size()<< std::endl;
    
    
    // arrLink.SortList(arrLink, 0, (arrLink.Size() - 1));
     std::cout << "List !!!!!" << std::endl;
    arrLink.SelectionSort(arrLink, arrLink.Size()-1);
    arrLink.PrintLinkedList();

    
    return EXIT_SUCCESS;
    system("exit");
}
