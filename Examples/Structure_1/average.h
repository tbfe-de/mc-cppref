struct average {
	double vals[5];
	double average;
	int count;
};

extern void average_update(struct average *s, double v);
extern void average_reset(struct average *s);
extern bool average_exists(const struct average *s);
extern double average_getval(const struct average *s);
extern double average_getavg(const struct average *s);
