#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n, x;
	std::cin >> n >> x;
	std::vector<std::pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	std::sort(a.begin(), a.end());

	int i{0}, j{n-1};
	while (i < j) {
		auto [ai, ii] = a[i];
		auto [aj, ij] = a[j];
		if (ai + aj < x) i++;
		else if (ai + aj > x) j--;
		else {
			std::cout << ii+1 << " " << ij+1 << "\n";
			return 0;
		}
	}
	std::cout << "IMPOSSIBLE\n";
}
