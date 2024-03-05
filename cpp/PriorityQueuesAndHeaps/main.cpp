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
    int a[12] = {1,5,14,2,10,21,18,3,11,8,7,12};
    Heap* h = createHeap(2,1);
    buildHeap(h, a, 12);

    return 0;
}