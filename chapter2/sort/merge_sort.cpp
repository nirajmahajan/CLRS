// sorts the given array by selections sort
// By Niraj Mahajan IITB, CSE
#include <cstdio>
#include <iostream>

void merge_sort(int input[],int output[], int n, int i, int j);
void merge(int input[], int output[], int n, int i, int j, int p, int q);

int main(void)
{
	int n;
	std::cout << "Array Size:  ";
	std::cin >> n;

	int input[n];
	int output[n];

	std::cout << "Enter the terms of the array:\n";

	// take input
	for(int i = 0; i < n; i++)
	{
		std::cout << "Term " << (i+1) << ":  ";
		std::cin >> input[i];
		output[i] = input[i];
	}

	// sort
	merge_sort(input, output, n, 0 , (n-1));

	// output
	std::cout << "The sorted array is:\n";
	for(int i = 0; i < n; i++)
	{
		std::cout << output[i] << "  ";
	}
	std::cout << "\n";
}

// sorts an array between index i, j inclusive
void merge_sort(int input[],int output[], int n, int i, int j)
{

	// ensure i > j
	int temp = i+j;
	j = std::max(i, j);
	i = temp - j;


	int mid = (i+j)/2;

	if(i == j)
	{
		return;
	}
	else if(i == mid)
	{
		merge(input, output, n, i, i, j, j);
	}
	else
	{
		merge_sort(input,output, n, i, mid);
		merge_sort(input,output, n, (mid+1), j);
		merge(input, output, n, i, mid, (mid+1), j);
	}
}

// merges two parts of array
// merges terms of index (i to j) with (p to q) in ascending order
// ensure i > j > p > q
void merge(int input[], int output[], int n, int i, int j, int p, int q)
{
	if(i > j || p > q || j >= p || q >= n)
	{
		printf("Merge Error\ni = %i\nj = %i\np = %i\nq = %i\n", i, j, p, q);
		return;
	}

	int index1 = i;
	int index2 = p;

	for(int k = i; k <= q; k++)
	{
		if(index1 > j)
		{
			output[k] = input[index2];
			(index2)++;
		}
		else if(index2 > q)
		{
			output[k] = input[index1];
			(index1)++;
		}
		else if(input[index1] < input[index2])
		{
			output[k] = input[index1];
			(index1)++;
		}
		else
		{
			output[k] = input[index2];
			(index2)++;
		}
	}

	// make these changes in input array
	for(int k = i; k <= q; k++)
	{
		input[k] = output[k];
	}
}
