#include "HeapPriorityQueue.h"

// For this class to work, the type T must have a defined operator< and inserter ostream << T
//
// There are three places below in which you must insert code.  Each place is marked with a TODO comment.
// Be sure to read HeapPriorityQueue.h; there are helpful functions defined in there.
// You may change this file, and you may add function declarations to HeapPriorityQueue.h.  Those are the
// only changes you are allowed.  You may not remove or edit anything already in HeapPriorityQueue.h, and may
// not change Item, Driver, or PriorityQueue (.h or .cpp).  Driver.cpp contains main(), which reads the standard input.  The
// file Sample.txt is a sample input that you can use; you can compare your output to SampleOutput.txt.
//
// One sample file is not a test suite.  Passing the sample is not a confirmation that everything is right.
// You can build your own test inputs if you'd like and if you have the time.
//
// happy coding!


template<typename T>
HeapPriorityQueue<T>::HeapPriorityQueue()
{
	numItems = 0;
	capacity = STARTING_CAPACITY;
	heap = new T*[capacity];
}

template<typename T>
HeapPriorityQueue<T>::~HeapPriorityQueue()
{
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//TODO: appropriate cleanup of memory resources used.

	delete[] heap;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

// DO NOT CHANGE THIS FUNCTION
template<typename T>
void HeapPriorityQueue<T>::insert(T* item)
{
	// see if we have a full array; if so, double the size of the array.
	if (numItems == capacity) {
		doubleHeapCapacity();
		cout << "doubling..." << endl;
	}

	const int newItemIndex = numItems;
	heap[newItemIndex] = item;
	numItems++;

	// repair the heap: the new item may be in the wrong place.

	                          //////////////////////////////////////////////////////////////////////////////////
	bubbleUp(newItemIndex);	  // TODO: you must create and write this function.
							  // this operation must complete in O(log n) time.
	                          //////////////////////////////////////////////////////////////////////////////////
}
template<typename T>
void HeapPriorityQueue<T>::doubleHeapCapacity() {

	T** tempHeap= new T*[capacity*2];
	for(int i=0; i<capacity; i++)
	{
		tempHeap[i]= this->heap[i];
	}
	this->capacity*=2;
	heap= new T*[capacity];

	for(int i=0; i<capacity; i++)
	{
		heap[i]= tempHeap[i];
	}

	delete[] tempHeap;
}
template <typename T>
void HeapPriorityQueue<T> :: bubbleUp(const int index)
{

	int parentPosition;
	int tempIndex = index;

    /*if(heap[index]>=heap[parentPosition])
            return;
    else
    {
    	swapItems(index, parentPosition);
      	tempIndex= parentPosition;
        bubbleUp(tempIndex);
    }*/

    while(tempIndex!=0)
    {
   		parentPosition= (tempIndex-1)/2;
    	if(heap[index]>= heap[parentPosition])
    	{
    		return;
    	}
    	else
    	{
    		swap(tempIndex, parentPosition);
    		tempIndex= parentPosition;
    	}
    }

template<typename T>
void HeapPriorityQueue<T>::bubbleDown(int nodeIndex)
{
	if (!hasChildren(nodeIndex)) {			// we're at the bottom of the heap.  Stop.
		return;
	}

	int leftIndex = leftChild(nodeIndex);
	int rightIndex = rightChild(nodeIndex);

	if (hasOneChild(nodeIndex)) {
		T* item = heap[nodeIndex];
		T* leftItem = heap[leftIndex];

		if (*leftItem < *item) {
			swapItems(nodeIndex, leftIndex);
		}
		return;
	}

	T* item      = heap[nodeIndex];
	T* leftItem  = heap[leftIndex];
	T* rightItem = heap[rightIndex];

	int minIndex = (*leftItem < *rightItem) ? leftIndex : rightIndex;
	T* minItem = heap[minIndex];

	if (*item < *minItem) {			// we're less than our children.  Stop.
		return;
	}
	swapItems(nodeIndex, minIndex);
	bubbleDown(minIndex);

}

template<typename T>
T* HeapPriorityQueue<T>::removeMin()
{
	T* result = heap[0];

	// repair the heap: replace item 0 with the last item, then restore the heap property
	// by "bubbling" this replacement item to the correct place.  Be sure that numItems is correctly set.

	heap[0] = heap[numItems - 1];
	numItems--;
	bubbleDown(0);

	return result;
}

template<typename T>
T* HeapPriorityQueue<T>::min()
{
	return heap[0];
}

// DO NOT CHANGE
template<typename T>
ostream& operator<< (ostream& out, HeapPriorityQueue<T> const & pQueue)
{
	out << "numItems: " << pQueue.numItems << endl;
	out << "capacity: " << pQueue.capacity << endl;
	for (int i = 0; i < pQueue.numItems; i++) {
		out << *pQueue.heap[i] << endl;
	}

	return out;
}
