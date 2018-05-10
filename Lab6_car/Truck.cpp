#include "Truck.h"
#pragma warning(disable: 4996)

Truck::Truck(const char* model, int gears, double fuelConsumption, double tankVolume, double maxCargoLoad, int numberOfWheels) {
	if ((gears < 1) || (fuelConsumption <= 0) || (tankVolume <= 0) || (maxCargoLoad < 0) || (numberOfWheels < 3)) {
		throw invalid_argument("Invalid argument in Truck(const char*, int, double, double, double, int)");
	}
	strL = strlen(model);
	model_ = new char[strL + 1];
	model_[strL] = '\0';
	strcpy(model_, model);
	gears_ = gears;
	fuelConsumption_ = fuelConsumption;
	tankVolume_ = tankVolume;
	maxCargoLoad_ = maxCargoLoad;
	numberOfWheels_ = numberOfWheels;
}

Truck::Truck(const Truck& origin) {
	strL = origin.strL;
	model_ = new char[strL + 1];
	model_[strL] = '\0';
	strcpy(model_, origin.model_);
	gears_ = origin.gears_;
	fuelConsumption_ = origin.fuelConsumption_;
	tankVolume_ = origin.tankVolume_;
	maxCargoLoad_ = origin.maxCargoLoad_;
	numberOfWheels_ = origin.numberOfWheels_;
}

Truck::~Truck() {
}


void Truck::print(ostream& out) const {
	out << model_  << " has " << numberOfWheels_ << " wheels; Gearbox has " << gears_ << " gears; Fuel consumption equals " << fuelConsumption_ << " litres per 100 km; Tank volume equals " << tankVolume_ << "litres";
	out << "; Truck can move maximum of " << maxCargoLoad_ << "kg";
}

void Truck::input(istream& in) {
	in.getline(model_, strL);
}
