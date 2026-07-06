#include <array>
#include <iostream>

constexpr size_t max = 1000001;
std::array<size_t, max> spf; // Smallest prime factor of i

size_t ndiv(size_t x) {
	size_t n{1}, d{0}, e{0};
	for (size_t i = x; i > 1; i /= spf[i]) {
		if (spf[i] != d) {
			n *= e+1;
			d = spf[i];
			e = 1;
		} else e++;
	}
	return n * (e+1);
}

int main() {
	for (size_t i = 2; i < max; i++) {
		if (spf[i] != 0) continue;
		spf[i] = i;
		for (size_t j = 2; i*j < max; j++)
			if (spf[i*j] == 0)
				spf[i*j] = i;
	}

	size_t n, x;
	std::cin >> n;
	for (size_t i = 0; i < n; i++) {
		std::cin >> x;
		std::cout << ndiv(x) << "\n";
	}
}
