#include "minmax.h"

minmax::minmax() {
	reset();
}

void minmax::update(double v) {
	if (first) {
		min = this->max = v;
		first = false;
	}
	else if (min > v) this->min = v;
	else if (max < v) this->max = v;
}

void minmax::reset() {
	first = true;
}

bool minmax::exists() const {
	return !first;
}

double minmax::getval() const {
	return val;
}

double minmax::getmin() const {
	return min;
}

double minmax::getmax() const {
	return max;
}
