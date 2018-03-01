#include "value.h"

class average_all : public value {
	double sum;
public:
	void reset();
	void update(double v);
	double getavg() const;
};
