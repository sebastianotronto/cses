#include <iostream>
#include <vector>

int main() {
	int n, q, x, y;
	std::cin >> n >> q;
	std::vector<long long> a(n+1, 0);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] += a[i-1];
	}

	for (int i = 0; i < q; i++) {
		std::cin >> x >> y;
		std::cout << a[y]-a[x-1] << "\n";
	}
}
