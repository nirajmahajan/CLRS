#include <iostream>
#include <array>
using namespace std;

void displayArray(int A[], int size) {
	for (int i = 0; i < size; i++) {
		if (i == size- 1){
			cout << A[i] << endl;
		} else {
			cout << A[i] << ", ";
		}
	}
}

// Pre condition : left and right branches of tree about root 'i' are max-heaps
// post condition : tree about root i is a max-heap
void maxHeapify(int A[], int i, int size) {
	int l = 2 * i;
	int r = (2 * i) + 1;
	int heapSize = size;
	int largest;

	// check with the left element
	if (l <= heapSize && A[l-1] > A[i-1]) {
		largest = l-1;
	}
	else {
		largest = i-1;
	}

	// check with the right element
	if (r <= heapSize && A[r-1] > A[largest]) {
		largest = r-1;
	}

	// swap if root is not the largest
	if (largest != i-1) {
		int temp = A[largest];
		A[largest] = A[i-1];
		A[i-1] = temp;

		maxHeapify(A, largest + 1, size);
	}
}

// post condition : A is a max-heap
void buildMaxHeap(int A[], int size) {
	int heapSize = size;
	for (int i = heapSize/2 ; i > 0; i--) {
		maxHeapify(A, i, size);
	}
}

void heapsort(int A[], int size) {
	int heapSize = size;
	buildMaxHeap(A, size);

	for (int i = size; i > 1; i--) {
		int temp = A[0];
		A[0] = A[i-1];
		A[i-1] = temp;

		heapSize--;
		maxHeapify(A, 1, heapSize);
	}

}

int main() {
	int A[] = {1, 2, 4, 3};
	int size = 4;
	heapsort(A, size);

	displayArray(A, size);
}