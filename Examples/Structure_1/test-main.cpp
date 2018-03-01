#include <cassert>

#include "average.h"
#include "minmax.h"

void test_average() {
	struct average t;
	average_reset(&t);

	assert(average_exists(&t) == false);
	
	average_update(&t, 2.0);

	assert(average_exists(&t) == true);
	assert(average_getval(&t) == 2.0);
	assert(average_getavg(&t) == 2.0);

	average_update(&t, 4.0);

	assert(average_exists(&t) == true);
	assert(average_getval(&t) == 4.0);
	assert(average_getavg(&t) == 3.0);

	average_update(&t, 3.0);

	assert(average_exists(&t) == true);
	assert(average_getval(&t) == 3.0);
	assert(average_getavg(&t) == 3.0);

	average_update(&t, 11.0);

	assert(average_exists(&t) == true);
	assert(average_getval(&t) == 11.0);
	assert(average_getavg(&t) == 5.0);

	average_reset(&t);

	assert(average_exists(&t) == false);
}

void test_minmax() {
	struct minmax t;
	minmax_reset(&t);

	assert(minmax_exists(&t) == false);
	
	minmax_update(&t, 2.0);

	assert(minmax_exists(&t) == true);
	assert(minmax_getval(&t) == 2.0);
	assert(minmax_getmin(&t) == 2.0);
	assert(minmax_getmax(&t) == 2.0);

	minmax_update(&t, 4.0);

	assert(minmax_exists(&t) == true);
	assert(minmax_getval(&t) == 4.0);
	assert(minmax_getmin(&t) == 2.0);
	assert(minmax_getmax(&t) == 4.0);

	minmax_update(&t, 3.0);

	assert(minmax_exists(&t) == true);
	assert(minmax_getval(&t) == 3.0);
	assert(minmax_getmin(&t) == 2.0);
	assert(minmax_getmax(&t) == 4.0);

	minmax_update(&t, 11.0);

	assert(minmax_exists(&t) == true);
	assert(minmax_getval(&t) == 11.0);
	assert(minmax_getmin(&t) == 2.0);
	assert(minmax_getmax(&t) == 11.0);

	minmax_reset(&t);

	assert(minmax_exists(&t) == false);
}

#include <iostream>
int main() {
	std::cout << "ALL TESTS PASSED" << std::endl;
}
