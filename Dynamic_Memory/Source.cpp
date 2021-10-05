#include<iostream>
using std::cin;
using std::cout;
using std::endl;

template<typename T>T** allocate(const unsigned int rows, const unsigned int cols);
template<typename T>void clear(T** arr, const unsigned int rows);

void FillRand(char arr[], const unsigned int n);
void FillRand(int arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const unsigned int n, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const unsigned int rows, const unsigned int cols);
void FillRand(int** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const unsigned int rows, const unsigned int cols, int minRand = 0, int maxRand = 100);
template<typename T>void Print(T arr[], const unsigned int n);
template<typename T>void Print(T** arr, const unsigned int rows, const unsigned int cols);

template<typename T>T* push_back(T arr[], int& n, T value);
template<typename T>T* push_front(T arr[], int& n, T value);
template<typename T>T* push_insert(T arr[], int& n, T value, int index);
template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T* pop_front(T arr[], int& n);
template<typename T>T* erase(T arr[], int& n, int index);

template<typename T>T** push_row_back(T** arr, unsigned int& rows, unsigned int cols);
template<typename T>T** push_row_front(T** arr, unsigned int& rows, unsigned int cols);
template<typename T>T** push_row_insert(T** arr, unsigned int& rows, unsigned int cols, unsigned int index);
template<typename T>T** pop_row_back(T** arr, unsigned int& rows, unsigned int cols);
template<typename T>T** pop_row_front(T** arr, unsigned int& rows, unsigned int cols);
template<typename T>T** pop_row_erase(T** arr, unsigned int& rows, unsigned int cols, unsigned int index);

template<typename T>void push_col_back(T** arr, unsigned int rows, unsigned int& cols);
template<typename T>void push_col_front(T** arr, unsigned int rows, unsigned int& cols);
template<typename T>T** push_col_insert(T** arr, unsigned int rows, unsigned int& cols, unsigned int number_col);
template<typename T>void pop_col_back(T** arr, unsigned int rows, unsigned int& cols);
template<typename T>void pop_col_front(T** arr, unsigned int rows, unsigned int& cols);
template<typename T>T** pop_col_erase(T** arr, unsigned int rows, unsigned int& cols, unsigned int number_col);


#define DATA_TYPE char
typedef char DataType;
//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	char* arr = new char[n];
	FillRand(arr, n);
	Print(arr, n);
	char value;
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
#ifdef DYNAMIC_MEMORY_2
	unsigned int rows;
	unsigned int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	DataType** arr = allocate<DataType>(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "ДДМ с добавленной в конец строкой: " << endl;
	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols);//заполняем значениями только новую добавленную строку
	Print(arr, rows, cols);

	cout << "ДДМ с добавленной в начало строкой: " << endl;
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols);//заполняем значениями только новую добавленную строку
	Print(arr, rows, cols);

	unsigned int index;
	cout << "Введите значение индекса для добавления строки: " << endl; cin >> index;
	cout << "ДДМ с добавленной по индексу строкой: " << endl;
	arr = push_row_insert(arr, rows, cols, index);
	if (index <= rows)FillRand(arr[index], cols);//заполняем значениями только новую добавленную строку
	Print(arr, rows, cols);

	cout << "ДДМ с удаленной последней строкой: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "ДДМ с удаленной первой строкой: " << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите значение индекса для удаления строки: " << endl; cin >> index;
	cout << "ДДМ с удаленной по индексу строкой: " << endl;
	arr = pop_row_erase(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Двумерный массив с добавленным в конце столбцом: " << endl;
	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++) arr[i][cols - 1] = rand() % 100;
	Print(arr, rows, cols);

	cout << "Двумерный массив с добавленным в начале столбцом: " << endl;
	push_col_front(arr, rows, cols);
	for (int i = 0; i < rows; i++) arr[i][0] = rand() % 100;
	Print(arr, rows, cols);

	int number_col;
	cout << "Введите номер добавляемого столбца: " << endl; cin >> number_col;
	cout << "Двумерный массив с добавленным в начале столбцом: " << endl;
	push_col_insert(arr, rows, cols, number_col);
	for (int i = 0; i < rows; i++) arr[i][number_col] = rand() % 100;
	Print(arr, rows, cols);

	cout << "Двумерный массив с удаленным последним столбцом: " << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Двумерный массив с удаленным первым столбцом: " << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите номер удаляемого столбца: " << endl; cin >> number_col;
	cout << "Двумерный массив с удаленным по номеру столбцом: " << endl;
	pop_col_erase(arr, rows, cols, number_col);
	Print(arr, rows, cols);

	clear(arr, rows);
