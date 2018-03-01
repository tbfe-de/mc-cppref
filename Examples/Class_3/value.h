#ifndef VALUE_H
#define VALUE_H

class value {
protected:
	double vals[5];
	int count;
public:
	value();
	void update(double v);
	void reset();
	bool exists() const;
	double get() const;
};

#endif
