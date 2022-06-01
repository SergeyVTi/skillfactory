#include "Header.h"

VacuumCleaner::VacuumCleaner(int price, string brand, int powerConsumption,
	int powerCapacity, int size) :
	IElectronics(price),
	DomesticAppliances(price, brand, powerConsumption),
	Mobile(price, powerCapacity),
	size_(size) {
}

void VacuumCleaner::show() {
	cout << "����: " << price_ << endl
		<< "�����: " << brand_ << endl
		<< "��������: " << powerConsumption_ << endl
		<< "����� �������: " << powerCapacity_ << endl
		<< "������: " << size_ << endl;
}
