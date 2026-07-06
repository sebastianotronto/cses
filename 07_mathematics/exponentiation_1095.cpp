#include <iostream>

static constexpr unsigned long long MOD = 1000000007;

unsigned long long pow(unsigned long long a, unsigned long long b) {
	if (b == 0) return 1;
	if (a == 0) return 0;
	if (b % 2 == 0) return pow(a*a % MOD, b/2) % MOD;
	return (a * pow(a, b-1)) % MOD;
}

int main() {
	unsigned long long n, a, b;
	std::cin >> n;
	for (unsigned long long i = 0; i < n; i++) {
		std::cin >> a >> b;
		std::cout << pow(a, b) << "\n";
	}
}
