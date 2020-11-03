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
int merge(int firstSet[], int firstLength, int secondSet[], int secondLength, int* mergedArray)
{
int temp, count = 0, index = 0; //count - repetitive elements


for (int i = 0; i < firstLength; i++)
{
for (int j = 0; j < secondLength - count; j++)
{
if (firstSet[i] == secondSet[j])
{
temp = secondSet[j];
secondSet[j] = secondSet[secondLength - 1 - count];
secondSet[secondLength - 1 - count] = temp;
count++;
}
}
mergedArray[index++] = firstSet[i];
}
for (int i = 0; i < secondLength - count; i++)
{
mergedArray[index++] = secondSet[i];
}
return index;
}

// section

int section(int firstSet[], int firstLength, int secondSet[], int secondLength, int* sectArray)
{
int index = 0;
for (int i = 0; i < firstLength; i++)
{
for (int j = 0; j < secondLength; j++)
{
if (firstSet[i] == secondSet[j])
{
sectArray[index++] = firstSet[i];
}
}
}
return index;
}

//difference

int difference(int firstSet[], int firstLength, int secondSet[], int secondLength, int* diffArray)
{
int index = 0;

for (int i = 0; i < firstLength; i++)
{
for (int j = 0; j < secondLength; j++)
{
if (firstSet[i] == secondSet[j])
{

i++;
j = -1;
}
}
if (i < firstLength)
{

diffArray[index++] = firstSet[i];
}

else if (i < secondLength)
{
diffArray[index++] = secondSet[i];
}
}
return index;
}


void displayMerge(int* mergedArray, int mergeCount)
{

cout << "Merge: ";
for (int i = 0; i < mergeCount; i++)
{
cout << mergedArray[i] << " ";
}
}
void displaySection(int* sectArray, int sectCount)
{

cout << endl << "Section: ";
for (int i = 0; i < sectCount; i++)
{
cout << sectArray[i] << " ";
}
}
void displayDifference(int* diffArray, int diffCount)
{

cout << endl << "Difference: ";
for (int i = 0; i < diffCount; i++)
{
cout << diffArray[i] << " ";
}
}
int main()
{
int firstLength, secondLength;
cout<<"Input length for the first set: ";
cin >> firstLength;
cout<<"Input length for the second set: ";
cin >> secondLength;
cout<<endl;

int* firstSet = new int[firstLength];
int* secondSet = new int[secondLength];

cout<<"Input first set: ";
input(firstSet, firstLength);
cout<<endl;
cout<<"Input second set: ";
input(secondSet, secondLength);
cout<<endl;

int* mergedArray = new int[firstLength + secondLength];
int mergeCount = merge(firstSet, firstLength, secondSet, secondLength, mergedArray);
displayMerge(mergedArray, mergeCount);
cout<<endl;
int* sectArray = new int[firstLength];
int sectCount = section(firstSet, firstLength, secondSet, secondLength, sectArray);
displaySection(sectArray, sectCount);
cout<<endl;
int* diffArray = new int[firstLength];
int diffCount = difference(firstSet, firstLength, secondSet, secondLength, diffArray);
displayDifference(diffArray, diffCount);
cout<<endl;
}