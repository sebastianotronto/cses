#include <iostream>
#include <vector>

int main() {
	long long n, a;
	std::vector<long long> b = {0, 0, 6, 28, 96};
	std::cin >> n;

	for (long long k = 1; k <= n; k++) {
		if (k <= 4) {
			a = b[k];
		} else {
			// Both knights in new strip
			a += (2*k - 1)*(k - 1) - 2;

			// One knight in new strip, one in previous square
			const long long s = (k-1)*(k-1);
			a += 5*(s - 2);
			a += 4*(s - 3);
			a += (2*k - 10)*(s - 4);
		}
		std::cout << a << std::endl;
	}
}
