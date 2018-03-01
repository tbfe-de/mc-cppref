double val;
double min;
double max;
bool first = true;

void minmax_update() {
	if (first) {
		min = max = val;
		first = false;
	}
	else if (min > val) min = val;
	else if (max < val) max = val;
}

void minmax_reset() {
	first = true;
}
