#include "minmax.h"

double minmax::getmin() const {
	double min = vals[0];
	for (int i = 1; i < count; ++i)
		if (min > vals[i]) min = vals[i];
	return min;
}

double minmax::getmax() const {
	double max = vals[0];
	for (int i = 1; i < count; ++i)
		if (max < vals[i]) max = vals[i];
	return max;
}
