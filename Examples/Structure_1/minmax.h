struct minmax {
	double val;
	double min;
	double max;
	bool first;
};

extern void minmax_update(struct minmax *, double v);
extern void minmax_reset(struct minmax *);
extern bool minmax_exists(const struct minmax *);
extern double minmax_getval(const struct minmax *);
extern double minmax_getmin(const struct minmax *);
extern double minmax_getmax(const struct minmax *);
