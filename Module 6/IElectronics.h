#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "DomesticAppliances.h"
#include "Mobile.h"
#include "VacuumCleaner.h"

using namespace std;

class IElectronics {
public:
	IElectronics(int price) : price_(price) {
	}
	virtual ~IElectronics() = default;
	virtual void show() = 0;
protected:
	int price_;
};



