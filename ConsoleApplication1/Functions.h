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
	int randInt(int start, int end) 
	{
		return start + rand() % (end - start + 1);
	};
	template<class Type>
	Type Rand(int start, int end, int accuracy=0)
	{
		if (accuracy != 0)
			return (double)randInt(start, end - 1) + double(randInt(0, accuracy - 1)) / pow(10, accuracy);
		else
			return randInt(start, end);
	}
	template<class Type>
	bool DefaultCompare(Type a, Type b)
	{
		return a > b;
	}
	template<class Type>
	void RandArray(Type arr[], int length, int start, int end, int accuracy=0)
	{
		for (int i = 0; i < length; i++)
			arr[i] = Rand<Type>(start, end, accuracy);
	}
	template<class Type>
	Type Summa(Type arr[], int length, int start, int end)
	{
		Type summa = 0;
		for (int i = start; i <= end; i++)
			summa += arr[i];
		return summa;
	}
	template<class Type>
	Type Product(Type arr[], int length, int start, int end)
	{
		Type prod = 1;
		for (int i = start; i <= end; i++)
			prod *= arr[i];
		return prod;
	}
	template<class Type>
	void Left(Type arr[], int length, int k) 
	{
		for (int i = k; i < length - 1; i++)
			arr[i] = arr[i + 1];
		arr[length - 1] = 0;
	}
	template<class Type>
	void Right(Type arr[], int length, int k) 
	{
		for (int i = length - 2; i <= k; i--)
			arr[i + 1] = arr[i];
		arr[k] = 0;
	}
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
	template<class Type>
	void RemoveElems(Type arr[], int length, int start, int end)
	{
		for (int i = start; i <= end--; i++)
			DeleteElem(arr, length--, i--);
	}
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
	template<class Type>
	int Min(Type arr[], int n)
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
			if (arr[i] < arr[idx])
				idx = i;
		return idx;
	}
	template<class Type>
	int Max(Type arr[], int n)
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
			if (arr[i] > arr[idx])
				idx = i;
		return idx;
	}
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
	template<class Type>
	int LinSearch(Type arr[], int start, int end, Type elem)
	{
		for (int i = start; start <= end; i++) {
			if (arr[i] == elem)
				return i;
		}
		return -1;
	}
	template<class Type>
	bool plus(Type n) { return n > 0; }
	template<class Type>
	bool minus(Type n) { return n < 0; }
	template<class Type>
	bool null(Type n) { return n == 0; }
	template<class Type>
	bool krat_m(Type n, Type m) { return n % m == 0; }
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
	template<class Type>
	Type count_pos(Type arr[], int n) { return counter_n(arr, n, plus); }
	template<class Type>
	Type count_neg(Type arr[], int n) { return counter_n(arr, n, minus); }
	template<class Type>
	Type count_null(Type arr[], int n) { return counter_n(arr, n, null); }
	int count_krat_m(int arr[], int n, int m) { return counter_nm(arr, n, m, krat_m); }
	template<class Type>
	void CIn(Type arr[], int length)
	{
		for (int i = 0; i < length; i++)
			cin >> arr[i];
	}
	template<class Type>
	void COut(Type arr[], int length)
	{
		for (int i = 0; i < length; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
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
	template<class Type>
	void FOutTXT(Type arr[], int length, const char* fileName)
	{
		ofstream fout(fileName);
		for (int i = 0; i < length; i++)
		{
			fout << to_string(arr[i]) + "\n";
		}
	}
	template<class Type>
	void FInBIN(Type arr[], int length, string fileName)
	{
		ifstream fin(fileName, ios_base::in | ios_base::binary);
		for (int i = 0; i < length; i++)
			fin.read((char*)&arr[i], sizeof arr[i]);
	}
	template<class Type>
	void FOutBIN(Type arr[], int length, string fileName)
	{
		ofstream fout(fileName, ios_base::out | ios_base::binary | ios_base::trunc);
		for (int i = 0; i < length; i++)
			fout.write((char*)&arr[i], sizeof arr[i]);
	}

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
