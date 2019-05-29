// sorts the given array by selections sort
// By Niraj Mahajan IITB, CSE
#include <cstdio>
#include <iostream>

void bubble_sort(int input[], int n);
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

	bubble_sort(input, n);

	std::cout << "The sorted array is:\n";

	for(int i = 0; i < n; i++)
	{
		std::cout << input[i] << "  ";
	}

	std::cout << "\n";
}

void bubble_sort(int input[], int n)
{
	int swap_count = 0;

	do
	{
		swap_count = 0;
		for(int i = 0; i < n-1; i++)
		{
			if(input[i] > input[i+1])
			{
				arr_swap(input, n, i, i+1);
				swap_count++;
			}
		}
	}
	while(swap_count != 0);
}

// swaps the ith and the jth terms of an array
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