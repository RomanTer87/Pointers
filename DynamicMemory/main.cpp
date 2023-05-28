#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n__________________________\n"


void FillRand(int arr[], int n);
void FillRand(double arr[], int n);
void FillRand(char arr[], int n);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);

template<typename T> void Print(T arr[], int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

template<typename T>T* Push_back(T* arr, int& n, T value);
template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>void push_col_back(T** arr, const int rows, int& cols);

template<typename T> T* Push_front(T* arr, int& n, T value);
template<typename T> T** push_row_front(T** arr, int& rows, const int cols);
template<typename T> void push_col_front(T** arr, const int rows, int& cols);

template<typename T>T* Insert(T* arr, int& n, T value, int index);
template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int index);
template<typename T>void insert_col(T** arr, const int rows, int& cols, const int index);

template<typename T> T* Pop_back(T* arr, int& n);
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T> void pop_cols_back(T** arr, const int rows, int& cols);

template<typename T> T* Pop_front(T* arr, int& n);
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T> void pop_cols_front(T** arr, const int rows, int& cols);

template<typename T>T* Erase(T* arr, int& n, int index);
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index);
template<typename T> void erase_cols(T** arr, const int rows, int& cols, const int index);

template<typename T> T** Allocate(const int rows, const int cols);
template<typename T> void Clear(T** arr, const int rows);

//#define dynamic_memory_1
#define dynamic_memory_2


void main()
{
	setlocale(LC_ALL, "");
	typedef int DataType;

#ifdef dynamic_memory_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	DataType* arr = new DataType[n];
	FillRand(arr, n);
	Print(arr, n);

	DataType value;
	cout << "Введите дополнительное значение для добавления в конец массива: "; cin >> value;
	// Push_back - добавление элемента в конец массива:
	arr = Push_back(arr, n, value);
	Print(arr, n);
	// Push_front - добавление элемента в начало массива:
	cout << "Введите дополнительное значение для добавления в начало массива: "; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);
	// Insert - добавление элемента в массив по заданному индексу:
	int index;
	cout << "Введите значение индекса для добавления в массив: "; cin >> index;
	cout << "Введите дополнительное значение в массив: "; cin >> value;
	arr = Insert(arr, n, value, index);
	Print(arr, n);
	// Pop_back - удаление последнего элемента массива:
	arr = Pop_back(arr, n);
	Print(arr, n);
	// Pop_front - удаление первого элемента массива:
	arr = Pop_front(arr, n);
	Print(arr, n);
	// Erase - удаление выбранного элемента массива:
	cout << "Введите значение индекса для удаления из массива: "; cin >> index;
	arr = Erase(arr, n, index);
	Print(arr, n);
#endif // dynamic_memory_1

#ifdef dynamic_memory_2
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	DataType** arr = Allocate<DataType>(rows,cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "Вывод двумерного динамического массива на экран с помощью арифметики указателей и оператора разыменования: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
	cout << delimiter << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	int index;
	cout << "Введите значение индекса для добавления строки в двумерный массив: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	cout << "Введите значение индекса для удаления строки из массива: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	cout << "Введите значение индекса для добавления столбца в двумерный массив: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	pop_cols_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	pop_cols_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter << endl;
	cout << "Введите значение индекса для удаления строки из двумерного массива: "; cin >> index;
	erase_cols(arr, rows, cols, index);
	Print(arr, rows, cols);
	Clear(arr, rows);
#endif // dynamic_memory_2

}
void FillRand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(double arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10000;
		arr[i] /= 100;
	}
}
void FillRand(char arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr+i) = rand();
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
template<typename T> void Print(T arr[], int n)
{
	for (int i = 0; i < n; i++) cout << arr[i] << "\t";
	cout << endl;
}
template<typename T> void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) cout << arr[i][j] << "\t";
		cout << endl;
	}
}
template<typename T>T* Push_back(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}
template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	return Push_back(arr, rows, new T[cols]{});
}
template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	//1) создаем буферную строку:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = Push_back(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T> T* Push_front(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1];
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
template<typename T> T** push_row_front(T** arr, int& rows, const int cols)
{
	return Push_front(arr, rows, new T[cols]{});
}
template<typename T> void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = Push_front(arr[i], cols, T());
		cols--;
	}
	cols++;
}
template<typename T>T* Insert(T* arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1];
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
template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	return Insert(arr, rows, new T[cols]{}, index);
}
template<typename T>void insert_col(T** arr, const int rows, int& cols, const int index)
{

	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	/*Insert(arr, cols, new T[cols]{}, index);
	cols++;*/
}
template<typename T> T* Pop_back(T* arr, int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>T** pop_row_back(T** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	return Pop_back(arr, rows);
}
template<typename T> void pop_cols_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = Pop_back(arr[i], cols);
		cols++;
	}
	cols--;
}
template<typename T> T* Pop_front(T* arr, int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
	//delete[] arr[0]; - есть ли необходимость удалять из памяти адрес первого массива?
	return Pop_front(arr, rows);
}
template<typename T> void pop_cols_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = Pop_front(arr[i], cols);
		cols++;
	}
	cols--;
}
template<typename T>T* Erase(T* arr, int& n, int index)
{
	T* buffer = new T[n - 1];
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
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	return Erase(arr, rows, index);
}
template<typename T> void erase_cols(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}
template<typename T> T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}
template<typename T> void Clear(T** arr, const int rows)
{
	// 1) Удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	// 2) Удаляем массив указателей
	delete[] arr;
	//arr = nullptr;
}