#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

void add_to_map(size_t i, size_t e, long long s,
    const std::vector<long long>& a,
    std::unordered_map<long long, long long>& m) {
	if (i == e) { m[s]++; return; }
	add_to_map(i+1, e, s, a, m);
	add_to_map(i+1, e, s+a[i], a, m);
}

long long f(size_t i, size_t e, long long t, long long s,
    const std::vector<long long>& a,
    const std::unordered_map<long long, long long>& m) {
	if (t < 0 || t > s) return 0;
	if (i == e) return m.find(t) == m.end() ? 0 : m.at(t);
	return f(i+1, e, t, s-a[i], a, m) + f(i+1, e, t-a[i], s-a[i], a, m);
}

int main() {
	size_t n, p;
	long long x, s{0};
	std::cin >> n >> x;
	std::vector<long long> a(n);
	for (size_t i = 0; i < n; i++)
		std::cin >> a[i];

	std::sort(a.begin(), a.end(), std::greater<long long>());
	s = std::accumulate(a.begin(), a.end(), 0LL);
	if (x > s) {
		std::cout << "0\n";
		return 0;
	}

	p = a.size()/2;
	std::unordered_map<long long, long long> m;
	add_to_map(p, a.size(), 0, a, m);
	std::cout << f(0, p, x, s, a, m) << "\n";
}
