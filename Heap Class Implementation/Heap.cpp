#include "Heap.h"

//index starts from 1

Heap::Heap(int length, int* elements) {
	this->length = length;
	heapSize = 0;
	for (int i = 1; i <= length; i++) {
		this->elements[i] = elements[i];
	}
}

#pragma region Methods for Max-heap

void Heap::maxHeapify(int i) {
	/*
	When it is called, maxHeapify assumes that the binary trees rooted at Left(i) and Right(i)
	are maxheaps, but that elements[i] might be smaller than its children, thus violating the max-heap
	property.
	*/
	int l, r, largest;
	l = this->Left(i);
	r = this->Right(i);
	if (l <= heapSize && elements[l] > elements[i]) largest = l;
	else largest = i;
	if (r <= heapSize && elements[r] > elements[largest]) largest = r;
	if (largest != i) {
		swap(elements[i], elements[largest]);
		maxHeapify(largest);
	}
}

void Heap::buildMaxHeap() {
	/*
	We can use the procedure maxHeapify in a bottom-up manner to convert an
	array A[1...n], where n = A.length, into a max-heap.
	The elements in the subarray A[(n/2)+1)...n] are all leaves of the tree,
	and so each is a 1-element heap to begin with. The method buildMaxHeap goes
	through the remaining nodes of the tree and runs maxHeapify on each one.

	-----------------------------------------------------------
	We can derive a tighter bound by observing that the time for MAX-HEAPIFY to
	run at a node varies with the height of the node in the tree, and the heights of most
	nodes are small.
	Our tighter analysis relies on the properties that an n-element heap
	has height [lgn] and at most [n/2^(h+1)] nodes of any height h.
	*/
	heapSize = length;
	for (int i = length / 2; i >= 1; i--) {
		this->maxHeapify(i);
	}
}

void Heap::heapSort() {

	buildMaxHeap();
	for (int i = length; i > 1; i--) {
		swap(elements[1], elements[i]);
		heapSize--;
		maxHeapify(1);
	}
}

int Heap::heapMaximum()
{
	return elements[1];
}

int Heap::heapExtractMax() {
	if (heapSize < 1) {
		cout << "heap underflow";
		exit(1);
	}
	int max = elements[1];
	elements[1] = elements[heapSize];
	heapSize--;
	maxHeapify(1);
	return max;
}

void Heap::heapIncreaseKey(int i, int key) {
	/*
	Because increasing the key of elements[i] might violate the
	max-heap property the method then traverses a simple path from
	this node toward the root to find a proper place for the newly
	increased key. As heapIncreaseKey traverses this path, it repeatedly
	compares an element to its parent, swaping their keys and continuing
	if the element's key is larger.
	The running time of this method on an n-element heap is O(lg n)
	since the path has length O(lg n)
	*/
	if (key < elements[i]) {
		cout << "new key is smaller than current key";
		exit(1);
	}
	elements[i] = key;
	while (i > 1 && elements[Parent(i)] < elements[i]) {
		swap(elements[i], elements[Parent(i)]);
		i = Parent(i);
	}
}

void Heap::maxHeapInsert(int key) {
	if (heapSize + 1 <= max_size) {
		heapSize++;
		elements[heapSize] = INT_MIN;
		heapIncreaseKey(heapSize, key);
	}
	else {
		cout << "Limit reached";
		exit(1);
	}
}

#pragma endregion

#pragma region Methods for Min-heap

void Heap::minHeapify(int i) {
	int l, r, smallest;
	l = Left(i);
	r = Right(i);
	if (elements[l] < elements[i] && l <= heapSize) {
		smallest = l;
	}
	else smallest = i;
	if (elements[r] < elements[smallest] && r <= heapSize) {
		smallest = r;
	}
	if (smallest != i) {
		swap(elements[smallest], elements[i]);
		minHeapify(smallest);
	}
}

void Heap::buildMinHeap() {
	heapSize = length;
	for (int i = length / 2; i >= 1; i--) {
		minHeapify(i);
	}
}

int Heap::heapMinimum() {
	return elements[1];
}

int Heap::heapExtractMin() {
	if (heapSize < 1) {
		cout << "heap underflow";
		exit(1);
	}
	int min = elements[1];
	elements[1] = elements[heapSize];
	heapSize--;
	minHeapify(1);
	return min;
}

void Heap::heapDecreaseKey(int i, int key) {

	if (key > elements[i]) {
		cout << "new key is bigger than current key";
		exit(1);
	}
	elements[i] = key;
	while (i > 1 && elements[Parent(i)] > elements[i]) {
		swap(elements[i], elements[Parent(i)]);
		i = Parent(i);
	}
}

void Heap::minHeapInsert(int key) {
	if (heapSize + 1 <= max_size) {
		heapSize++;
		elements[heapSize] = INT_MAX;
		heapDecreaseKey(heapSize, key);
	}
	else {
		cout << "Limit reached";
		exit(1);
	}
}

#pragma endregion

#pragma region Helper Methods

int Heap::Parent(int i) {
	return (i / 2);
}

int Heap::Left(int i) {
	return (2 * i);
}

int Heap::Right(int i) {
	return (2 * i + 1);
}

void Heap::swap(int& a, int& b) {
	int aux;
	aux = a;
	a = b;
	b = aux;
}

#pragma endregion

void Heap::printHeap() {
	for (int i = 1; i <= heapSize; i++) {
		cout << elements[i] << " ";
	}
	cout << endl;
}

void Heap::printArray() {
	for (int i = 1; i <= length; i++) {
		cout << elements[i] << " ";
	}
	cout << endl;
}