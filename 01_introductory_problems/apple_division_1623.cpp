#include <iostream>
#include <numeric>
#include <vector>

long long md(std::vector<long long>& a, long long p, long long t, size_t i) {
	if (2*p >= t)
		return 2*p - t;
	if (i == a.size())
		return t;
	return std::min(md(a, p, t, i+1), md(a, p+a[i], t, i+1));
}

int main() {
	size_t n;
	std::cin >> n;
	std::vector<long long> a(n);
	for (size_t i = 0; i < n; i++)
		std::cin >> a[i];
	auto s = md(a, 0, std::accumulate(a.begin(), a.end(), (long long)0), 0);
	std::cout << s << "\n";
}
