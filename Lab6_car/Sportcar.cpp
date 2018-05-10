#include "Sportcar.h"
#pragma warning(disable: 4996)

Sportcar::Sportcar(const char* model, int gears, double fuelConsumption, double tankVolume, double maxSpeed)
{
	if ((gears < 1) || (fuelConsumption <= 0) || (tankVolume <= 0)) {
		throw invalid_argument("Invalid argument in Sportcar()");
	}
	if (maxSpeed < 200) {
		throw invalid_argument("This is Nissan Leaf, not a sportcar");
	}
	strL = strlen(model);
	model_ = new char[strL + 1];
	model_[strL] = '\0';
	strcpy(model_, model);
	gears_ = gears;
	fuelConsumption_ = fuelConsumption;
	tankVolume_ = tankVolume;
	maxSpeed_ = maxSpeed;
}

Sportcar::Sportcar(const Sportcar& origin) {
	strL = strlen(origin.model_);
	model_ = new char[strL + 1];
	model_[strL] = '\0';
	strcpy(model_, origin.model_);
	gears_ = origin.gears_;
	fuelConsumption_ = origin.fuelConsumption_;
	tankVolume_ = origin.tankVolume_;
	maxSpeed_ = origin.maxSpeed_;
}

Sportcar::~Sportcar() {
}

void Sportcar::print(ostream& out) const {
	out << model_ << "; Max speed equals " << maxSpeed_ << "km/h; Gearbox has " << gears_ << " gears; Fuel consumption equals " << fuelConsumption_ << " litres per 100 km; Tank volume equals " << tankVolume_ << "litres";
}

void Sportcar::input(istream& in) {
	in.getline(model_, strL);
}
