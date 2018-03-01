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

double val;
double min;
double max;
bool first = true;

int main() {

	string line;
	for (;;) {
		if (!first) {
			cout << val << " (" << min << " .. " << max << ")\n";
		}
		cout << "--> ";
		if (!getline(cin, line)) break;
		if (line == ".") break;
		if (line == "*") {
			first = true;
			continue;
		}
		istringstream iss(line + " ");
		if (!(iss >> val >> ws).eof()) {
			cout << "invalid input!\n";
			continue;
		}
		if (first) {
			min = max = val;
			first = false;
		}
		else if (min > val) min = val;
		else if (max < val) max = val;
	}
}
