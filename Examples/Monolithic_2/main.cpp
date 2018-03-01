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

double vals[5];
double avg;
int count = 0;

int main() {

	string line;
	for (;;) {
		if (!first) {
			cout << "val1=" << val << " (min=" << min << ", max=" << max << ")\n";
		}
		if (count > 0) {
			double sum = 0.0;
			for (int i = 0; i < count; ++i)
				sum += vals[i];
			cout << "val2=" << vals[0] << " (average=" << sum / count << ")\n";
		}
		cout << "--> ";
		if (!getline(cin, line)) break;
		if (line == ".") break;
		if (line == "*") {
			first = true;
			count = 0;
			continue;
		}
		istringstream iss(line + " ");
		double tval;
		if (!(iss >> val >> tval >> ws).eof()) {
			cout << "invalid input!\n";
			continue;
		}
		if (first) {
			min = max = val;
			first = false;
		}
		else if (min > val) min = val;
		else if (max < val) max = val;
		int n = (count == 5) ? 5 : ++count;
		while (--n > 0)
			vals[n] = vals[n-1];
		vals[0] = tval;
	}
}
