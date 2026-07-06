#include <algorithm>
#include <bit>
#include <iostream>
#include <vector>

int main() {
	unsigned n, k;
	std::cin >> n >> k;
	std::vector<unsigned> a(n);
	for (unsigned i = 0; i < n; i++) {
		for (unsigned j = 0, p = 1; j < k; j++, p <<= 1) {
			char c;
			std::cin >> c;
			if (c == '1') a[i] += p;
		}
	}
	int s = k+1;
	for (unsigned i = 0; i < n; i++)
		for (unsigned j = i+1; j < n; j++)
			s = std::min(s, std::popcount(a[i] ^ a[j]));
	std::cout << s << "\n";
}
