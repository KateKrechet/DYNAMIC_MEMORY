#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int** allocate(const unsigned int rows, const unsigned int cols);
void clear(int** arr, const unsigned int rows);

void FillRand(int arr[], const unsigned int n, int minRand=0, int maxRand=100);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols);
void Print(int arr[], const unsigned int n);
void Print(int** arr, const unsigned int rows, const unsigned int cols);
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* push_insert(int arr[], int& n, int value, int index);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);

int** push_row_back(int** arr, unsigned int &rows, unsigned int cols);
int** push_row_front(int** arr, unsigned int& rows, unsigned int cols);
int** push_row_insert(int** arr, unsigned int& rows, unsigned int cols,unsigned int index);
int** pop_row_back(int** arr, unsigned int& rows, unsigned int cols);
int** pop_row_front(int** arr, unsigned int& rows, unsigned int cols);
int** pop_row_erase(int** arr, unsigned int& rows, unsigned int cols, unsigned int index);



//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое в конец значение: "; cin >> value;
	arr = push_back(arr, n, value);
	cout << "Массив с добавленным в конце элементом: " << endl;
	Print(arr, n);

	cout << "Введите добавляемое в начало значение: "; cin >> value;
	arr = push_front(arr, n, value);
	cout << "Массив с добавленным в начало элементом: " << endl;
	Print(arr, n);

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс для вставки значения: "; cin >> index;
	arr = push_insert(arr, n, value, index);
	cout << "Массив с добавленным по номеру индекса значением: " << endl;
	Print(arr, n);

	arr = pop_back(arr, n);
	cout << "Массив с удаленным последним элементом массива: " << endl;
	Print(arr, n);

	arr = pop_front(arr, n);
	cout << "Массив с удаленным первым элементом массива: " << endl;
	Print(arr, n);

	cout << "Введите индекс для удаляемого значения: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	delete[]arr;
#endif // DYNAMIC_MEMORY_1
	unsigned int rows;
	unsigned int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	int** arr = allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "ДДМ с добавленной в конец строкой: " << endl;
	arr=push_row_back(arr, rows, cols);
	FillRand(arr[rows-1], cols, 0, 1000);//заполняем значениями только новую добавленную строку
	Print(arr, rows, cols);

	cout << "ДДМ с добавленной в начало строкой: " << endl;
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 0, 1000);//заполняем значениями только новую добавленную строку
	Print(arr, rows, cols);
	
	int index;
	cout << "Введите значение индекса для добавления строки: " << endl; cin >> index;
	cout << "ДДМ с добавленной по индексу строкой: " << endl;
	arr = push_row_insert(arr, rows, cols,index);
	FillRand(arr[index], cols, 0, 1000);//заполняем значениями только новую добавленную строку
	Print(arr, rows, cols);

	cout << "ДДМ с с удаленной последней строкой: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "ДДМ с с удаленной первой строкой: " << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите значение индекса для удаления строки: " << endl; cin >> index;
	cout << "ДДМ с удаленной по индексу строкой: " << endl;
	arr = pop_row_erase(arr, rows, cols, index);
	Print(arr, rows, cols);
	clear(arr, rows);
}

int** allocate(const unsigned int rows, const unsigned int cols)
{
	//Объявление двумерного динамического массива:
		//1) Объявляем указатель на указатель и сохрнаяем в него адрес массива указателей

	int** arr = new int* [rows];
	//2) Создаем строки ДДМ:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}
void clear(int** arr, const unsigned int rows)
{
	//3) Удаление ДДМ
	//Удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete arr[i];
	}
	//Удаляем массив указателей
	delete[] arr;
}
void FillRand(int arr[], const unsigned int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand-minRand)+minRand;
	}

}
void FillRand(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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

void Print(int** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr+i)+j)<< "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[], int& n, int value)
{
	//добавление элемента в массив
	//1)создаем буферный массив нужного размера
	int* buffer = new int[n + 1];
	//копируем исходный массив в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)удалить исходный массив
	delete[] arr;
	//4)подменем исходный массив новым (буферным) массивом, за счет подмены адреса
	arr = buffer;
	//5)Только после всех этих действий можно добавить значние в конец массива
	arr[n] = value;
	//6)После добавления элемента в массив количество его элементов увеличивается на 1
	n++;
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
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
int* push_insert(int arr[], int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	if (index >= n) return arr;
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
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n--;
	return arr;
}
int* pop_front(int arr[], int& n)
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
int* erase(int arr[], int& n, int index)
{
	if (index > (n - 1)) return arr;
	int* buffer = new int[n - 1];
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

int** push_row_back(int** arr, unsigned int &rows, unsigned int cols)
{
	//1)создаем буферный массив указателей
	int** buffer = new int*[rows + 1]{};
	//2) копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new int[cols] {};
	rows++;
	return arr;
}
int** push_row_front(int** arr, unsigned int& rows, unsigned int cols)
{
	//1)создаем буферный массив указателей
	int** buffer = new int* [rows + 1]{};
	//2) копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new int[cols] {};
	rows++;
	return arr;
}
int** push_row_insert(int** arr, unsigned int& rows, unsigned int cols, unsigned int index)
{
	int** buffer = new int* [rows + 1]{};
	if (index >= rows) return arr;
	for (int i = 0, k = 0; i < rows; i++, k++)
	{
		if (i == index)k++;
		buffer[k] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new int[cols] {};
	rows++;
	return arr;
}
int** pop_row_back(int** arr, unsigned int& rows, unsigned int cols)
{
	int** buffer = new int* [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int** pop_row_front(int** arr, unsigned int& rows, unsigned int cols)
{
	int** buffer = new int* [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int** pop_row_erase(int** arr, unsigned int& rows, unsigned int cols, unsigned int index)
{
	if (index > (rows - 1)) return arr;
	int** buffer = new int*[--rows];
	for (int i = 0, k = 0; i < rows; i++)
	{
		if (i == index) k++;
		buffer[i] = arr[i + k];
	}
	delete[]arr;
	arr = buffer;
	return arr;
}