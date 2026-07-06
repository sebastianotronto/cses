#include <iostream>
#include <vector>

void visit(size_t i, const std::vector<std::vector<size_t>>& a,
    std::vector<bool>& c) {
	if (c[i]) return;
	c[i] = true;
	for (auto j : a[i])
		visit(j, a, c);
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

	std::vector<bool> c(n, false);
	std::vector<size_t> s;
	for (size_t i = 0; i < n; i++) {
		if (c[i]) continue;
		if (i != 0) s.push_back(i);
		visit(i, a, c);
	}
	std::cout << s.size() << "\n";
	for (auto x : s) std::cout << "1 " << x+1 << "\n";
}
