#pragma once
#include <iostream>
#include <cmath>

/*
All functions in this file are used for max-heap  
 */


class Heap
{
public:
    int* arr;
    int count;
    int capacity;
    int heap_type;
};

Heap* createHeap(int capacity, int heap_type)
{
    //heap_type: 0 is min_heap, 1 is max_heap
    Heap* newHeap = new Heap;
    newHeap->capacity = capacity;
    newHeap->heap_type = heap_type;
    newHeap->count = 0;
    newHeap->arr = new int[capacity];
    return newHeap;
}

void deleteHeap(Heap* h)
{
    delete h->arr;
    delete h;
}

int parent(Heap* h, int i)
{
    if(i<=0 || i>=h->count) return -1;
    return (int)((i-1)/2);
}

int leftChild(Heap* h, int i)
{
    if(i<0 || i> parent(h, h->count-1)) return -1;
    int position = (2*i+1);
    if(position >= h->count) return -1; 
    return position;
}

int rightChild(Heap* h, int i)
{
    if(i<0 || i> parent(h, h->count-1)) return -1;
    int position = (2*i+2);
    if(position >= h->count) return -1; 
    return position;
}

int getMaximum(Heap* h)
{
    if(h->count == 0) return -1;
    return (h->arr)[0];
}

int log(int base, int value)
{
    if(value == 1) return 0;
    int res = 0;
    while(pow(2, res) < value)
    {
        ++res;
    }
    return pow(2, res-1);
}

void percolateDown(Heap* h, int i)
{
    std::cout << "percolate: " << h->arr[i] << '\n';
    //i: is the position that we want to percolate 
    //precolateDown: reallocate from top to bottom
    int l; //!< left child of node i
    int r; //!< right child of node i
    int temp; //!< use for swapping two nodes
    int max; //!< use for containing the node that has the maximum value between the current node and it's children
    l = leftChild(h, i);
    r = rightChild(h, i);
    std::cout << "left-"<< l << " right-" << r << '\n'; 
    if(l != -1 && (h->arr)[i] < (h->arr)[l]) //!< get the bigger element between i and it's left child
    {
        max = l; //!< element's value is smaller than it's left child
    } 
    else
    {
        max = i;            
    }
    //now max is the biggest element between i and it's left child

    if(r != -1 && (h->arr)[max] < (h->arr)[r])  //!< check if i's right child is bigger than both i and it's left child
    {
        max = r;
    }

    if(max == i) return;

    //swap the biggest element to i position
    temp = (h->arr)[max];
    (h->arr)[max] = (h->arr)[i];
    (h->arr)[i] = temp;

    percolateDown(h, max);
}


// /*
// insert an element to heap, if success return 1 else return -1 if any error appears 
//  */
// int insertElement(Heap* h, int elementToInsert)
// {
//     if(h->count == h->capacity) return -1;
//     (h->arr)[h->count] = elementToInsert;
//     ++(h->count);
//     return 1; 
// }

void printHeap(Heap* h)
{
    std::cout << "All elements of heap" << '\n';
    for(int i=0; i<(h->count); ++i)
    {
        std::cout << (h->arr)[i] << "-";
    }
    std::cout << '\n';
}

//return the first element of the heap (the maximum one)
int deleteElement(Heap* h)
{
    if(h->count == 0) return -1;
    int res = (h->arr)[0];
    (h->arr)[0] = (h->arr)[h->count-1];
    --(h->count);
    percolateDown(h, 0);
    return res;
}

void resizeHeap(Heap* h)
{
    int* oldArr = h->arr;
    int oldCapacity = h->capacity;
    h->arr = new int[2*oldCapacity];
    h->capacity = 2*oldCapacity;
    for(auto i=0; i<2*oldCapacity; ++i)
    {
        (h->arr)[i] = oldArr[i];
    }
    delete oldArr;
}

void insertElement(Heap* h, int element)
{
    if(h->count == h->capacity) resizeHeap(h);
    ++h->count;
    int pos = h->count - 1;
    
    /*
    Explain the below while loop:
        Assume that Heap h is alredy a max-heap, the last element that has just been added to the heep would be not in correct place.
        Go from node parent of that last node, we will use 'i' for storing the correct position of the newly added node, with the first
        iteration 'i' will be the last position of heap. Each step we will examine if that parent node is greater than the newly added node ('i'),
        if yes, newly added node has already in right place, if no, push the parent node down to 'i' position and 'i' now will take that 
        parent node position and maybe this will be the correct position.
     */
    
    while(pos > 0 && element > (h->arr)[(pos-1)/2])
    {
        (h->arr)[pos] = (h->arr)[(pos-1)/2];
        pos = (pos-1)/2;
    }
    (h->arr)[pos] = element; 
}

void buildHeap(Heap* h, int a[], int n)
{
    while(h->capacity < n)
    {
        resizeHeap(h);
    }
    
    h->count = n;
    for(int i=0; i<n; ++i)
    {
        (h->arr)[i] = a[i];
    }
    printHeap(h);

    // heapify from the parent of the last leaf (meaning that the first parent from the bottom) up to the top
    for(int i=(h->count-2)/2; i>=0; --i)
    {
        percolateDown(h, i);
    }

    // std::cout << h->arr[0];
    
    
    return;
}


int deleteElement(Heap* h, int i) //!< 'i' starts from 0
{
    if(i>=h->count) return -1;
    int elementToBeDeleted = h->arr[i]; 
    h->arr[i] = (h->arr)[(h->count)-1];
    --(h->count);
    std::cout << "---" << (h->arr)[i] << "----" << '\n';
    percolateDown(h, i);
    return elementToBeDeleted;
}

void printAllElementsThatLessThanValue(Heap* h, int value, int position)
{
    if(position == -1)
    {
        return;
    }
    if(h->arr[position] < value)
    {
        std::cout << h->arr[position] << '-';
        printAllElementsThatLessThanValue(h, value, leftChild(h, position));
        printAllElementsThatLessThanValue(h, value, rightChild(h, position));
        return;
    }
    if(h->arr[position] >= value)
    {
        printAllElementsThatLessThanValue(h, value, leftChild(h, position));
        printAllElementsThatLessThanValue(h, value, rightChild(h, position));
        return;
    }
}


