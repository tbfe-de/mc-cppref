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
		if (!first) {
			cout << "val1=" << val << " (min=" << min << ", max=" << max << ")\n";
		}
		if (count > 0) {
			cout << "val2=" << vals[0] << " (average=" << average_calculate() << ")\n";
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
		double tval;
		if (!(iss >> val >> tval >> ws).eof()) {
			cout << "invalid input!\n";
			continue;
		}
		minmax_update();
		average_update(tval);
	}
}
