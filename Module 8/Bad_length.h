#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Bad_length : public exception {
public:
	virtual const char* what() const noexcept override;
};


