#include <iostream>

int main() {
	unsigned long long n, f, p, s{0};
	std::cin >> n;

	for (unsigned long long i = 1, m = n; i <= n; i <<= 1, m >>= 1) {
		f = i * (m / 2);
		p = (n % (2*i)) + 1;
		p = p > i ? p - i : 0;
		s += f + p;
	}
	std::cout << s << "\n";
}
