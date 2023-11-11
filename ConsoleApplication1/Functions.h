#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cmath>

using namespace std;

namespace functions
{

	// Вспомогательные функции
	// Генератор случайных целых чисел
	int randInt(int start, int end) 
	{
		return start + rand() % (end - start + 1);
	};
	// Генератор случайных чисел с плавающей точкой
	template<class Type>
	Type Rand(int start, int end, int accuracy=0)
	{
		if (accuracy != 0)
			return (double)randInt(start, end - 1) + double(randInt(0, accuracy - 1)) / pow(10, accuracy);
		else
			return randInt(start, end);
	}
	// Сравнение по умолчанию
	template<class Type>
	bool DefaultCompare(Type a, Type b)
	{
		return a > b;
	}

	// Задание 1. Заполнение случайными значениями
	template<class Type>
	void RandArray(Type arr[], int length, int start, int end, int accuracy=0)
	{
		for (int i = 0; i < length; i++)
			arr[i] = Rand<Type>(start, end, accuracy);
	}

	// Задание 2. Вычисление суммы/произведения элементов
	// Для суммы
	template<class Type>
	Type Summa(Type arr[], int length, int start, int end)
	{
		Type summa = 0;
		for (int i = start; i <= end; i++)
			summa += arr[i];
		return summa;
	}

	// Для произведения
	template<class Type>
	Type Product(Type arr[], int length, int start, int end)
	{
		Type prod = 1;
		for (int i = start; i <= end; i++)
			prod *= arr[i];
		return prod;
	}

	// Задание 3. Вставка и удаление элементов
	// Сдвиг влево
	template<class Type>
	void Left(Type arr[], int length, int k) 
	{
		for (int i = k; i < length - 1; i++)
			arr[i] = arr[i + 1];
		arr[length - 1] = 0;
	}
	// Сдвиг вправо
	template<class Type>
	void Right(Type arr[], int length, int k) 
	{
		for (int i = length - 2; i <= k; i--)
			arr[i + 1] = arr[i];
		arr[k] = 0;
	}

	// Вставка
	template<class Type>
	void Insert(Type arr[], int length, int k, int n)
	{
		Right(arr, length - 1, k);
		arr[k] = n;
	}
	template<class Type>
	void DeleteElem(Type arr[], int n, int k) {
		if (k < 0 || k >= n) {
			std::cout << "Invalid index!" << std::endl;
			return;
		}

		for (int i = k; i < n - 1; i++) {
			arr[i] = arr[i + 1];
		}
	}
	// Удаление
	template<class Type>
	void RemoveElems(Type arr[], int length, int start, int end)
	{
		for (int i = start; i <= end--; i++)
			DeleteElem(arr, length--, i--);
	}

	// Задание 4. Сортировка массива
	// Соритровка выбором
	template<class Type>
	void SelectionSort(Type arr[], int n, bool (*compare)(Type, Type) = DefaultCompare)
	{
		int j = 0;
		Type var = 0;
		for (int i = 0; i < n; i++) {
			j = i;
			for (int k = i; k < n; k++) {
				if (compare(arr[j], arr[k])) {
					j = k;
				}
			}
			var = arr[i];
			arr[i] = arr[j];
			arr[j] = var;
		}
	}
	// Пузырьковая сортировка
	template<class Type>
	void BubbleSort(Type arr[], int n, bool (*compare)(Type, Type) = DefaultCompare)
	{
		Type var = 0;
		for (int i = 0; i < n; i++) {
			for (int j = (n - 1); j >= (i + 1); j--) {
				if (compare(arr[j-1], arr[j])) {
					var = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = var;
				}
			}
		}
	}
	// Сортировка вставками
	template<class Type>
	void InsertionSort(Type arr[], int n, bool (*compare)(Type, Type) = DefaultCompare)
	{
		Type var = 0;
		int i = 0;
		for (int j = 1; j < n; j++) {
			var = arr[j];
			i = j - 1;
			while (i >= 0 && arr[i] > var) {
				arr[i + 1] = arr[i];
				i = i - 1;
				arr[i + 1] = var;
			}
		}
	}

