#pragma once

// this abstract class defines the interface for a (min) PriorityQueue.
// it uses pointers rather than constant references.


template <typename T>
class PriorityQueue
{
public:
	virtual void insert(T* item) = 0;	// inserts the item into the heap
	virtual T* removeMin() = 0;			// returns minimum item and removes it from the heap
	virtual T* min() = 0;				// returns minimum item
};

