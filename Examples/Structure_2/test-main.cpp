#include <cassert>

#include "average.h"
#include "minmax.h"

void test_average() {
	struct average t;
	reset(&t);

	assert(exists(&t) == false);
	
	update(&t, 2.0);

	assert(exists(&t) == true);
	assert(getval(&t) == 2.0);
	assert(getavg(&t) == 2.0);

	update(&t, 4.0);

	assert(exists(&t) == true);
	assert(getval(&t) == 4.0);
	assert(getavg(&t) == 3.0);

	update(&t, 3.0);

	assert(exists(&t) == true);
	assert(getval(&t) == 3.0);
	assert(getavg(&t) == 3.0);

	update(&t, 11.0);

	assert(exists(&t) == true);
	assert(getval(&t) == 11.0);
	assert(getavg(&t) == 5.0);

	reset(&t);

	assert(exists(&t) == false);
}

void test_minmax() {
	struct minmax t;
	reset(&t);

	assert(exists(&t) == false);
	
	update(&t, 2.0);

	assert(exists(&t) == true);
	assert(getval(&t) == 2.0);
	assert(getmin(&t) == 2.0);
	assert(getmax(&t) == 2.0);

	update(&t, 4.0);

	assert(exists(&t) == true);
	assert(getval(&t) == 4.0);
	assert(getmin(&t) == 2.0);
	assert(getmax(&t) == 4.0);

	update(&t, 3.0);

	assert(exists(&t) == true);
	assert(getval(&t) == 3.0);
	assert(getmin(&t) == 2.0);
	assert(getmax(&t) == 4.0);

	update(&t, 11.0);

	assert(exists(&t) == true);
	assert(getval(&t) == 11.0);
	assert(getmin(&t) == 2.0);
	assert(getmax(&t) == 11.0);

	reset(&t);

	assert(exists(&t) == false);
}

#include <iostream>
int main() {
	std::cout << "ALL TESTS PASSED" << std::endl;
}
