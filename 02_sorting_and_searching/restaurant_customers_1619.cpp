#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
	size_t n;
	std::cin >> n;
	std::vector<std::pair<int, int>> c(n);
	for (size_t i = 0; i < n; i++) {
		int a, b;
		std::cin >> a >> b;
		c[i] = {a, b};
	}
	std::sort(c.begin(), c.end());
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	size_t m{0};
	for (auto d : c) {
		while (!q.empty() && q.top() < d.first) q.pop();
		q.push(d.second);
		m = std::max(m, q.size());
	}
	std::cout << m << "\n";
}
