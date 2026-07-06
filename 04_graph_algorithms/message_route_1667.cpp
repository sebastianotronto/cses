#include <iostream>
#include <queue>
#include <ranges>
#include <vector>

constexpr size_t inf = 1999999999;

int main() {
	size_t n, m;
	std::cin >> n >> m;
	std::vector<std::vector<size_t>> a(n);
	for (size_t i = 0; i < m; i++) {
		size_t x, y;
		std::cin >> x >> y;
		a[x-1].push_back(y-1);
		a[y-1].push_back(x-1);
	}

	std::queue<size_t> q;
	std::vector<size_t> d(n, inf);
	d[0] = 0;
	q.push(0);
	while (!q.empty()) {
		auto i = q.front();
		q.pop();
		if (i == n-1) break;
		for (auto j : a[i]) {
			if (d[j] > d[i]+1) {
				d[j] = d[i] + 1;
				q.push(j);
			}
		}
	}

	if (d[n-1] == inf) {
		std::cout << "IMPOSSIBLE\n";
	} else {
		std::cout << d[n-1]+1 << "\n";
		// Backtracking
		std::vector<size_t> v;
		v.push_back(n-1);
		while (v.back() != 0) {
			for (auto j : a[v.back()]) {
				if (d[j] == d[v.back()]-1) {
					v.push_back(j);
					break;
				}
			}
		}
		for (auto x : v | std::views::reverse)
			std::cout << x+1 << " ";
		std::cout << "\n";
	}
}
