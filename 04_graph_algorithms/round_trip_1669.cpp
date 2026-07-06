#include <iostream>
#include <vector>

std::vector<int> cyc;

int dfs(const std::vector<std::vector<int>>& a,
    std::vector<bool>& v, int i, int p) {
	v[i] = true;
	for (auto x : a.at(i)) {
		if (x == p) continue;
		if (v.at(x)) {
			cyc.push_back(x);
			cyc.push_back(i);
			return x;
		}
		if (int r = dfs(a, v, x, i); r != 0) {
			cyc.push_back(i);
			if (r == i) {
				std::cout << cyc.size() << "\n";
				for (auto y : cyc) std::cout << y << " ";
				std::cout << "\n";
				exit(0);
			} else return r;
		}
	}
	return 0;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n+1);
	for (int i = 0; i < m; i++) {
		int x, y;
		std::cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	std::vector<bool> v(n+1);
	for (int i = 1; i <= n; i++)
		if (!v.at(i))
			dfs(a, v, i, 0);
	std::cout << "IMPOSSIBLE\n";
}
