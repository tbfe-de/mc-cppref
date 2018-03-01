static double val;
static double min;
static double max;
static bool first = true;

void minmax_update(double v) {
	if (first) {
		min = max = v;
		first = false;
	}
	else if (min > v) min = v;
	else if (max < v) max = v;
}

void minmax_reset() {
	first = true;
}

bool minmax_exists() {
	return !first;
}

double minmax_getval() {
	return val;
}

double minmax_getmin() {
	return min;
}

double minmax_getmax() {
	return max;
}
