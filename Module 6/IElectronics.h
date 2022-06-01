#pragma once

class IElectronics {
public:
	IElectronics(int price) : price_(price) {
	}
	virtual ~IElectronics() = default;
	virtual void show() = 0;
protected:
	int price_;
};