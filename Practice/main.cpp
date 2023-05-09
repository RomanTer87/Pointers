#include<iostream>
using namespace std;

void FillRand(int arr[], int n);
void Print(int arr[], int n);
int* Push_back(int* arr, int& n, int value);
int* Push_front(int* arr, int& n, int value);
int* Insert(int* arr, int& n, int value, int index);
int* Pop_back(int* arr, int& n);
int* Pop_front(int* arr, int& n);
int* Erase(int* arr, int& n, int index);

void main()
{
	setlocale(LC_ALL, "");

	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "¬ведите дополнительное значение дл€ добавлени€ в конец массива: "; cin >> value;
	// Push_back - добавление элемента в конец массива:
	arr = Push_back(arr, n, value);
	Print(arr, n);
	// Push_front - добавление элемента в начало массива:
	cout << "¬ведите дополнительное значение дл€ добавлени€ в начало массива: "; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);
	// Insert - добавление элемента в массив по заданному индексу:
	int index;
	cout << "¬ведите значение индекса дл€ добавлени€ в массив: "; cin >> index;
	cout << "¬ведите дополнительное значение в массив: "; cin >> value;
	arr = Insert(arr, n, value, index);
	Print(arr, n);
	// Pop_back - удаление последнего элемента массива:
	arr = Pop_back(arr, n);
	Print(arr, n);
	// Pop_front - удаление первого элемента массива:
	arr = Pop_front(arr, n);
	Print(arr, n);
	// Erase - удаление выбранного элемента массива:
	cout << "¬ведите значение индекса дл€ удалени€ из массива: "; cin >> index;
	arr = Erase(arr, n, index);
	Print(arr, n);
}
void FillRand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* Push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	arr[n] = value;
	n++;
	return arr;
}
int* Push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	buffer[0] = value;
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}
int* Insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* Pop_back(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* Pop_front(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int* Erase(int* arr, int& n, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}