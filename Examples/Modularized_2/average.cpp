double vals[5];
int count = 0;

void average_update(double v) {
		int n = (count == 5) ? 5 : ++count;
		while (--n > 0)
			vals[n] = vals[n-1];
		vals[0] = v;
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

double average_calculate() {
	double sum = 0.0;
	for (int i = 0; i < count; ++i)
		sum += vals[i];
	return sum / count;
}
