#include <iostream>
#include <vector>

int main() {
	size_t n, k;
	long long x, a, b, c, sum{0}, sol{0};
	std::cin >> n >> k >> x >> a >> b >> c;

	std::vector<long long> v(k);
	for (size_t i = 0; i < k; i++) {
		sum += x;
		v[i] = x;
		x = (a*x + b) % c;
	}

	sol = sum;
	for (size_t i = 0; i < n-k; i++) {
		sum -= v[i%k];
		v[i%k] = (a*v[(i-1+k)%k] + b) % c;
		sum += v[i%k];
		sol ^= sum;
	}

	std::cout << sol << "\n";
}