	// Задание 5. Мин/Макс
	// Мин
	template<class Type>
	int Min(Type arr[], int n)
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
			if (arr[i] < arr[idx])
				idx = i;
		return idx;
	}
	// Макс
	template<class Type>
	int Max(Type arr[], int n)
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
			if (arr[i] > arr[idx])
				idx = i;
		return idx;
	}

	// Задание 6.Бинарный поиск
	template<class Type>
	int BinSearch(Type arr[], int start, int end, int elem)
	{
		int s = start, e = end, m = (s + e) / 2;
		while (s < e) {
			if (arr[m] == elem)
				return m;
			if (arr[m] > elem)
				e = m;
			if (arr[m] < elem)
				s = m;
		}
		return -1;
	}
	// Задание 6. Линейый поиск
	template<class Type>
	int LinSearch(Type arr[], int start, int end, Type elem)
	{
		for (int i = start; start <= end; i++) {
			if (arr[i] == elem)
				return i;
		}
		return -1;
	}
	// Задание 7. Подсчёт элементов
	// Предикаты
	template<class Type>
	bool plus(Type n) { return n > 0; }
	template<class Type>
	bool minus(Type n) { return n < 0; }
	template<class Type>
	bool null(Type n) { return n == 0; }
	template<class Type>
	bool krat_m(Type n, Type m) { return n % m == 0; }
	// Функции, использующие предикаты
	template<class Type>
	int counter_n(Type arr[], int n, bool pred(Type n)) {
		int c = 0;
		for (int i = 0; i < n; i++)
			if (pred(arr[i]))
				c++;
		return c;
	}
	int counter_nm(int arr[], int n, int m, bool pred(int n, int m)) {
		int c = 0;
		for (int i = 0; i < n; i++)
			if (pred(arr[i], m))
				c++;
		return c;
	}
	// Основные функции с использованием предикатов
	// Положительные
	template<class Type>
	Type count_pos(Type arr[], int n) { return counter_n(arr, n, plus); }
	// Отрицательные
	template<class Type>
	Type count_neg(Type arr[], int n) { return counter_n(arr, n, minus); }
	// Нулевые
	template<class Type>
	Type count_null(Type arr[], int n) { return counter_n(arr, n, null); }
	// Кратные M
	int count_krat_m(int arr[], int n, int m) { return counter_nm(arr, n, m, krat_m); }

	// Задание 8. Ввод/Вывод
	// Консольный ввод
	template<class Type>
	void CIn(Type arr[], int length)
	{
		for (int i = 0; i < length; i++)
			cin >> arr[i];
	}
	// Консольный вывод
	template<class Type>
	void COut(Type arr[], int length)
	{
		for (int i = 0; i < length; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	// Файловый ввод TXT
	template<class Type>
	void FInTXT(Type arr[], int length, string fileName)
	{
		ifstream fin(fileName);
		if (fin.eof()) fin.clear();
		for (int i = 0; fin.is_open() && i < length; i++)
		{
			string str;
			getline(fin, str);
			arr[i] = stoi(str);
		}
	}
	// Файловый вывод TXT
	template<class Type>
	void FOutTXT(Type arr[], int length, const char* fileName)
	{
		ofstream fout(fileName);
		for (int i = 0; i < length; i++)
		{
			fout << to_string(arr[i]) + "\n";
		}
	}

	// Файловый ввод BIN
	template<class Type>
	void FInBIN(Type arr[], int length, string fileName)
	{
		ifstream fin(fileName, ios_base::in | ios_base::binary);
		for (int i = 0; i < length; i++)
			fin.read((char*)&arr[i], sizeof arr[i]);
	}

	// Файловый вывод BIN
	template<class Type>
	void FOutBIN(Type arr[], int length, string fileName)
	{
		ofstream fout(fileName, ios_base::out | ios_base::binary | ios_base::trunc);
		for (int i = 0; i < length; i++)
			fout.write((char*)&arr[i], sizeof arr[i]);
	}

	// Адаптация функций к решению варианта 6
	// Ex A
	// Сравнение по умолчанию (Описан ранее)
	//template<class Type>
	//bool DefaultCompare(Type a, Type b)
	//{
	//	return a > b;
	//}
	// Нахождение максимума
	template<class Type>
	int Max(Type arr[], int n, bool (*compare)(Type, Type) = DefaultCompare)
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
			if (compare(arr[i], arr[idx]))
				idx = i;
		return idx;
	}
}
#endif // !FUNCTIONS