#include <algorithm>
#include <iostream>
#include <string>

int main() {
	char cur{'x'};
	int n{0}, m{0};
	std::string str;
	std::cin >> str;
	for (auto c : str) {
		if (c == cur) {
			n++;
		} else {
			m = std::max(m, n);
			n = 1;
			cur = c;
		}
	}
	std::cout << std::max(m, n) << std::endl;
}
