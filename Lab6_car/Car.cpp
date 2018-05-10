#include "Car.h"

//Car::Car(const char* model, int gears, double fuelConsumption, double tankVolume) {
//	if ((gears < 1) || (fuelConsumption <= 0) || (tankVolume <=0)) {
//		throw invalid_argument("Invalid argument in Car(const char*, int, double, double)");
//	}
//	strL = strlen(model);
//	model_ = new char[strL + 1];
//	model_[strL] = '\0';
//	strcpy_s(model_, strL, model);
//	gears_ = gears;
//	fuelConsumption_ = fuelConsumption;
//	tankVolume_ = tankVolume;
//}
//
//Car::Car(const Car& origObj) {
//	if ((origObj.gears_ < 1) || (origObj.fuelConsumption_ <= 0) || (origObj.tankVolume_ <= 0)) {
//		throw invalid_argument("Invalid argument in Car(const char*, int, double, double)");
//	}
//	strL = origObj.strL;
//	delete[] model_;
//	model_ = new char[strL];
//	model_[strL] = '\0';
//	strcpy_s(model_, strL, origObj.model_);
//	gears_ = origObj.gears_;
//	fuelConsumption_ = origObj.fuelConsumption_;
//	tankVolume_ = origObj.tankVolume_;
//}

Car::~Car() {
	delete[] model_;
}

double Car::calcMaxDist() {
	return tankVolume_ / fuelConsumption_;
}
