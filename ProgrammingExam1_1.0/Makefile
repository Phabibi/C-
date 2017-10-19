all: driver

driver: Item.o HeapPriorityQueue.o Driver.o
	g++ -Wall -std=c++11 Item.o HeapPriorityQueue.o Driver.o -o driver 

Driver.o: Driver.h Driver.cpp HeapPriorityQueue.h HeapPriorityQueue.cpp Item.h
	g++ -Wall -std=c++11 -c Driver.cpp

HeapPriorityQueue.o: HeapPriorityQueue.h HeapPriorityQueue.cpp PriorityQueue.h
	g++ -Wall -std=c++11 -c HeapPriorityQueue.cpp

Item.o: Item.h Item.cpp
	g++ -Wall -c Item.cpp

clean:
	rm -f driver *.o
