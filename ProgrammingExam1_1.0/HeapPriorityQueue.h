#pragma once
#include <iostream>
#include "PriorityQueue.h"

// this is an implementation of the PriorityQueue abstract class
// this implementation uses a heap.
using namespace std;

template <typename T>
class HeapPriorityQueue : public PriorityQueue<T>
{
public:
	HeapPriorityQueue();
	~HeapPriorityQueue();

	void insert(T* item);	// inserts the item into the heap
	T* removeMin();			// returns minimum item and removes it from the heap
	T* min();				// returns minimum item

	template <typename U>
	friend ostream& operator<< (ostream& out, HeapPriorityQueue<U> const & pQueue);

private:
	static const int STARTING_CAPACITY = 4;	// do not change!
	T** heap;								// an array of pointers to a T
	int numItems;							// number of items in queue
	int capacity;							// size of memory allocated


	void doubleHeapCapacity();
	void bubbleDown(int nodeIndex);
	void bubbleUp(int nodeIndex);

	// below are convenience functions; you are encouraged to use them where you can.

	// from an element's index in the array, we can calculate the index of its parent,
	// left child, or right child

	int parent(int index) {
		return (index - 1) / 2;		// this rounds down
	}
	bool hasParent(int index) {
		return index != 0;
	}
	int leftChild(int index) {
		return 2 * index + 1;
	}
	int rightChild(int index) {
		return 2 * index + 2;
	}
	bool hasChildren(int index) {
		return leftChild(index) < numItems;
	}
	bool hasOneChild(int index) {
		return leftChild(index) == numItems - 1;
	}
	bool isRoot(int index) { return index == 0; }

	void swapItems(int index1, int index2) {
		T* firstItem = heap[index1];
		heap[index1] = heap[index2];
		heap[index2] = firstItem;
	}
};
