#include <algorithm>
#include <array>
#include <iostream>

// We use a funny memory optimization: we only store the last 7 values.

int main() {
	constexpr unsigned mod = 1e9+7;
	int n;
	std::cin >> n;
	std::array<int, 7> v{0};
	v[0] = 1;
	for (int i = 1; i <= n; i++) {
		v[i%7] = 0;
		for (int j = std::max(0, i-6); j < i; j++)
			v[i%7] = (v[i%7]+v[j%7]) % mod;
	}
	std::cout << v[n%7] << "\n";
}
