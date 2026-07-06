#include <iostream>
#include <vector>

// We pre-compute prefix and suffix or for non-overlapping windows of k
// elements, and we compute the sliding window or from those.
// https://codeforces.com/blog/entry/142846

int main() {
	size_t n, k;
	long long a, b, c, sol{0};
	std::cin >> n >> k;
	std::vector<long long> v(n), pre(n), suf(n);
	std::cin >> v[0] >> a >> b >> c;

	for (size_t i = 1; i < n; i++)
		v[i] = (a*v[i-1] + b) % c;

	for (size_t i = 0; i < n; i++)
		pre[i] = i % k == 0 ? v[i] : v[i] | pre[i-1];

	for (size_t i = n; i > 0; i--)
		suf[i-1] = i == n || (i-1) % k == 0 ? v[i-1] : v[i-1] | suf[i];

	for (long long i = k-1; i < n; i++)
		sol ^= pre[i] | suf[i-(k-1)];

	std::cout << sol << "\n";
}
