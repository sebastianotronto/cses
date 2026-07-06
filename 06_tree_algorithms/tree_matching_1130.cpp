#include <iostream>
#include <vector>

int f(const std::vector<std::vector<int>>& a,
    std::vector<std::vector<int>>& t, int v, int p, bool x) {
	if (t[v][x] != -1) return t[v][x];
	if (p != -1 && a[v].size() == 1) return t[v][x] = 0;

	t[v][x] = 0;
	for (auto u : a[v]) {
		if (u == p) continue;
		t[v][x] += f(a, t, u, v, false);
	}
	if (x) return t[v][x];

	for (auto u : a[v]) {
		if (u == p) continue;
		if (f(a, t, u, v, true) == t[u][false]) {
			t[v][x]++;
			break;
		}
	}
	return t[v][x];
}

int main() {
	int n, x, y;
	std::cin >> n;
	std::vector<std::vector<int>> a(n);
	for (int i = 0; i < n-1; i++) {
		std::cin >> x >> y;
		a[x-1].push_back(y-1);
		a[y-1].push_back(x-1);
	}
	if (n == 1) {
		std::cout << "0\n";
		return 0;
	}
	std::vector<std::vector<int>> t(n, {-1, -1});
	std::cout << f(a, t, 0, -1, false) << "\n";
}
