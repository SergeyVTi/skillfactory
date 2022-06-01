#include "Header.h"

VacuumCleaner::VacuumCleaner(int price, string brand, int powerConsumption,
	int powerCapacity, int size) :
	IElectronics(price),
	DomesticAppliances(price, brand, powerConsumption),
	Mobile(price, powerCapacity),
	size_(size) {
}

void VacuumCleaner::show() {
	cout << "Цена: " << price_ << endl
		<< "Боенд: " << brand_ << endl
		<< "Мощность: " << powerConsumption_ << endl
		<< "Объем батареи: " << powerCapacity_ << endl
		<< "Размер: " << size_ << endl;
}
