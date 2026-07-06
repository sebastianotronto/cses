#include <algorithm>
#include <iostream>
#include <vector>

int f(const std::vector<int>& a, const std::vector<int>& b, size_t i, size_t j,
    std::vector<std::vector<int>>& t) {
	if (i == a.size() || j == b.size()) return t[i][j] = 0;
	if (t[i][j] != -1) return t[i][j];
	if (a[i] == b[j]) return t[i][j] = 1+f(a, b, i+1, j+1, t);
	return t[i][j] = std::max(f(a, b, i+1, j, t), f(a, b, i, j+1, t));
}

std::vector<int> read(size_t n) {
	std::vector<int> a(n);
	for (size_t i = 0; i < n; i++)
		std::cin >> a[i];
	return a;
}

int main() {
	std::size_t n, m;
	std::cin >> n >> m;
	std::vector<int> a = read(n);
	std::vector<int> b = read(m);
	std::vector<std::vector<int>> t(n+1, std::vector<int>(m+1, -1));
	int x = f(a, b, 0, 0, t);
	std::cout << x << "\n";

	std::vector<int> s;
	size_t i{0}, j{0};
	while (x > 0) {
		if (a[i] == b[j]) {
			s.push_back(a[i]);
			i++; j++; x--;
		} else {
			if (t[i+1][j] == x) i++;
			else j++;
		}
	}

	for (auto x : s)
		std::cout << x << " ";
	std::cout << "\n";
}
