#include "average.h"

double average::getavg() const {
	double sum = 0.0;
	for (int n = 0; n < count; ++n)
		sum += vals[n];
	return sum / count;
}
