#include <algorithm>
#include <iostream>

bool f(int a, int b) {
	auto max = std::max(a, b);
	auto min = std::min(a, b);

	return max <= 2*min && (2*min - max) % 3 == 0;
}

int main() {
	int t, a, b;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> a >> b;
		std::cout << (f(a, b) ? "YES" : "NO") << std::endl;
	}
}
