#include <iostream>

static constexpr unsigned long long MOD = 1000000007;

unsigned long long pow(unsigned long long a, unsigned long long b,
    unsigned long long mod) {
	if (b == 0) return 1;
	if (a == 0) return 0;
	if (b % 2 == 0) return pow(a*a % mod, b/2, mod) % mod;
	return (a * pow(a, b-1, mod)) % mod;
}

int main() {
	unsigned long long n, a, b, c;
	std::cin >> n;
	for (unsigned long long i = 0; i < n; i++) {
		std::cin >> a >> b >> c;
		std::cout << pow(a, pow(b, c, MOD-1), MOD) << "\n";
	}
}
