#include <iostream>
	using std::cin;
	using std::cout;
#include <iomanip>
	using std::ws;
#include <string>
	using std::string;
	using std::getline;
#include <sstream>
	using std::istringstream;

#include "minmax.h"
#include "average.h"

int main() {
	struct minmax data1;
	minmax_reset(&data1);
	struct average data2;
	average_reset(&data2);
	

	string line;
	for (;;) {
		if (minmax_exists(&data1)) {
			cout << "val1=" << minmax_getval(&data1)
			     << " (min=" << minmax_getmin(&data1)
			     << ", max=" << minmax_getmax(&data1) << ")\n";
		}
		double avg;
		if (average_exists(&data2)) {
			cout << "val2=" << average_getval(&data2)
                             << " (average=" << average_getavg(&data2) << ")\n";
		}
		cout << "--> ";
		if (!getline(cin, line)) break;
		if (line == ".") break;
		if (line == "*") {
			minmax_reset(&data1);
			average_reset(&data2);
			continue;
		}
		istringstream iss(line + " ");
		double tval1, tval2;
		if (!(iss >> tval1 >> tval2 >> ws).eof()) {
			cout << "invalid input!\n";
			continue;
		}
		minmax_update(&data1, tval1);
		average_update(&data2, tval2);
	}
}
