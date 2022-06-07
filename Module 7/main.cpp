

#include "IntegerArray.h"

#include <iostream>
using namespace std;

ostream& operator<<(ostream& s, IntegerArray& arr);

int main() {
	setlocale(LC_ALL, "");

	cout << endl << "1) ������� ���������(10) � ������� �� �����" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << intArray << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "2) ������� ��������� �������� 0" << endl;
	try {
		IntegerArray intArray(0);
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "3) �������� ���������1(5) � ���������2(10)" << endl;
	try {
		IntegerArray intArray1(5), intArray2(10);
		for (int i = 0; i < intArray1.getLength(); ++i)
			intArray1[i] = i + 1;
		intArray2 = intArray1;
		cout << intArray2 << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "4) �������� ���������1(10) � ���������2(5)" << endl;
	try {
		IntegerArray intArray1(10), intArray2(5);
		for (int i = 0; i < intArray1.getLength(); ++i)
			intArray1[i] = i + 1;
		intArray2 = intArray1;
		cout << intArray2 << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "5) �������� ������ � �������� ����������(10) �� ������� 9" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << "intArray[9] = " << intArray[9] << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "6) �������� ������ � �������� ����������(10) �� ������� 10" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << "intArray[10] = " << intArray[10] << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "7) �������� ������ ����������(10) �� 5" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << intArray << endl;
		cout << intArray.resize(5) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "8) �������� ������ ����������(10) �� 15" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << intArray << endl;
		cout << intArray.resize(15) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "9) �������� ������ ����������(10) �� 0" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << intArray << endl;
		cout << intArray.resize(0) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "10) ��������� ������� 999 � ���������(10) �� ������� 6" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << intArray << endl;
		cout << intArray.insertBefore(999, 6) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "11) ��������� ������� 999 � ���������(10) �� ������� 15" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << intArray << endl;
		cout << intArray.insertBefore(999, 15) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "12) ������� ������� �� ����������(10) �� ������� 6" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << intArray << endl;
		cout << intArray.deleteVal(6) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "13) ������� ������� �� ����������(10) �� ������� 10" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << intArray << endl;
		cout << intArray.deleteVal(10) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "14) ��������� ������� 999 � ������ ����������(10)" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << intArray << endl;
		cout << intArray.insertAtBeginning(999) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "15) ��������� ������� 999 � ����� ����������(10)" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << intArray << endl;
		cout << intArray.insertAtEnd(999) << endl;
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	cout << endl << "16) ���� ������� 5 � ����������(10)" << endl;
	try {
		IntegerArray intArray(10);
		for (int i = 0; i < intArray.getLength(); ++i)
			intArray[i] = i + 1;
		cout << intArray << endl
			<< "intArray[" << intArray.searchVal(5) << "] = " <<
			intArray[intArray.searchVal(5)] << endl;		
	}
	catch (const exception& e) {
		cout << e.what() << endl;
	}

	return 0;
}

ostream& operator<<(ostream& s, IntegerArray& arr) {
	s.put('[');
	char comma[3] = { '\0', ' ', '\0' };
	for (int i = 0; i < arr.getLength(); i++) {
		s << comma << arr[i];
		comma[0] = ',';
	}
	return s << ']';
}

