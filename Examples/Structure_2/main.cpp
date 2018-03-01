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
	reset(&data1);
	struct average data2;
	reset(&data2);
	

	string line;
	for (;;) {
		if (exists(&data1)) {
			cout << "val1=" << getval(&data1)
			     << " (min=" << getmin(&data1)
			     << ", max=" << getmax(&data1) << ")\n";
		}
		double avg;
		if (exists(&data2)) {
			cout << "val2=" << getval(&data2)
                             << " (average=" << getavg(&data2) << ")\n";
		}
		cout << "--> ";
		if (!getline(cin, line)) break;
		if (line == ".") break;
		if (line == "*") {
			reset(&data1);
			reset(&data2);
			continue;
		}
		istringstream iss(line + " ");
		double tval1, tval2;
		if (!(iss >> tval1 >> tval2 >> ws).eof()) {
			cout << "invalid input!\n";
			continue;
		}
		update(&data1, tval1);
		update(&data2, tval2);
	}
}
