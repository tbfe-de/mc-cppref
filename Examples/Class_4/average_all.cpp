#include "average_all.h"

void average_all::reset() {
	sum = 0.0;
	value::reset();
}

double average_all::getavg() const {
	double sum = 0.0;
	for (int n = 0; n < count; ++n)
		sum += vals[n];
	return sum / count;
}
