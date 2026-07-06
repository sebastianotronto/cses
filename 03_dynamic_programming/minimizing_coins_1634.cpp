#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int f(const std::vector<int>& c, int x) {
	static constexpr int max = 999999999;
	std::vector<int> a(x+1, max);
	std::queue<int> q;
	a[0] = 0;
	q.push(0);
	while (!q.empty()) {
		auto i = q.front();
		q.pop();
		for (auto k : c) {
			if (i + k > x || a[i+k] <= a[i]+1) continue;
			if (i + k == x) return a[i] + 1;
			a[i+k] = a[i] + 1;
			q.push(i + k);
		}
	}
	return -1;
}

int main() {
	int n, x;
	std::cin >> n >> x;
	std::vector<int> c(n);
	for (int i = 0; i < n; i++)
		std::cin >> c[i];

	std::cout << f(c, x) << "\n";
}
