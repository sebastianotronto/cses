#include <iostream>

int f(int n, int k, int m) {
	int h = n/2 + m*(n%2);
	if (n == 1) return 1;
	if (k <= h) return 2*k-m;
	return 2*f(n-h, k-h, m^(n%2))+m-1;
}

int main() {
	int q, n, k;
	std::cin >> q;
	for (int i = 0; i < q; i++) {
		std::cin >> n >> k;
		std::cout << f(n, k, 0) << "\n";
	}
}
