#include <iostream>
using namespace std;

void displayArray(int A[], int size);
int partition(int A[], int start, int end);
void quicksort(int A[], int start, int end);

int main() {
	int A[] = {1, 2, 4, 3};
	int size = 4;
	quicksort(A, 0, 3);
	displayArray(A, size);
}

void displayArray(int A[], int size) {
	for (int i = 0; i < size; i++) {
		if (i == size - 1){
			cout << A[i] << endl;
		} else {
			cout << A[i] << ", ";
		}
	}
}


int partition(int A[], int start, int end){
	int anchor = A[end];
	int index = start - 1;

	for (int i = start; i < end; i++) {
		if (A[i] <= anchor) {
			index++;
			int temp = A[i];
			A[i] = A[index];
			A[index] = temp;
		}
	}
	int temp = A[end];
	A[end] = A[index+1];
	A[index+1] = temp;
	return index +1;
}
void quicksort(int A[], int start, int end) {
	if (start < end) {
		int mid = partition(A, start, end);

		partition(A, start, mid-1);
		partition(A, mid+1, end);
	}
}