#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

int main() {
	int n;
	std::vector<std::tuple<int, int, int>> v;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		v.push_back({a, b, i});
	}
	std::sort(v.begin(), v.end());

	using P = std::pair<int, int>;
	std::priority_queue<P, std::vector<P>, std::greater<>> r;
	std::vector<int> al(n);
	for (auto [a, d, i] : v) {
		int ind = r.size()+1;
		if (!r.empty()) {
			auto [x, j] = r.top();
			if (a > x) {
				r.pop();
				ind = j;
			}
		}
		r.push({d, ind});
		al[i] = ind;
	}

	std::cout << r.size() << "\n";
	for (auto i : al)
		std::cout << i << " ";
	std::cout << "\n";
}
