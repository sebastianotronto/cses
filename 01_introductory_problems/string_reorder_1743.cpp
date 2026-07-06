#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

int main() {
	std::array<size_t, 26> a{};
	std::string s;
	std::cin >> s;
	for (auto c : s) a[c-'A']++;

	size_t i{0}, j{1}, tot{s.size()}, c{99};
	std::stringstream ss{};
	while (*std::max_element(a.begin(), a.end()) <= tot / 2) {
		while (a[i] == 0) i++;
		while (a[j] == 0 || j <= i) j++;
		c = i == c ? j : i;
		ss << (char)('A' + c);
		a[c]--;
		tot--;
	}

	j = std::distance(a.begin(), std::max_element(a.begin(), a.end()));
	while (a[j] > 1) {
		if (tot == a[j]) {
			std::cout << "-1\n";
			return 0;
		}
		while (a[i] == 0 || i == j) i++;
		ss << (char)('A' + j) << (char)('A' + i);
		a[i]--;
		a[j]--;
		tot -= 2;
	}
	std::cout << ss.str() << (char)('A' + j) << "\n";
}
