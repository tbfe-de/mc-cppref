struct minmax {
	double val;
	double min;
	double max;
	bool first;
};

extern void update(struct minmax *, double v);
extern void reset(struct minmax *);
extern bool exists(const struct minmax *);
extern double getval(const struct minmax *);
extern double getmin(const struct minmax *);
extern double getmax(const struct minmax *);
