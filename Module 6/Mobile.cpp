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
	cout << "����: " << price_ << endl
		<< "����� �������: " << powerCapacity_ << endl
		<< "����: " << color_ << endl;
}

LapTop::LapTop(int price, int powerCapacity, string cpu) :
	IElectronics(price),
	Mobile(price, powerCapacity),
	cpu_(cpu) {
}

void LapTop::show() {
	cout << "����: " << price_ << endl
		<< "����� �������: " << powerCapacity_ << endl
		<< "���������: " << cpu_ << endl;
}
