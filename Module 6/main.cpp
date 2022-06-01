
#include "header.h"

int displayMenu();

int main() {
	setlocale(LC_ALL, "");

	IElectronics* refrigerator = new Refrigerator(50000, "LG", 1500, 100);
	IElectronics* conditioner = new Conditioner(40000, "DEXP", 2500, 12);
	IElectronics* phone = new Phone(20000, 1000, "�����");
	IElectronics* laptop = new LapTop(100000, 3000, "Intel");
	IElectronics* cleaner = new VacuumCleaner(15000, "Huawei", 500, 1100, 40);

	vector<IElectronics*> electronicsStore;
	electronicsStore.push_back(refrigerator);
	electronicsStore.push_back(conditioner);
	electronicsStore.push_back(phone);
	electronicsStore.push_back(laptop);
	electronicsStore.push_back(cleaner);

	bool done{ false };

	cout << "������� �����������" << endl
		<< "-------------------" << endl;

	while (!done) {

		int selection{ displayMenu() };

		switch (selection) {
		case 0:
			done = true;
			break;

		case 1:
			electronicsStore[0]->show();
			break;

		case 2:
			electronicsStore[1]->show();
			break;

		case 3:
			electronicsStore[2]->show();
			break;

		case 4:
			electronicsStore[3]->show();
			break;

		case 5:
			electronicsStore[4]->show();
			break;

		default:
			cerr << "����������� �������" << endl;
			break;
		}
	}
	for (auto& val : electronicsStore) {
		delete val;
		val = nullptr;
	}
	return 0;
}

int displayMenu() {
	int selection;
	cout << endl
		<< "�������� �����" << endl
		<< "-----------------" << endl
		<< "1) �����������" << endl
		<< "2) �����������" << endl
		<< "3) �������" << endl
		<< "4) �������" << endl
		<< "5) �������" << endl
		<< "0) �����" << endl
		<< endl
		<< "---> ";
	cin >> selection;
	return selection;
}

