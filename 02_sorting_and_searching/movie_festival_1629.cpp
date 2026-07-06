#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	size_t n;
	std::cin >> n;
	std::vector<std::pair<int, int>> v(n);
	for (size_t i = 0; i < n; i++)
		std::cin >> v[i].first >> v[i].second;
	std::sort(v.begin(), v.end());
	int e{-1}, s{0};
	for (auto a : v) {
		if (a.first >= e) {
			e = a.second;
			s++;
		}
		e = std::min(e, a.second);
	}
	std::cout << s << "\n";
}
