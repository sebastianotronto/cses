#include <iostream>

int f(long long k) {
	long long n{1}, p{1}, d{1}, q{9};
	while (p + d*q <= k) {
		n += q;
		p += d * q;
		d++;
		q *= 10;
	}
	long long x{(k-p) / d + n};
	long long m{(k-p) % d};
	for (long long j = 0; j < d-m-1; j++)
		x /= (long long)10;
	return x % (long long)10;
}

int main() {
	long long k;
	std::cin >> k;
	while (std::cin >> k)
		std::cout << f(k) << "\n";
}
