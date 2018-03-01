#include "average.h"

void update(struct average *s, double v) {
		double sum = 0.0;
		int n = (s->count == 5) ? 5 : ++s->count;
		while (--n > 0)
			sum += (s->vals[n] = s->vals[n-1]);
		sum += (s->vals[0] = v);
		s->average = sum / s->count;
}

void reset(struct average *s) {
	s->count = 0;
}

bool exists(const struct average *s) {
	return (s->count > 0);
}

double getval(const struct average *s) {
	return s->vals[0];
}

double getavg(const struct average *s) {
	return s->average;
}
