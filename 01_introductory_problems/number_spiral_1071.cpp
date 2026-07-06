#include <algorithm>
#include <iostream>

long long f(long long x, long long y) {
	long long c = std::max(x, y);
	if (c % 2) {
		if (y >= x)
			return (c-1)*(c-1)+x;
		else
			return c*c-y+1;
	} else {
		if (y >= x)
			return c*c-x+1;
		else
			return (c-1)*(c-1)+y;
	}
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		long long x, y;
		std::cin >> y >> x;
		std:: cout << f(x, y) << std::endl;
	}
}
