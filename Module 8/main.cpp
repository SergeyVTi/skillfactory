#include "IntegerArray.h"

#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "");

	cout << endl << "1) Создаем контейнер(10) и выводим на экран" << endl;
	try {
		IntegerArray<int> intArray(10);
		IntegerArray<double> intArray1(10);
		
		cout << intArray << endl;
		cout << intArray1 << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "2) Создаем контейнер размером 0" << endl;
	try {
		IntegerArray<double> intArray(0);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "3) Копируем контейнер1(5) в контейнер2(10)" << endl;
	try {
		IntegerArray<double> intArray1(5);
		IntegerArray<double> intArray2(10);
		intArray2 = intArray1;
		cout << intArray2 << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "4) Копируем контейнер1(10) в контейнер2(5)" << endl;
	try {
		IntegerArray<double> intArray1(10), intArray2(5);
		intArray2 = intArray1;
		cout << intArray2 << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "5) Получаем доступ к элементу контейнера(10) по индексу 9" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << "intArray[9] = " << intArray[9] << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "6) Получаем доступ к элементу контейнера(10) по индексу 10" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << "intArray[10] = " << intArray[10] << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "7) Изменяем размер контейнера(10) на 5" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << intArray << endl;
		cout << intArray.resize(5) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "8) Изменяем размер контейнера(10) на 15" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << intArray << endl;
		cout << intArray.resize(15) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "9) Изменяем размер контейнера(10) на 0" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << intArray << endl;
		cout << intArray.resize(0) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "10) Вставляем элемент 999 в контейнер(10) по индексу 6" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << intArray << endl;
		cout << intArray.insertBefore(999, 6) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "11) Вставляем элемент 999 в контейнер(10) по индексу 15" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << intArray << endl;
		cout << intArray.insertBefore(999, 15) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "12) Удаляем элемент из контейнера(10) по индексу 6" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << intArray << endl;
		cout << intArray.deleteVal(6) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "13) Удаляем элемент из контейнера(10) по индексу 10" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << intArray << endl;
		cout << intArray.deleteVal(10) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "14) Вставляем элемент 999 в начало контейнера(10)" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << intArray << endl;
		cout << intArray.insertAtBeginning(999) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "15) Вставляем элемент 999 в конец контейнера(10)" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << intArray << endl;
		cout << intArray.insertAtEnd(999) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "16) Ищем элемент 5 в контейнере(10)" << endl;
	try {
		IntegerArray<double> intArray(10);
		cout << intArray << endl
			<< "intArray[" << intArray.searchVal(5) << "] = " <<
			intArray[intArray.searchVal(5)] << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}


