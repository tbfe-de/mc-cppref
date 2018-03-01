#include "average.h"

value::value() {
	reset();
}

void value::update(double v) {
	int n = (count == 5) ? 5 : ++count;
	while (--n > 0)
		vals[n] = vals[n-1];
	vals[0] = v;
}

void value::reset() {
	count = 0;
}

bool value::exists() const {
	return (count > 0);
}

double value::get() const {
	return vals[0];
}
