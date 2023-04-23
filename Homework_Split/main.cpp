#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");

	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	int count_even = 0;
	int count_odd = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) count_even++;
		else count_odd++;
	}

	int* arr_even = new int[count_even];
	int* arr_odd = new int[count_odd];

	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) arr_even[j++] = arr[i];
		else arr_odd[k++] = arr[i];
	}

	Print(arr_even, count_even);
	Print(arr_odd, count_odd);

	delete[] arr_even;
	delete[] arr_odd;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}