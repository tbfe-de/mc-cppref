#include "average.h"

average::average() {
	reset();
}

void average::update(double v) {
		double sum = 0.0;
		int n = (count == 5) ? 5 : ++this->count;
		while (--n > 0)
			sum += (vals[n] = this->vals[n-1]);
		sum += (vals[0] = v);
		avg = sum / this->count;
}

void average::reset() {
	count = 0;
}

bool average::exists() const {
	return (count > 0);
}

double average::getval() const {
	return vals[0];
}

double average::getavg() const {
	return avg;
}
