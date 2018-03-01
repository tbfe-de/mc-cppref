#include "minmax.h"

void update(struct minmax *s, double v) {
	if (s->first) {
		s->min = s->max = v;
		s->first = false;
	}
	else if (s->min > v) s->min = v;
	else if (s->max < v) s->max = v;
}

void reset(struct minmax *s) {
	s->first = true;
}

bool exists(const struct minmax *s) {
	return !s->first;
}

double getval(const struct minmax *s) {
	return s->val;
}

double getmin(const struct minmax *s) {
	return s->min;
}

double getmax(const struct minmax *s) {
	return s->max;
}
