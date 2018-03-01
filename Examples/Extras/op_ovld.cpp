enum Color { R, G, B };

#include <iostream>

std::ostream &operator<<(std::ostream& lhs, Color rhs) {
	switch (rhs) {
	case R: lhs << "R"; break;
	case G: lhs << "G"; break;
	case B: lhs << "B"; break;
	}
	
}

Color operator++(Color &c) {
	switch (c) {
	case R: return c = G;
	case G: return c = B;
	case B: return c = R;
	}
}

Color operator++(Color &c, int) {
	const Color old = c;
	switch (c) {
	case R: c = G;
	case G: c = B;
	case B: c = R;
	}
	return old;
}

int main()
{
	Color c = R;
	std::cout << c << std::endl;
	std::cout << c++ << std::endl;
}
