#include "IntegerArray.h"

IntegerArray::IntegerArray(int length) : length_(length) {
	cout << "Allocating array" << endl;
	if (length_ <= 0) {
		throw Bad_length();
	}
	dataPtr_ = new int[length_] {};
	cout << "Array allocated" << endl;

	for (int i = 0; i < length_; ++i)
		dataPtr_[i] = i;
}

IntegerArray::~IntegerArray() {
	cout << "Deleting array" << endl;
	delete[] dataPtr_;
	dataPtr_ = nullptr;
	cout << "Array destructed" << endl;
}

int& IntegerArray::operator[](int index) {
	if (index >= 0 && index < length_) {
		return dataPtr_[index];
	}
	throw Bad_range();
}

IntegerArray& IntegerArray::operator=(const IntegerArray& other) {
	if (this == &other)
		return *this;

	if (length_ < other.length_)
		throw Bad_length();

	copy(other.dataPtr_, other.dataPtr_ + other.length_, dataPtr_);
	return *this;
}

IntegerArray& IntegerArray::resize(int newLength) {
	if (newLength == length_)
		return *this;

	if (newLength <= 0)
		throw Bad_length();

	IntegerArray* newData{ new IntegerArray(newLength) };

	int elementsToCopy{ (newLength > length_) ? length_ : newLength };

	copy((*this).dataPtr_, this->dataPtr_ + elementsToCopy, newData->dataPtr_);

	delete[] dataPtr_;
	dataPtr_ = nullptr;
	dataPtr_ = newData->dataPtr_;
	length_ = newLength;
	return *this;
}

IntegerArray& IntegerArray::insertBefore(int value, int index) {
	if (index < 0 || index > length_)
		throw Bad_range();

	IntegerArray* newData{ new IntegerArray(length_ + 1) };

	copy((*this).dataPtr_, this->dataPtr_ + index, newData->dataPtr_);

	*(newData->dataPtr_ + index) = value;

	copy((*this).dataPtr_ + index, this->dataPtr_ + length_, newData->dataPtr_ + index + 1);

	delete[] dataPtr_;
	dataPtr_ = nullptr;
	dataPtr_ = newData->dataPtr_;
	++length_;
	return *this;
}

IntegerArray& IntegerArray::deleteVal(int index) {
	if (index < 0 || index > length_ - 1)
		throw Bad_range();

	if (length_ == 1) {
		this->~IntegerArray();
	}

	IntegerArray* newData{ new IntegerArray(length_ - 1) };

	copy((*this).dataPtr_, this->dataPtr_ + index, newData->dataPtr_);

	copy((*this).dataPtr_ + index + 1, this->dataPtr_ + length_, newData->dataPtr_ + index);

	delete[] dataPtr_;
	dataPtr_ = nullptr;
	dataPtr_ = newData->dataPtr_;
	--length_;
	return *this;
}

IntegerArray& IntegerArray::insertAtBeginning(int value) {
	insertBefore(value, 0);
	return *this;
}

IntegerArray& IntegerArray::insertAtEnd(int value) {
	insertBefore(value, length_);
	return *this;
}

int IntegerArray::searchVal(int value) {
	for (int i = 0; i < length_; ++i)
		if (*(this->dataPtr_ + i) == value)
			return i;
	return -1;
}

int IntegerArray::getLength() const {
	return length_;
}
