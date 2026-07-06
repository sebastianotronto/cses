#include <array>
#include <bitset>
#include <iostream>

// This method is very different (and more complicated) than the one used
// in the official solution.
// First we save in spf[i] the smallest prime number that divides i.
// Then we initialize an array d with d[i] being 1 if i is in the input.
// Then we loop backwards and we search all divisors of the numbers marked
// in d. For each number we encounter, we look at its maximal divisors.
// If any of them was already found, we update our candidate solution.
// To avoid looking at a divisor more than once, we save in d[i] the
// smallest prime we want to continue diving i by to find more divisors.

constexpr size_t max = 1000001;
std::array<size_t, max> spf; // Smallest prime factor of i
std::array<size_t, max> d;

int main() {
	for (size_t i = 2; i < max; i++) {
		if (spf[i] != 0) continue;
		spf[i] = i;
		for (size_t j = 2; i*j < max; j++)
			if (spf[i*j] == 0)
				spf[i*j] = i;
	}

	size_t n, sol{1};
	std::cin >> n;
	for (size_t i = 0; i < n; i++) {
		size_t x;
		std::cin >> x;
		if (d[x] != 0) sol = std::max(sol, x);
		d[x] = 1;
	}

	for (size_t i = max-1; i >= sol; i--) {
		if (d[i] == 0) continue;

		// Loop over maximal divisors of i
		size_t y{i};
		while (y != 1) {
			size_t p = spf[y];
			if (i/p < sol) break;
			if (p >= d[i]) {
				if (d[i/p] != 0) sol = std::max(sol, i/p);
				d[i/p] = p;
			}
			while (y % p == 0) y /= p;
		}
	}
	std::cout << sol << "\n";
}
