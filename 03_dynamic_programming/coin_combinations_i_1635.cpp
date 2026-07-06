#include <iostream>
#include <vector>

static constexpr int mod = 1000000007;
static constexpr int X = 1000001;

int f(const std::vector<int>& c, std::vector<int>& a, int x) {
	if (x < 0) return 0;
	if (a[x] != -1) return a[x];
	if (x == 0) return a[x] = 1;

	a[x] = 0;
	for (auto m : c)
		a[x] = (a[x] + f(c, a, x-m)) % mod;
	return a[x];
}

int main() {
	int n, x;
	std::cin >> n >> x;
	std::vector<int> c(n), a(X, -1);
	for (int i = 0; i < n; i++)
		std::cin >> c[i];
	std::cout << f(c, a, x) << "\n";
}
