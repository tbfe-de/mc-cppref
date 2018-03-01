#include "minmax.h"

void minmax::update(double v) {
	if (this->first) {
		this->min = this->max = v;
		this->first = false;
	}
	else if (this->min > v) this->min = v;
	else if (this->max < v) this->max = v;
}

void minmax::reset() {
	this->first = true;
}

bool minmax::exists() const {
	return !this->first;
}

double minmax::getval() const {
	return this->val;
}

double minmax::getmin() const {
	return this->min;
}

double minmax::getmax() const {
	return this->max;
}
