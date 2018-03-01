#include "minmax.h"

void minmax_update(struct minmax *s, double v) {
	if (s->first) {
		s->min = s->max = v;
		s->first = false;
	}
	else if (s->min > v) s->min = v;
	else if (s->max < v) s->max = v;
}

void minmax_reset(struct minmax *s) {
	s->first = true;
}

bool minmax_exists(const struct minmax *s) {
	return !s->first;
}

double minmax_getval(const struct minmax *s) {
	return s->val;
}

double minmax_getmin(const struct minmax *s) {
	return s->min;
}

double minmax_getmax(const struct minmax *s) {
	return s->max;
}
