#include "Dynamic_Memory_1D.h"

template<typename T>T* push_back(T arr[], unsigned int& n, T value)
{
	//���������� �������� � ������
	//1)������� �������� ������ ������� �������
	T* buffer = new T[n + 1];
	//�������� �������� ������ � ��������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)������� �������� ������
	delete[] arr;
	//4)�������� �������� ������ ����� (��������) ��������, �� ���� ������� ������
	arr = buffer;
	//5)������ ����� ���� ���� �������� ����� �������� ������� � ����� �������
	arr[n] = value;
	//6)����� ���������� �������� � ������ ���������� ��� ��������� ������������� �� 1
	n++;
	return arr;
}
template<typename T>T* push_front(T arr[], unsigned int& n, T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
template<typename T>T* push_insert(T arr[], unsigned int& n, T value, unsigned int index)
{
	if (index >= n) return arr;
	T* buffer = new T[n + 1];
	for (int i = 0, k = 0; i < n; i++, k++)
	{
		if (i == index)k++;
		buffer[k] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
template<typename T>T* pop_back(T arr[], unsigned int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
template<typename T>T* pop_front(T arr[], unsigned int& n)
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
template<typename T>T* erase(T arr[], unsigned int& n, unsigned int index)
{
	if (index > (n - 1)) return arr;
	T* buffer = new T[n - 1];
	for (int i = 0, k = 0; i < n; i++)
	{
		if (i == index) k++;
		buffer[i] = arr[i + k];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}

