// sorts the given array by selections sort
// By Niraj Mahajan IITB, CSE
#include <cstdio>
#include <iostream>

void selec_sort(int input[], int n);
void arr_swap(int input[], int n, int i , int j);

int main(void)
{
	int n;
	std::cout << "Array Size:  ";
	std::cin >> n;

	int input[n];

	std::cout << "Enter the terms of the array:\n";

	// take input
	for(int i = 0; i < n; i++)
	{
		std::cout << "Term " << (i+1) << ":  ";
		std::cin >> input[i];
	}

	// sort
	selec_sort(input, n);

	// output
	std::cout << "The sorted array is:\n";
	for(int i = 0; i < n; i++)
	{
		std::cout << input[i] << "  ";
	}
	std::cout << "\n";
}


// sorts the given array by selection sort
void selec_sort(int input[], int n)
{
	// variable head stores the index of the array which is being analysed
	int head = 0;
	
	// LI:  array terms of index 0, 1, ... (head-1) are sorted and are less than all unsorted terms
	// 		the next min term in unsorted terms will be swapped with the index 'head'
	do
	{
		int min_index = head;

		for(int i = head; i < n; i++)				// the next 'min' term is to be found in the unsorted region of array
		{
			if(input[i] < input[min_index])
			{								// potential min is found
				min_index = i;
			}
			else{/* carry on */}
		}

		// swap min with the head
		arr_swap(input, n, min_index, head);
		head++;
	}
	while(head != n);
}

void arr_swap(int input[], int n, int i , int j)
{
	if(i < 0 || j < 0 || i >= n || j >= n)
	{
		std::cout << "Error in swap\n";
		printf("i = %i\nj = %i\n", i, j);
		return;
	}

	int temp = input[i];
	input[i] = input[j];
	input[j] = temp;
	return;
}