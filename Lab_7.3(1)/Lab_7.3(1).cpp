//(Ітераційний спосіб)(1 Завдання)
#include <iostream>
#include <Windows.h>
#include <iomanip>

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High);
void matriz_print(int** matriz, const int line, const int column);
int matriz_sum(int** matriz, const int line, const int column);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	using std::cout;
	using std::endl;

	const int line = 3;
	const int column = 3;

	int** matriz = new int* [line];
	for (int index = 0; index < line; index++)
		matriz[index] = new int[column];

	int High = 97;
	int Low = 16;
	matriz_create(matriz, line, column, Low, High);
	cout << "Сформований масив: " << endl;
	matriz_print(matriz, line, column);

	cout << endl;
	int suma = matriz_sum(matriz, line, column);
	cout << "Сума елементів матриці за вказаним критерієм: " << suma << endl;
	cout << endl;

	delete[] matriz;

	return 0;
}

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High)
{
	using std::cout;
	using std::endl;
	using std::cin;
	for (int index = 0; index < line; index++)
	{
		for (int index_j = 0; index_j < column; index_j++)
		{
			cout << "a[" << index << "][" << index_j << "] = ";
			cin >> matriz[index][index_j];
		}
		cout << endl;
	}
}

void matriz_print(int** matriz, const int line, const int column)
{
	using std::cout;
	using std::endl;
	cout << endl;
	for (int index = 0; index < line; index++)
	{
		for (int index_j = 0; index_j < column; index_j++)
			cout << std::setw(4) << matriz[index][index_j];
		cout << endl;
	}
	cout << endl;
}

int matriz_sum(int** matriz, const int line, const int column)
{
	int sum = 0;
	for (int index = 0; index < line; index++)
	{
		for (int index_jl = 0; index_jl < column; index_jl++)
		{
			if (matriz[index][index_jl] < 0)
			{
				for (int index_j = 0; index_j < column; index_j++)
					sum += matriz[index][index_j];
				index_jl = column;
			}
		}
	}
	return sum;
}
