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
	struct average data2;

	string line;
	for (;;) {
		if (data1.exists()) {
			cout << "val1=" << data1.getval()
			     << " (min=" << data1.getmin()
			     << ", max=" << data1.getmax() << ")\n";
		}
		double avg;
		if (data2.exists()) {
			cout << "val2=" << data2.getval()
                             << " (average=" << data2.getavg() << ")\n";
		}
		cout << "--> ";
		if (!getline(cin, line)) break;
		if (line == ".") break;
		if (line == "*") {
			data1.reset();
			data2.reset();
			continue;
		}
		istringstream iss(line + " ");
		double tval1, tval2;
		if (!(iss >> tval1 >> tval2 >> ws).eof()) {
			cout << "invalid input!\n";
			continue;
		}
		data1.update(tval1);
		data2.update(tval2);
	}
}
