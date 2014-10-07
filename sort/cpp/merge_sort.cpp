#include<iostream>
#include<stdlib.h>

#define Length 100
//#define VERSION_OLD
///The Old Version (Old not means bad!)
#ifdef VERSION_OLD
void Merge(int* arr, int head, int mid, int tail)
{
	//Calc the length of two subarray
	int n1 = mid - head + 1;
	int n2 = tail - mid;
	//Malloc
	int *a = (int*)malloc(sizeof(int)*(n1 + 1));
	int *b = (int*)malloc(sizeof(int)*(n2 + 1));
	//Copy 
	for (int i = 0; i < n1; i++)
	{
		a[i] = arr[head + i];
	}
	for (int i = 0; i < n2; i++)
	{
		b[i] = arr[mid + i + 1];
	}

	//Here is some tricks:Watcher
	a[n1] = INT_MAX;
	b[n2] = INT_MAX;
	//Compare the heads of two Array.
	int i = 0;
	int j = 0;
	for (int k = head; k <= tail; k++)
	{
		if (a[i] <= b[j])
		{
			arr[k] = a[i];
			i++;
		}
		else
		{
			arr[k] = b[j];
			j++;
		}
	}
}
#else
//Question P22  Quiz 2.3-2
//Rewrite the method Merge with no watcher!
void Merge(int* arr, int head, int mid, int tail)
{
	//Calc the length of two subarray
	int n1 = mid - head + 1;
	int n2 = tail - mid;
	//Malloc
	int *a = (int*)malloc(sizeof(int)*(n1));
	int *b = (int*)malloc(sizeof(int)*(n2));
	//Copy 
	for (int i = 0; i < n1; i++)
	{
		a[i] = arr[head + i];
	}
	for (int i = 0; i < n2; i++)
	{
		b[i] = arr[mid + i + 1];
	}

	//Compare the heads of two Array.
	int i = 0;
	int j = 0;
	int k = head;
	while (i < n1 && j < n2)
	{
		if (a[i] <= b[j])
		{
			arr[k] = a[i];
			++i;
		}
		else
		{
			arr[k] = b[j];
			++j;
		}
		++k;
	}
	if (i >= n1)//Means Sub Array2 still have something remain
	{
		while (k <= tail)
		{
			arr[k] = b[j];
			++j;
			++k;
		}
	}
	else
	{
		while (k <= tail)
		{
			arr[k] = a[i];
			++i;
			++k;
		}
	}
}


#endif


void MergeSort(int* arr, int head, int tail)
{
	if (head < tail)
	{
		int mid = (head + tail) / 2;
		MergeSort(arr, head, mid);
		MergeSort(arr, mid + 1, tail);
		Merge(arr, head, mid, tail);
	}
}

int main()
{
	int arr[Length];

	for (size_t i = 0; i < Length; i++)
	{
		std::cin >> arr[i];
	}

	MergeSort(arr, 0, Length - 1);

	for (size_t i = 0; i < Length; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}