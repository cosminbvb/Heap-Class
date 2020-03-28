#include<iostream>
using namespace std;

#pragma once
class Heap
{
	//index starts from 1

	int max_size = 10000;
	int length; //number of elements in the array
	int heapSize; //represents how many elements in the heap are stored within the array
	int elements[10000]; //array of elements

public:
	Heap(int, int*); //constructor 

	//methods for Max-heap
	void maxHeapify(int); //runs in O(lg n) time, is the key to maintaining the max-heap property
	void buildMaxHeap(); //which runs in linear time, produces a maxheap from an unordered input array
	void heapSort(); //which runs in O(n lg n) time, sorts an array in place
	int heapMaximum(); //θ(1)
	int heapExtractMax(); //O(lg n)
	void heapIncreaseKey(int, int);//O(lg n)
	void maxHeapInsert(int);//O(lg n)

	//methods for Min-heap
	void minHeapify(int);
	void buildMinHeap();
	int heapMinimum();
	int heapExtractMin(); //O(lg n)
	void heapDecreaseKey(int, int);//O(lg n)
	void minHeapInsert(int);//O(lg n)

	void printHeap(); //prints the elements in the heap
	void printArray(); //prints the elements in the array 

protected:
	//helper methods
	int Parent(int);
	int Left(int);
	int Right(int);
	static void swap(int&, int&);
};


