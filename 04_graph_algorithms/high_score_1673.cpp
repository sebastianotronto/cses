#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

constexpr long long inf = 999999999999999LL;

size_t findcycle(
	size_t v,
	const std::vector<std::tuple<size_t, size_t, long long>>& a, 
	const std::vector<size_t>& p
) {
	std::vector<bool> visited(p.size(), false);
	visited[v] = true;
	size_t u = p[v];
	while (!visited[u]) {
		visited[u] = true;
		u = p[u];
	}
	return u;
}

int main() {
	size_t n, m;
	std::cin >> n >> m;
	std::vector<std::tuple<size_t, size_t, long long>> a(m);
	for (size_t i = 0; i < m; i++) {
		size_t x, y;
		long long w;
		std::cin >> x >> y >> w;
		a[i] = {x-1, y-1, w};
	}

	std::vector<size_t> p(n, n);
	std::vector<long long> d(n, -inf);
	d[0] = 0;
	std::vector<bool> reach_1(n, false), reach_n(n, false);
	reach_1[0] = reach_n[n-1] = true;
	for (size_t i = 0; i < n; i++) {
		for (auto [v, u, w] : a) {
			if (d[u] < d[v] + w) {
				d[u] = d[v] + w;
				p[u] = v;
			}
			reach_n[v] = reach_n[v] || reach_n[u];
			reach_1[u] = reach_1[u] || reach_1[v];
		}
	}

	for (auto [v, u, w] : a) {
		if (d[u] < d[v] + w) {
			size_t x = findcycle(u, a, p);
			if (reach_1[x] && reach_n[x]) {
				std::cout << "-1\n";
				return 0;
			}
		}
	}

	std::cout << d[n-1] << "\n";
}
