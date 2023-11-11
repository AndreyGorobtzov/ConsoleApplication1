#include "Functions.h"
using namespace functions;
using namespace std;

// A
bool Compare(int a, int b)
{
	return abs(a) > abs(b);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Проверка заполнения массива случайными элементами int:" << endl;
	int arr1[10];
	RandArray(arr1, 10, 0, 10);
	COut(arr1, 10);

	cout << endl << "Проверка заполнения массива случайными элементами double:" << endl;
	double arr2[10];
	RandArray(arr2, 10, 0, 10, 3);
	COut(arr2, 10);

	cout << endl << "Сумма: " << endl;
	cout << Summa(arr2, 10, 0, 9) << endl;

	cout << endl << "Произведение: " << endl;
	cout << Product(arr2, 10, 0, 9) << endl;

	cout << endl << "Удаление: " << endl;
	RemoveElems(arr1, 10, 0, 5);
	COut(arr1, 10);

	cout << endl << "Добавление: " << endl;
	Insert(arr1, 10, 5, 1000);
	COut(arr1, 10);

	cout << endl << "Сортировка выбором: " << endl;
	SelectionSort(arr1, 10);
	COut(arr1, 10);

	cout << endl << "Сортировка пузырьком: " << endl;
	BubbleSort(arr2, 10);
	COut(arr2, 10);

	cout << endl << "Мин arr2: " << endl;
	cout << arr2[Min(arr2, 10)] << endl;

	cout << endl << "Поиск элемента 2.001 в arr2: " << endl;
	cout << BinSearch(arr2, 0, 9, 2.001) << endl;

	cout << endl << "Подсчёт нулевых элементов в arr1: " << endl;
	cout << count_null(arr1, 10) << endl;

	cout << endl << "Тест записи файлов в текстовый файл" << endl;
	FOutTXT(arr1, 10, "NewFile.txt");
	int arrC[10];
	FInTXT(arrC, 10, "NewFile.txt");
	COut(arrC, 10);

	cout << endl << "Вариант 6.\nРабочие данные:" << endl;
	int arr[11] = { -1000,-20000,-3,-2,-1,0,1,2,3,-30000, 0 };
	COut(arr, 11);


	cout << "Задание A" << endl;
	cout << "Индекс максимального по модулю элемента " << Max(arr, 11, Compare) << endl;

	cout << "Задание B" << endl;
	int i01 = LinSearch(arr, 0, 11, 0),
		i02 = LinSearch(arr, i01+1, 11, 0);
	cout << "Произведение элементов между двумя нулевыми " << Product(arr, 11, i01+1, i02-1) << endl;

	cout << "Задание С" << endl;
	RemoveElems(arr, 11, i01, i02);
	cout << "Удаление элементов между двумя нулевыми "  << endl;
	COut(arr, 11);
}

