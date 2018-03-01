#include "average.h"

void average::update(double v) {
		double sum = 0.0;
		int n = (this->count == 5) ? 5 : ++this->count;
		while (--n > 0)
			sum += (this->vals[n] = this->vals[n-1]);
		sum += (this->vals[0] = v);
		this->average = sum / this->count;
}

void average::reset() {
	this->count = 0;
}

bool average::exists() const {
	return (this->count > 0);
}

double average::getval() const {
	return this->vals[0];
}

double average::getavg() const {
	return this->average;
}
