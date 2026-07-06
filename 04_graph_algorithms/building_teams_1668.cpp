#include <iostream>
#include <vector>

bool visit(size_t i, int c, const std::vector<std::vector<size_t>>& a,
    std::vector<int>& t) {
	if (t[i] != 0) return true;
	t[i] = c;
	for (auto j : a[i])
		if (t[j] == c)
			return false;
		else if (!visit(j, 3-c, a, t)) return false;
	return true;
}

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

	std::vector<int> t(n);
	for (size_t i = 0; i < n; i++) {
		if (t[i] == 0) {
			if (!visit(i, 1, a, t)) {
				std::cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
	}
	for (auto x : t) std::cout << x << " ";
	std::cout << "\n";
}
