#include "average.h"

void average_update(struct average *s, double v) {
		double sum = 0.0;
		int n = (s->count == 5) ? 5 : ++s->count;
		while (--n > 0)
			sum += (s->vals[n] = s->vals[n-1]);
		sum += (s->vals[0] = v);
		s->average = sum / s->count;
}

void average_reset(struct average *s) {
	s->count = 0;
}

bool average_exists(const struct average *s) {
	return (s->count > 0);
}

double average_getval(const struct average *s) {
	return s->vals[0];
}

double average_getavg(const struct average *s) {
	return s->average;
}
