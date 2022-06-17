#pragma once
#include <iostream>
#include "Bad_length.h"
#include "Bad_range.h"
using namespace std;

template <typename T>
class IntegerArray {
public:
	IntegerArray() = default;
	IntegerArray(int length);
	~IntegerArray();

	T& operator[](int index);
	IntegerArray& operator=(const IntegerArray& other);
	IntegerArray& resize(int newLength);
	IntegerArray& insertBefore(T value, int index);
	IntegerArray& deleteVal(int index);
	IntegerArray& insertAtBeginning(T value);
	IntegerArray& insertAtEnd(T value);
	int searchVal(T value);
	int getLength() const;

	friend ostream& operator<<(ostream& s, IntegerArray<T>& arr) {
		s.put('[');
		char comma[3] = { '\0', ' ', '\0' };
		for (int i = 0; i < arr.getLength(); i++) {
			s << comma << arr[i];
			comma[0] = ',';
		}
		return s << ']';
	}

protected:
	int length_{};
	T* dataPtr_{};
};

