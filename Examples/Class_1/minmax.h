class minmax {
	double val;
	double min;
	double max;
	bool first;
public:
	void update(double v);
	void reset();
	bool exists() const;
	double getval() const;
	double getmin() const;
	double getmax() const;
};
