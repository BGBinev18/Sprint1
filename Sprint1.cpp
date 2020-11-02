#include <iostream>
using namespace std;

//input of array elements
void input(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}
// unification
int merge(int arr1[], int m, int arr2[], int n, int* mergedArray)
{
	int temp, count = 0, index = 0; //count - repetitive elements


	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n - count; j++)
		{
			if (arr1[i] == arr2[j])
			{
				temp = arr2[j];
				arr2[j] = arr2[n - 1 - count];
				arr2[n - 1 - count] = temp;
				count++;
			}
		}
		mergedArray[index++] = arr1[i];
	}
	for (int i = 0; i < n - count; i++)
	{
		mergedArray[index++] = arr2[i];
	}
	return index;
}

// section

int section(int arr1[], int m, int arr2[], int n, int* sectArray)
{
	int index = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr1[i] == arr2[j])
			{
				sectArray[index++] = arr1[i];
			}
		}
	}
	return index;
}

int main()
{
	int length1, length2;
	cin >> length1 >> length2;

	int* arr1 = new int [length1];
	int* arr2 = new int [length2];
	input(arr1, length1);
	input(arr2, length2);


	cout << "Merge: ";
	int* mergedArray = new int[length1 + length2];
	int mergeCount = merge(arr1, length1, arr2, length2, mergedArray);
	for (int i = 0; i < mergeCount; i++)
	{
		cout << mergedArray[i] << " ";
	}

	
         cout << endl << "Section: ";
	int* sectArray = new int[length1];
	int sectCount = section(arr1, length1, arr2, length2, sectArray);
	for (int i = 0; i < sectCount; i++)
	{
		cout << sectArray[i] << " ";
	}
}