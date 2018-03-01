#include <cassert>

#include "average.h"
#include "minmax.h"

void test_average() {
	struct average t;

	assert(t.exists() == false);
	
	t.update(2.0);

	assert(t.exists() == true);
	assert(t.getval() == 2.0);
	assert(t.getavg() == 2.0);

	t.update(4.0);

	assert(t.exists() == true);
	assert(t.getval() == 4.0);
	assert(t.getavg() == 3.0);

	t.update(3.0);

	assert(t.exists() == true);
	assert(t.getval() == 3.0);
	assert(t.getavg() == 3.0);

	t.update(11.0);

	assert(t.exists() == true);
	assert(t.getval() == 11.0);
	assert(t.getavg() == 5.0);

	t.reset();

	assert(t.exists() == false);
}

void test_minmax() {
	struct minmax t;

	assert(t.exists() == false);
	
	t.update(2.0);

	assert(t.exists() == true);
	assert(t.getval() == 2.0);
	assert(t.getmin() == 2.0);
	assert(t.getmax() == 2.0);

	t.update(4.0);

	assert(t.exists() == true);
	assert(t.getval() == 4.0);
	assert(t.getmin() == 2.0);
	assert(t.getmax() == 4.0);

	t.update(3.0);

	assert(t.exists() == true);
	assert(t.getval() == 3.0);
	assert(t.getmin() == 2.0);
	assert(t.getmax() == 4.0);

	t.update(11.0);

	assert(t.exists() == true);
	assert(t.getval() == 11.0);
	assert(t.getmin() == 2.0);
	assert(t.getmax() == 11.0);

	t.reset();

	assert(t.exists() == false);
}

#include <iostream>
int main() {
	std::cout << "ALL TESTS PASSED" << std::endl;
}
