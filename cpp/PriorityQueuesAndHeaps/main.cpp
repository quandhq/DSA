#include <iostream>
#include "Heap.cpp"

int main()
{
    // //=================TEST HEAP================
    // Heap* h = createHeap(11, 1);
    // insertElement(h, 2);
    // printHeap(h);
    
    // insertElement(h, 78);
    // printHeap(h);
    
    // insertElement(h, 19);
    // printHeap(h);
    
    // insertElement(h, 67);
    // printHeap(h);
    
    // insertElement(h, 34);
    // printHeap(h);

    // insertElement(h, 60);
    // printHeap(h);
    

    // deleteHeap(h);

    //===================test build heap======================

    int n = 12;
    int a[12] = {99, 67, 85, 56, 34, 19};
    Heap* h = createHeap(2,1);
    buildHeap(h, a, 6);
    printHeap(h);
    std::cout << "======================" << '\n';
    std::cout << "Element to be deleted: " << deleteElement(h, 1) << '\n';
    printHeap(h);
    std::cout << "Print all elements that less than" << '\n';
    printAllElementsThatLessThanValue(h, 99, 0);
    std::cout << '\n';


    deleteHeap(h);
    return 0;
}