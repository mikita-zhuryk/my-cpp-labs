#include "Pickup.h"

Pickup::Pickup(const Truck& truck, double length, double width, double height): Truck(truck) {
	trunkL_ = length;
	trunkW_ = width;
	trunkH_ = height;
}

Pickup::Pickup(const char* model, int gears, double fuelCons, double tankVol, double maxCargo, int wheels, double length, double width, double height): Truck(model, gears, fuelCons, tankVol, maxCargo, wheels) {
	if ((length <= 0) || (width <= 0) || (height < 0)) {
		throw invalid_argument("Invalid size of trunk in Pickup(lot of params)");
	}
	trunkL_ = length;
	trunkW_ = width;
	trunkH_ = height;
}

Pickup::Pickup(const Pickup& origin): Truck((Truck&)origin) {
	trunkL_ = origin.trunkL_;
	trunkH_ = origin.trunkH_;
	trunkW_ = origin.trunkW_;
}

void Pickup::print(ostream& out) const {
	((Truck)*this).print(out);
	out << "; Pickup's trunk volume equals " << trunkVolume() << "m^3";
}

void Pickup::input(istream& in) {
	in.getline(model_, strL);
}

double Pickup::trunkVolume() const {
	return trunkL_ * trunkW_ * trunkH_;
}
