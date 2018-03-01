#include "minmax.h"

void minmax_all::update(double v) {
	value::update(v);
	if (count == 1) {
		min = max = v;
	}
	else if (min > v) min = v;
	else if (max < v) max = v;
}

double minmax_all::getmin() const {
	return min;
}

double minmax_all::getmax() const {
	return max;
}
