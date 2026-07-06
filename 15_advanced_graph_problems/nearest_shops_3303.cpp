#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

// The difficult part is finding for every city with an anime shop the
// closest other city with a shop. We do this via a "double BFS", where
// we reach each node twice from two different sources.

struct V { int v1; int s1; int v2; int s2; };

int main() {
	constexpr int max{99999999};
	int n, m, k, x, y;
	std::queue<std::tuple<int, int, int>> q;
	std::cin >> n >> m >> k;
	std::vector<V> v(n, {max, -1, max, -1});
	for (int i = 0; i < k; i++) {
		std::cin >> x;
		v[x-1] = {0, x-1, max, -1};
		q.push({x-1, 0, x-1});
	}
	std::vector<std::vector<int>> a(n);
	for (int i = 0; i < m; i++) {
		std::cin >> x >> y;
		a[x-1].push_back(y-1);
		a[y-1].push_back(x-1);
	}

	while (!q.empty()) {
		auto [u, w, s] = q.front();
		q.pop();
		for (auto z : a[u]) {
			if (z == s) continue;
			auto& [v1, s1, v2, s2] = v[z];
			if (v1 > w+1) {
				v1 = w+1;
				s1 = s;
				q.push({z, w+1, s});
			} else if (s1 != s && v2 > w+1) {
				v2 = w+1;
				s2 = s;
				q.push({z, w+1, s});
			}
		}
	}

	for (int i = 0; i < n; i++) {
		auto [x, s, y, _] = v[i];
		auto w = s == i ? y : x;
		std::cout << (w == max ? -1 : w) << " ";
	}
	std::cout << "\n";
}
