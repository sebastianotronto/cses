#include <iostream>
#include <utility>
#include <vector>

// Observation: putting 1 at the n-th position (1-based) generates n-1
// inversions; then, putting 2 at n-2 generates another n-2 inversions;
// and so on.
// The first step in our algorithm counts how many times we can do this,
// and leaves k pointing to the position where we should put the next
// element. All other elements are in increasing order.

int main() {
	long long n, k, p, l, m, j, i{0};
	std::cin >> n >> k;
	std::vector<long long> a(n, 0);

	for (j = 1, p = 0; p < n-1 && k >= n-j; p++, j++) k -= n-j;

	for (m = p+1, l = p+2, i = 0; i < n; i++)
		std::cout << ((n-i <= p || i == k) ? m-- : l++) << " ";
	std::cout << "\n";
}
