#include <algorithm>
#include <iostream>
#include <vector>

constexpr size_t inf{999999999999999ULL};

int main() {
	size_t n, m, q;
	std::cin >> n >> m >> q;
	std::vector<std::vector<size_t>> d(n, std::vector(n, inf));
	for (size_t i = 0; i < n; i++) d[i][i] = 0;
	for (size_t i = 0; i < m; i++) {
		size_t x, y, z;
		std::cin >> x >> y >> z;
		d[x-1][y-1] = d[y-1][x-1] = std::min(d[x-1][y-1], z);
	}

	for (size_t k = 0; k < n; k++)
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < n; j++)
				d[j][i] = d[i][j] =
				    std::min(d[i][j], d[i][k] + d[k][j]);

	for (size_t i = 0; i < q; i++) {
		size_t x, y;
		std::cin >> x >> y;
		long long int dd = d[x-1][y-1];
		std::cout << (dd == inf ? -1LL : dd) << "\n";
	}
}