#endif // DEBUG

}
template<typename T>
T** allocate(const unsigned int rows, const unsigned int cols)
{
	//Объявление двумерного динамического массива:
		//1) Объявляем указатель на указатель и сохрнаяем в него адрес массива указателей

	T** arr = new T * [rows];
	//2) Создаем строки ДДМ:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{};
	}
	return arr;
}
template<typename T>
void clear(T** arr, const unsigned int rows)
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
void FillRand(char arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}

}
void FillRand(int arr[], const unsigned int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
	}

}
void FillRand(double arr[], const unsigned int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
	}

}

void FillRand(char** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
void FillRand(int** arr, const unsigned int rows, const unsigned int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void FillRand(double** arr, const unsigned int rows, const unsigned int cols, int minRand, int maxRand)
{

	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
			arr[i][j] /= 100;
		}
	}
}

template<typename T>void Print(T arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";

	}
	cout << endl;
}
template<typename T>void Print(T** arr, const unsigned int rows, const unsigned int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *(*(arr + i) + j) << "\t";
		}
		cout << endl;
	}
}
template<typename T>T* push_back(T arr[], int& n, T value)
{
	//добавление элемента в массив
	//1)создаем буферный массив нужного размера
	T* buffer = new T[n + 1];
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
template<typename T>T* push_front(T arr[], int& n, T value)
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
template<typename T>T* push_insert(T arr[], int& n, T value, int index)
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
template<typename T>T* pop_back(T arr[], int& n)
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
template<typename T>T* pop_front(T arr[], int& n)
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
template<typename T>T* erase(T arr[], int& n, int index)
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
template<typename T>T** push_row_back(T** arr, unsigned int& rows, unsigned int cols)
{
	//1)создаем буферный массив указателей
	T** buffer = new T * [rows + 1]{};
	//2) копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[rows] = new T[cols]{};
	rows++;
	return arr;
}
template<typename T>T** push_row_front(T** arr, unsigned int& rows, unsigned int cols)
{
	//1)создаем буферный массив указателей
	T** buffer = new T * [rows + 1]{};
	//2) копируем адреса строк в буферный массив указателей
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = new T[cols]{};
	rows++;
	return arr;
}
template<typename T>T** push_row_insert(T** arr, unsigned int& rows, unsigned int cols, unsigned int index)
{
	if (index > (rows - 1)) return arr;
	T** buffer = new T * [rows + 1]{};
	for (int i = 0, k = 0; i < rows; i++, k++)
	{
		if (i == index)k++;
		buffer[k] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = new T[cols]{};
	rows++;
	return arr;
}
template<typename T>T** pop_row_back(T** arr, unsigned int& rows, unsigned int cols)
{
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[rows];
	delete[] arr;
	arr = buffer;
	return arr;
}
template<typename T>T** pop_row_front(T** arr, unsigned int& rows, unsigned int cols)
{
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[]arr[0];
	delete[] arr;
	arr = buffer;
	return arr;
}
template<typename T>T** pop_row_erase(T** arr, unsigned int& rows, unsigned int cols, unsigned int index)
{
	if (index > (rows - 1)) return arr;
	T** buffer = new T * [--rows];
	for (int i = 0, k = 0; i < rows; i++)
	{
		if (i == index) k++;
		buffer[i] = arr[i + k];
	}
	delete[] arr[index];
	delete[]arr;
	arr = buffer;
	return arr;
}

template<typename T>void push_col_back(T** arr, unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1)создаем буферную строку размером на 1 элемент больше
		T* buffer = new T[cols + 1]{};
		//2)копируем исходную строку в буферную
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];

		}
		//3)удаляем исходную строку
		delete[] arr[i];
		arr[i] = buffer;

	}
	//4) после того, как в каждой строке добавилось по элементу кол-во столбцов увеличилось на 1
	cols++;
}
template<typename T>void push_col_front(T** arr, unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}
template<typename T>T** push_col_insert(T** arr, unsigned int rows, unsigned int& cols, unsigned int number_col)
{
	for (int i = 0; i < rows; i++)
	{
		if (number_col > cols) return arr;
		T* buffer = new T[cols + 1]{};
		for (int j = 0, k = 0; j < cols; j++, k++)
		{
			if (j == number_col)k++;
			buffer[k] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;

	}
	cols++;
	return arr;
}
template<typename T>void pop_col_back(T** arr, unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;

}
template<typename T>void pop_col_front(T** arr, unsigned int rows, unsigned int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;

	}
	cols--;
}
template<typename T>T** pop_col_erase(T** arr, unsigned int rows, unsigned int& cols, unsigned int number_col)
{
	if (number_col > cols - 1) return arr;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0, k = 0; j < cols - 1; j++)
		{
			if (j == number_col)k++;
			buffer[j] = arr[i][j + k];
		}
		delete[] arr[i];
		arr[i] = buffer;

	}
	cols--;
	return arr;
}


