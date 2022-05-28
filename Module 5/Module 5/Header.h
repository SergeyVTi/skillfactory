#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

enum SnackType {
	Bounty = 0,
	Snickers,
	Mars
};

namespace Cals {
	enum SnackCals {
		Bounty = 300,
		Snickers = 350,
		Mars = 440
	};
}

namespace Price {
	enum SnackPrice {
		Bounty = 90,
		Snickers = 100,
		Mars = 80
	};
}
enum Selection : int {
	Delete = 0,
	Add
};

class Snack {
public:
	Snack(SnackType type);
	~Snack() = default;

	friend class SnackSlot;
	void createNew();
	void setSnackName(string& value);
	void setSnackCals(int& value);
	void setSnackPrice(int& value);
	void display() const;
	Snack& operator++();
	Snack& operator--();
	friend ostream& operator<<(ostream& output, const Snack* s);

private:
	string snackName{}; //////
	SnackType snackType{};
	unsigned int snackNum{};
	unsigned int snackPrice{};
	unsigned int snackCals{};
};
////////////////////////////////////////
class SnackSlot {
public:
	SnackSlot(int num);
	~SnackSlot() = default;

	friend class VendingMachine;
	void addSnack(SnackType type);
	void deleteSnack(SnackType type);
	void display();

private:
	vector<Snack*> slot{};
	unsigned int snackSlotSize{ 10 };
	unsigned int snackSlotNum{};
	bool activeSlot{ false };
};
////////////////////////////////////////
class VendingMachine {
public:
	VendingMachine();
	~VendingMachine() = default;

	SnackSlot* getSnackSlot(const int& num);
	int addSlot(unsigned int& num);
	void deleteSlot(unsigned int& num);
	void moveSnack(const Selection& selection);
	void deleteSnack();
	void displayMachine();

private:
	vector<SnackSlot*> snackSlot{};
	unsigned int slotNum{ 1 };
};

#pragma once
