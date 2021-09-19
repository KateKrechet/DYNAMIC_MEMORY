﻿#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void FillRand(int arr[], const unsigned int n);
void Print(int arr[], const unsigned int n);
void push_back(int** arr, int& n, int value);//принимаем указатель на массив по указателю
void push_front(int** arr, int& n, int value);
int push_insert(int** arr, int& n, int value, int index);
void pop_back(int** arr, int& n);
void pop_front(int** arr, int& n);
int erase(int** arr, int& n, int index);

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое в конец значение: "; cin >> value;
	push_back(&arr, n, value);
	cout << "Массив с добавленным в конце элементом: " << endl;
	Print(arr, n);

	cout << "Введите добавляемое в начало значение: "; cin >> value;
	push_front(&arr, n, value);
	cout << "Массив с добавленным в начало элементом: " << endl;
	Print(arr, n);

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите значение индекса: "; cin >> index;
	push_insert(&arr, n, value, index);
	cout << "Массив с добавленным по номеру индекса значением: " << endl;
	Print(arr, n);

	pop_back(&arr, n);
	cout << "Массив с удаленным последним элементом массива: " << endl;
	Print(arr, n);

	pop_front(&arr, n);
	cout << "Массив с удаленным первым элементом массива: " << endl;
	Print(arr, n);

	cout << "Введите индекс для удаляемого значения: "; cin >> index;
	erase(&arr, n, index);
	Print(arr, n);

	delete[]arr;
}
void FillRand(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";

	}
	cout << endl;
}
void push_back(int** arr, int& n, int value)
{
	//cout << typeid(arr).name() << endl;
	//добавление элемента в массив
	//1)создаем буферный массив нужного размера
	int* buffer = new int[n + 1];
	//копируем исходный массив в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = (*arr)[i];
	}
	//3)удалить исходный массив
	delete[] * arr;
	//4)подменем исходный массив новым (буферным) массивом, за счет подмены адреса
	*arr = buffer;
	//5)Только после всех этих действий можно добавить значние в конец массива
	(*arr)[n] = value;
	//6)После добавления элемента в массив количество его элементов увеличивается на 1
	n++;

}
void push_front(int** arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = (*arr)[i];
	}
	delete[] * arr;
	*arr = buffer;
	(*arr)[0] = value;
	n++;
}
int push_insert(int** arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	if (index >= n) return **arr;
	for (int i = 0, k = 0; i < n; i++, k++)
	{
		if (i == index)k++;
		buffer[k] = (*arr)[i];
	}
	delete[] * arr;
	*arr = buffer;
	(*arr)[index] = value;
	n++;
	return **arr;
}
void pop_back(int** arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = (*arr)[i];
	delete[] *arr;
	*arr = buffer;

}
void pop_front(int** arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = (*arr)[i+1];
	delete[] * arr;
	*arr = buffer;
}
int erase(int** arr, int& n, int index)
{
	if (index >= n) return **arr;
	int* buffer = new int[--n];
	for (int i = 0, k = 0; i < n; i++)
	{
		if (i == index) k++;
		buffer[i] = (*arr)[i + k];
	}
	delete[]*arr;
	*arr = buffer;
	return **arr;
	
}