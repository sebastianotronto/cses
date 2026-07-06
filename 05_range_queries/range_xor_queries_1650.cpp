#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	size_t n, q;
	std::cin >> n >> q;
	std::vector<int> p(n);
	for (size_t i = 0; i < n; i++)
		std::cin >> p[i];
	for (size_t i = 1; i < n; i++)
		p[i] ^= p[i-1];
	for (size_t i = 0; i < q; i++) {
		int x, k, s;
		std::cin >> x >> k;
		s = p[k-1];
		if (x > 1) s ^= p[x-2];
		std::cout << s << "\n";
	}
}
