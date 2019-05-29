// sorts the given array by selections sort
// By Niraj Mahajan IITB, CSE
#include <cstdio>
#include <iostream>

void inser_sort(int input[], int n);

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
	inser_sort(input, n);

	std::cout << "The sorted array is:\n";
	// output
	for(int i = 0; i < n; i++)
	{
		std::cout << input[i] << "  ";
	}
	std::cout << "\n";
}

void inser_sort(int input[], int n)
{
	int target = 0;

	// LI: all terms of index 0, 1, ... head are sorted and are less than all unsorted terms
	// 	   the term of index 'target' is appropriately inserted in the sorted region
	do
	{
		for(int i = 0; i < target; i++)				// all terms of index till target are checked
		{
			if(input[i] >= input[target])			// since they are sorted, the first term found
													// greater than target term is to be swapped, let i
			{										// and the terms of index i, (i+1)...(target - 1) are to be shifted to
													// (i+1), (i+2), ... (target)

				int temp = input[target];			// store the target number

				for(int j = target; j > i; j--)
				{									// swap up the terms
					input[j] = input[j - 1];
				}

				input[i] = temp;					// finally give the ith term the value of target term

				break;
			}
		}
		target++;
	}
	while(target != n);
}