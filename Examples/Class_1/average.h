class average {
	double vals[5];
	double average;
	int count;
public:
	void update(double v);
	void reset();
	bool exists() const;
	double getval() const;
	double getavg() const;
};
