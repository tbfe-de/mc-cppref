class average {
	double vals[5];
	double avg;
	int count;
public:
	average();
	void update(double v);
	void reset();
	bool exists() const;
	double getval() const;
	double getavg() const;
};
