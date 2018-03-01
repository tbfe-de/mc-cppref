static double vals[5];
static double average;
static int count = 0;

void average_update(double v) {
		double sum = 0.0;
		int n = (count == 5) ? 5 : ++count;
		while (--n > 0)
			sum += (vals[n] = vals[n-1]);
		sum += (vals[0] = v);
		average = sum /count;
}

void average_reset() {
	count = 0;
}

bool average_exists() {
	return (count > 0);
}

double average_getval() {
	return vals[0];
}

double average_getavg() {
	return average;
}
