#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	size_t n;
	std::cin >> n;
	std::vector<long long> a(n);
	for (size_t i = 0; i < n; i++)
		std::cin >> a[i];

	long long scur{0}, smax{0};
	for (size_t j = 0; j < n; j++) {
		scur = std::max(0LL, scur + a[j]);
		smax = std::max(smax, scur);
	}
	if (smax == 0) smax = *std::max_element(a.begin(), a.end());
	std::cout << smax << "\n";
}
