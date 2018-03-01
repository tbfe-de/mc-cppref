struct average {
	double vals[5];
	double average;
	int count;
};

extern void update(struct average *s, double v);
extern void reset(struct average *s);
extern bool exists(const struct average *s);
extern double getval(const struct average *s);
extern double getavg(const struct average *s);
