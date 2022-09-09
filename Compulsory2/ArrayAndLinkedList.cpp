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

void ArrayAndLinkedList::PrintArray()
{
    for (size_t i = 0; i < std::size(staticArray); ++i)
    {
        std::cout << staticArray[i] << " ";
    }
    std::cout << std::endl;
}
