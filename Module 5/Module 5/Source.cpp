#include "header.h"

Snack::Snack(SnackType type) {
	switch (snackType = type) {
	case(Bounty):
		snackName = "Bounty";
		snackPrice = Price::Bounty;
		snackCals = Cals::Bounty;
		break;

	case(Snickers):
		snackName = "Snickers";
		snackPrice = Price::Snickers;
		snackCals = Cals::Snickers;
		break;

	case(Mars):
		snackName = "Mars";
		snackPrice = Price::Mars;
		snackCals = Cals::Mars;
		break;

	default:
		break;
	}
}

void Snack::createNew() {
	cout << "������� ���: " << endl;
	string str;
	cin >> str;
	setSnackName(str);
}

void Snack::setSnackName(string& value) {
	snackName = value;
}

void Snack::setSnackCals(int& value) {
	snackCals = value;
}

void Snack::setSnackPrice(int& value) {
	snackPrice = value;
}

void Snack::display() const {
	cout << "��� �����: " << snackName << endl
		<< "���������� ������: " << snackNum << endl
		<< "���� �����: " << snackPrice << endl
		<< "���������� �������: " << snackCals << endl;

}

Snack& Snack::operator++() {
	++snackNum;
	return *this;
}

Snack& Snack::operator--() {
	--snackNum;
	return *this;
}

ostream& operator<<(ostream& output, const Snack* s) {
	output << "��� �����: " << s->snackName << endl
		<< "���������� ������: " << s->snackNum << endl
		<< "���� �����: " << s->snackPrice << endl
		<< "���������� �������: " << s->snackCals << endl
		<< endl;
	return output;
}

SnackSlot::SnackSlot(int num) {
	snackSlotNum = num;
}

void SnackSlot::addSnack(SnackType type) {
	for (auto& slotVal : slot) {
		if (slotVal && slotVal->snackType == type && slotVal->snackNum < snackSlotSize) {
			++slotVal->snackNum;
			return;
		}
	}
	Snack* snack = new Snack(type);
	++* snack;
	slot.push_back(snack);
}

void SnackSlot::deleteSnack(SnackType type) {
	for (auto& slotVal : slot) {
		if (slotVal->snackType == type && slotVal->snackNum > 0) {
			--slotVal->snackNum;
			return;
		}
	}
	throw logic_error{ "---------------\n���� �� ������!\n---------------" };
}

void SnackSlot::display() {
	for (const auto& val : slot) {
		val->display();
	}
}

VendingMachine::VendingMachine() {

}

SnackSlot* VendingMachine::getSnackSlot(const int& num) {
	for (auto& val : snackSlot) {
		if (val->snackSlotNum == num && val->activeSlot)
			return val;
	}
	throw logic_error{ "---------------\n����� �� ������!\n---------------" };
}

int VendingMachine::addSlot(unsigned int& num) {

	for (auto& val : snackSlot) {
		if (val->snackSlotNum == num) {
			val->activeSlot = true;
			return num;
		}
	}

	SnackSlot* slot = new SnackSlot(num);
	slot->activeSlot = true;
	snackSlot.push_back(slot);
	return num;
}

void VendingMachine::deleteSlot(unsigned int& num) {

	for (auto& val : snackSlot) {
		if (val->snackSlotNum == num && val->activeSlot) {
			val->activeSlot = false;
			return;
		}
	}
	throw logic_error{ "---------------\n����� �� ������!\n---------------" };
}

void VendingMachine::moveSnack(const Selection& selection) {////////////
	int selectionSlot{};
	int selectionSnack{};

	cout << "�������� �����" << endl
		<< "---> ";
	cin >> selectionSlot;
	cout << "�������� ����" << endl
		<< "1) Bounty" << endl
		<< "2) Snickers" << endl
		<< "3) Mars" << endl
		<< "---> ";
	cin >> selectionSnack;

	switch (selectionSnack) {
	case 1:
		switch (selection) {
		case (Add):
			this->getSnackSlot(selectionSlot)
				->addSnack(Bounty);
			break;
		case (Delete):
			this->getSnackSlot(selectionSlot)
				->deleteSnack(Bounty);
			break;
		}
		break;

	case 2:
		switch (selection) {
		case (Add):
			this->getSnackSlot(selectionSlot)
				->addSnack(Snickers);
			break;
		case (Delete):
			this->getSnackSlot(selectionSlot)
				->deleteSnack(Snickers);
			break;
		}
		break;

	case 3:
		switch (selection) {
		case (Add):
			this->getSnackSlot(selectionSlot)
				->addSnack(Mars);
			break;
		case (Delete):
			this->getSnackSlot(selectionSlot)
				->deleteSnack(Mars);
			break;
		}
		break;

	default:
		cerr << "�������� ����!" << endl;
		break;
	}
}

void VendingMachine::displayMachine() {
	for (auto& val : snackSlot) {
		if (val->activeSlot) {
			cout << "***************************" << endl
				<< "����� " << val->snackSlotNum << endl;
			val->display();
			cout << "***************************" << endl;
		}
	}
}
