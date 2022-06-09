#pragma once
#include <iostream>
#include "Bad_length.h"
#include "Bad_range.h"
using namespace std;

class IntegerArray {
public:
	IntegerArray() = default;
	IntegerArray(int length);
	~IntegerArray();

	int& operator[](int index);
	IntegerArray& operator=(const IntegerArray& other);
	IntegerArray& resize(int newLength);
	IntegerArray& insertBefore(int value, int index);
	IntegerArray& deleteVal(int index);
	IntegerArray& insertAtBeginning(int value);
	IntegerArray& insertAtEnd(int value);
	int searchVal(int value);
	int getLength() const;

protected:
	int length_{};
	int* dataPtr_{};	
};


