#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

int main() {
	long long n, k, x, a, b, c, m{0};
	std::cin >> n >> k >> x >> a >> b >> c;

	std::vector<long long> v(k);
	for (long long i = 0; i < k; i++) {
		v[i] = x;
		m ^= x;
		x = (a*x + b) % c;
	}

	long long sol{m};
	for (long long i = 0; i < n-k; i++) {
		m ^= v[i%k];
		v[i%k] = (a*v[(i-1+k)%k] + b) % c;
		m ^= v[i%k];
		sol ^= m;
	}

	std::cout << sol << "\n";
}
