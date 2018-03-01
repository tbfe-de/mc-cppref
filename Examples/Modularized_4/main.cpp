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

	string line;
	for (;;) {
		if (minmax_exists()) {
			cout << "val1=" << minmax_getval()
			     << " (min=" << minmax_getmin()
			     << ", max=" << minmax_getmax() << ")\n";
		}
		double avg;
		if (average_exists()) {
			cout << "val2=" << average_getval() << " (average=" << average_getavg() << ")\n";
		}
		cout << "--> ";
		if (!getline(cin, line)) break;
		if (line == ".") break;
		if (line == "*") {
			minmax_reset();
			average_reset();
			continue;
		}
		istringstream iss(line + " ");
		double tval1, tval2;
		if (!(iss >> tval1 >> tval2 >> ws).eof()) {
			cout << "invalid input!\n";
			continue;
		}
		minmax_update(tval1);
		average_update(tval2);
	}
}
