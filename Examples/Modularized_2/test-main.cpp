#include <cassert>

#include "average.h"
#include "minmax.h"

void test_average() {
	assert(average_exists() == false);
	
	average_update(2.0);

	assert(average_exists() == true);
	assert(average_getval() == 2.0);
	assert(average_calculate() == 2.0);

	average_update(4.0);

	assert(average_exists() == true);
	assert(average_getval() == 4.0);
	assert(average_calculate() == 3.0);

	average_update(3.0);

	assert(average_exists() == true);
	assert(average_getval() == 3.0);
	assert(average_calculate() == 3.0);

	average_update(11.0);

	assert(average_exists() == true);
	assert(average_getval() == 11.0);
	assert(average_calculate() == 5.0);

	average_reset();

	assert(average_exists() == false);
}

void test_minmax() {
	assert(minmax_exists() == false);
	
	minmax_update(2.0);

	assert(minmax_exists() == true);
	assert(minmax_getval() == 2.0);
	assert(minmax_getmin() == 2.0);
	assert(minmax_getmax() == 2.0);

	minmax_update(4.0);

	assert(minmax_exists() == true);
	assert(minmax_getval() == 4.0);
	assert(minmax_getmin() == 2.0);
	assert(minmax_getmax() == 4.0);

	minmax_update(3.0);

	assert(minmax_exists() == true);
	assert(minmax_getval() == 3.0);
	assert(minmax_getmin() == 2.0);
	assert(minmax_getmax() == 4.0);

	minmax_update(11.0);

	assert(minmax_exists() == true);
	assert(minmax_getval() == 11.0);
	assert(minmax_getmin() == 2.0);
	assert(minmax_getmax() == 11.0);

	minmax_reset();

	assert(minmax_exists() == false);
}

#include <iostream>
int main() {
	std::cout << "ALL TESTS PASSED" << std::endl;
}
