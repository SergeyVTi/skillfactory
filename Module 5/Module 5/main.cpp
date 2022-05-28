#include "header.h"

int displayMenu();

int main() {
	setlocale(LC_ALL, "");

	VendingMachine* vendingMachine = new VendingMachine;

	unsigned int slotNum{};
	bool done{ false };

	while (!done) {
		vendingMachine->displayMachine();
		int selection{ displayMenu() };
		try {
			switch (selection) {
			case 0:
				done = true;
				break;

			case 1:
				cout << "Введите номер лотка" << endl
					<< "---> ";
				cin >> slotNum;
				vendingMachine->addSlot(slotNum);
				break;

			case 2:
				cout << "Введите номер лотка" << endl
					<< "---> ";
				cin >> slotNum;
				vendingMachine->deleteSlot(slotNum);
				break;

			case 3:
				vendingMachine->moveSnack(Add);
				break;

			case 4:
				vendingMachine->moveSnack(Delete);
				break;

			default:
				cerr << "Неизвестная команда" << endl;
				break;
			}
		}
		catch (const exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}

int displayMenu() {
	int selection;
	cout << endl
		<< "VendingMachine" << endl
		<< "-----------------" << endl
		<< "1) Добавить лоток" << endl
		<< "2) Удалить лоток" << endl
		<< "3) Добавить снек" << endl
		<< "4) Удалить снек" << endl
		<< "0) Выход" << endl
		<< endl
		<< "---> ";
	cin >> selection;
	return selection;
}

