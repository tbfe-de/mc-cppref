#include "value.h"

class minmax : public value {
	double min;
	double max;
public:
	void update(double v);
	double getmin() const;
	double getmax() const;
};
