#include <iostream>
#include <queue>
#include <utility>
#include <vector>

class dvpair {
public:
	size_t d;
	size_t v;
	auto operator<=>(const dvpair& p) const { return p.d <=> d; }
};

int main() {
	size_t n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<size_t, size_t>>> a(n);
	for (size_t i = 0; i < m; i++) {
		size_t x, y, z;
		std::cin >> x >> y >> z;
		a[x-1].push_back({y-1, z});
	}

	constexpr size_t inf{999999999999999ULL};
	std::vector<size_t> d(n, inf);
	std::priority_queue<dvpair> q;
	d[0] = 0;
	q.push({0, 0});
	while (!q.empty()) {
		auto [dd, p] = q.top();
		q.pop();
		if (dd > d[p])
			continue;
		for (auto [r, w] : a[p]) {
			if (w + d[p] < d[r]) {
				d[r] = d[p] + w;
				q.push({d[r], r});
			}
		}
	}
	for (auto x : d)
		std::cout << x << " ";
	std::cout << "\n";
}
