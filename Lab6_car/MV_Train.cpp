#include "MV_Train.h"

MV_Train::MV_Train(const Truck& truckOr, bool hasRefridgerator): Truck(truckOr) {
	hasRefridgerator_ = hasRefridgerator;
}

MV_Train::MV_Train(const char* model, int gears, double fuelConsumption, double tankVolume, double maxCargoLoad, int numberOfWheels, bool hasRefridgerator): Truck(model, gears, fuelConsumption, tankVolume, maxCargoLoad, numberOfWheels) {
	hasRefridgerator_ = hasRefridgerator;
}

void MV_Train::print(ostream& out) const {
	((Truck)*this).print(out);
	out << "; " << ((hasRefridgerator_) ? (" Has") : (" Has no")) << " refridgerator";
}

void MV_Train::input(istream& in) {
	in.getline(model_, strL);
}
