#pragma once
class Mobile : virtual public IElectronics {
public:
	Mobile(int price, int powerCapacity);

	void show() override;//

protected:
	int powerCapacity_;
};

class Phone : public Mobile {
public:
	Phone(int price, int powerCapacity, string color);

	void show() override;//

protected:
	string color_;
};

class LapTop : public Mobile {
public:
	LapTop(int price, int powerCapacity, string cpu);

	void show() override;//

protected:
	string cpu_;
};
