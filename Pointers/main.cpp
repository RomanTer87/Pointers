//Pointers
#include<iostream>
using namespace std;

//#define POINTERS_BASICS
//#define POINTERS_BASICS_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl; // ����� ���������� 'a' �� �����
	cout << &a << endl; // ������ ������ ���������� 'a' ����� ��� ������.
	cout << pa << endl; // ����� ������ ���������� 'a', ����������� � ��������� 'pa'
	cout << *pa << endl; // ������������� ��������� 'pa' � ����� �� ����� �������� �� ������.  
#endif // POINTERS_BASICS

	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
#ifdef POINTERS_BASICS_2
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";
	}
	cout << endl;
#endif // POINTERS_BASICS_2

	//for (int i = 0; i < n; i++)
	//{
	//	int* pa = &arr[i]; // ���������� ��������� pa ��� ������� �������� �������
	//	pa++;
	//	cout << pa << "\t";  // ������� �� ����� ����� ������� �������� �������, ����������� � ��������� 'pa'
	//}
	//cout << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	
	//	int* pa = &arr[i];
	//	//pa++;
	//	cout << *pa << "\t\t"; // ������������� ��������� 'pa' � ����� �� ����� �������� ������� �������� �������
	//}
	//cout << endl;

	for (int* p_arr = arr; *p_arr != 0xCCCCCCCC; p_arr++)
	{
		cout << *p_arr << "\t";
	}
	cout << endl;
}
