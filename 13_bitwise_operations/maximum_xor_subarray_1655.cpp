#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

// First we compute the array a of cumulative xor starting from the
// first element (a[0] being set to 0 for convenience). Then we
// work bit by bit from the highest bit, building at each point
// an unordered set of the the available top-masked elements. We
// always try to find a full-mask, but when a bit is not available
// we store it in a the mask called "no". The reasoning is similar
// to finding a pair of elements in an array with a specified sum.
// The official solution uses a trie; it is more elegant and more
// efficient, but the idea is not too different.

unsigned bit(unsigned i) { return 1U << (i-1); }

bool no_bit(const std::vector<unsigned>& a, unsigned b) {
	return std::ranges::none_of(a, [b](unsigned x){ return x & b; });
}

bool pair_match(
    const std::unordered_set<unsigned>& s, unsigned m, unsigned no) {
	for (auto x : s)
		if (s.contains(((~x)&m)^no))
			return true;
	return false;
}

int main() {
	size_t n;
	std::cin >> n;
	std::vector<unsigned> a(n+1); // Cumulative xor
	a[0] = 0;
	for (size_t i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] ^= a[i-1];
	}
	unsigned i{32}, no{0};
	for ( ; i > 0 && no_bit(a, bit(i)); i--)
		no |= bit(i);
	i--;
	std::unordered_set<unsigned> s;
	for ( ; i > 0; i--) {
		unsigned m = ~(bit(i) - 1);
		s.clear();
		for (auto x : a)
			s.insert(x & m);
		if (!pair_match(s, m, no))
			no |= bit(i);
	}
	std::cout << ~no << "\n";
}
