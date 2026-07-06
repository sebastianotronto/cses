#include <iostream>
#include <map>
#include <vector>

static constexpr int mod = 1000000007;
static constexpr int X = 1000001;

int main() {
	int n, x;
	std::cin >> n >> x;
	std::vector<int> c(n);
	for (int i = 0; i < n; i++)
		std::cin >> c[i];

	std::vector<std::vector<int>> a(n, std::vector<int>(X, 0));
	for (int i = 0; i < (int)c.size(); i++) a[i][0] = 1;
	for (int j = c.back(); j <= x; j += c.back()) a[c.size()-1][j] = 1;
	for (int i = c.size()-2; i >= 0; i--) {
		for (int j = 1; j <= x; j++) {
			a[i][j] = a[i+1][j];
			if (j >= c[i]) {
				a[i][j] += a[i][j-c[i]];
				a[i][j] %= mod;
			}
		}
	}
	std::cout << a[0][x] << "\n";
}
