#include "minmax.h"

void minmax::update(double v) {
	value::update(v);
	if (count == 1) {
		min = max = v;
	}
	else if (min > v) min = v;
	else if (max < v) max = v;
}

double minmax::getmin() const {
	return min;
}

double minmax::getmax() const {
	return max;
}
