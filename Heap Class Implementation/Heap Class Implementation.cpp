// Heap Class Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Heap.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f("test.txt");
	int size;
	int a[100]; //index starts from 1
	f >> size;
	for (int i = 1; i <= size; i++) {
		f >> a[i];
	}
	cout << "Test on A:" << endl;
	Heap A = Heap(size, a);
	A.buildMaxHeap();
	A.printHeap();
	A.printArray();
	A.heapSort();
	A.printArray();
	cout << "Test on B:" << endl;
	Heap B = Heap(size, a);
	B.buildMinHeap();
	B.printHeap();
	B.heapExtractMin();
	B.printHeap();
	B.minHeapInsert(6);
	B.printHeap();
    
	return 0;
}

