#include "Header.h"

Mobile::Mobile(int price, int powerCapacity) :
	IElectronics(price),
	powerCapacity_(powerCapacity) {
}

void Mobile::show() {
}

Phone::Phone(int price, int powerCapacity, string color) :
	IElectronics(price),
	Mobile(price, powerCapacity), color_(color) {
}

void Phone::show() {
	cout << "Цена: " << price_ << endl
		<< "Объем батареи: " << powerCapacity_ << endl
		<< "Цвет: " << color_ << endl;
}

LapTop::LapTop(int price, int powerCapacity, string cpu) :
	IElectronics(price),
	Mobile(price, powerCapacity),
	cpu_(cpu) {
}

void LapTop::show() {
	cout << "Цена: " << price_ << endl
		<< "Объем батареи: " << powerCapacity_ << endl
		<< "Процессор: " << cpu_ << endl;
}
