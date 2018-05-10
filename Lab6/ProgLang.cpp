#include "ProgLang.h"

ProgLang::ProgLang(const char* name, bool dynamicTypization, int typizationStrength, bool objectOriented, int cameOut) {
	int length = strlen(name);
	name_ = new char[length + 1];
	name_[length] = '\0';
	strcpy_s(name_, length, name);
	dynamicTypization_ = dynamicTypization;
	typizationStrength_ = typizationStrength;
	objectOriented_ = objectOriented;
	cameOut_ = cameOut;
}
