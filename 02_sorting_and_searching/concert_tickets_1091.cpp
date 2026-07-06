#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main() {
	size_t n, m;
	std::cin >> n >> m;
	std::vector<int> hv(n), t(m);
	for (size_t i = 0; i < n; i++)
		std::cin >> hv[i];
	for (size_t i = 0; i < m; i++)
		std::cin >> t[i];

	std::multiset<int, std::greater<int>> h(hv.begin(), hv.end());

	for (auto c : t) {
		if (auto x = h.lower_bound(c); x == h.end()) {
			std::cout << "-1\n";
		} else {
			std::cout << *x << "\n";
			h.erase(x);
		}
	}
}
