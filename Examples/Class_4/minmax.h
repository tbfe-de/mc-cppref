#include "value.h"

class minmax : public value {
public:
	void update(double v);
	double getmin() const;
	double getmax() const;
};
