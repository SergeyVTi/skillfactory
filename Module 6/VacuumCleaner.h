#pragma once
class VacuumCleaner : public DomesticAppliances, Mobile {
public:
	VacuumCleaner(int price, string brand, int powerConsumption,
		int powerCapacity, int size);

	void show() override;//

protected:
	int size_;
};
