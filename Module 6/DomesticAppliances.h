#pragma once
class DomesticAppliances : virtual public IElectronics {
public:
	DomesticAppliances(int price, string brand, int powerConsumption);

	void show() override;//

protected:
	string brand_;
	int powerConsumption_;
};

class Refrigerator : public DomesticAppliances {
public:
	Refrigerator(int price, string brand, int powerConsumption, int volume);

	void show() override;//

protected:
	int volume_;
};

class Conditioner : public DomesticAppliances {
public:
	Conditioner(int price, string brand, int powerConsumption, int cooling);

	void show() override;//

protected:
	int cooling_;
};
