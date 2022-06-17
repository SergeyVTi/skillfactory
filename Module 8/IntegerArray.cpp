#include "IntegerArray.h"

template <typename T>
IntegerArray<T>::IntegerArray(int length) : length_(length) {
	cout << "Allocating array" << endl;
	if (length_ <= 0) {
		throw Bad_length();
	}
	dataPtr_ = new T[length_] {};
	cout << "Array allocated" << endl;

	for (double i = 0.1; i < length_; ++i)
		dataPtr_[static_cast<int>(i)] = i;
}

template <typename T>
IntegerArray<T>::~IntegerArray() {
	cout << "Deleting array" << endl;
	delete[] dataPtr_;
	dataPtr_ = nullptr;
	cout << "Array destructed" << endl;
}

template <typename T>
T& IntegerArray<T>::operator[](int index) {
	if (index >= 0 && index < length_) {
		return dataPtr_[index];
	}
	throw Bad_range();
}

template <typename T>
IntegerArray<T>& IntegerArray<T>::operator=(const IntegerArray<T>& other) {
	if (this == &other)
		return *this;

	if (length_ < other.length_)
		throw Bad_length();

	copy(other.dataPtr_, other.dataPtr_ + other.length_, dataPtr_);
	return *this;
}

template <typename T>
IntegerArray<T>& IntegerArray<T>::resize(int newLength) {
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

template <typename T>
IntegerArray<T>& IntegerArray<T>::insertBefore(T value, int index) {
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

template <typename T>
IntegerArray<T>& IntegerArray<T>::deleteVal(int index) {
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

template <typename T>
IntegerArray<T>& IntegerArray<T>::insertAtBeginning(T value) {
	insertBefore(value, 0);
	return *this;
}

template <typename T>
IntegerArray<T>& IntegerArray<T>::insertAtEnd(T value) {
	insertBefore(value, length_);
	return *this;
}

template <typename T>
int IntegerArray<T>::searchVal(T value) {
	for (int i = 0; i < length_; ++i)
		if (*(this->dataPtr_ + i) == value)
			return i;
	return -1;
}

template <typename T>
int IntegerArray<T>::getLength() const {
	return length_;
}

template class IntegerArray<int>;
template class IntegerArray<double>;
