#include "Header.h"

DomesticAppliances::DomesticAppliances(int price, string brand,
	int powerConsumption) :
	IElectronics(price),
	brand_(brand),
	powerConsumption_(powerConsumption) {
}

void DomesticAppliances::show() {

}

Refrigerator::Refrigerator(int price, string brand, int powerConsumption,
	int volume) :
	IElectronics(price),
	DomesticAppliances(price, brand, powerConsumption),
	volume_(volume) {
}

void Refrigerator::show() {
	cout << "Цена: " << price_ << endl
		<< "Брэнд: " << brand_ << endl
		<< "Мощность: " << powerConsumption_ << endl
		<< "Объем: " << volume_ << endl;
}

Conditioner::Conditioner(int price, string brand, int powerConsumption,
	int cooling) :
	IElectronics(price),
	DomesticAppliances(price, brand, powerConsumption),
	cooling_(cooling) {
}

void Conditioner::show() {
	cout << "Цена: " << price_ << endl
		<< "Брэнд: " << brand_ << endl
		<< "Мощность: " << powerConsumption_ << endl
		<< "Охлаждение: " << cooling_ << endl;
}

