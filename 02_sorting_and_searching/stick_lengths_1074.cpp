#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	long long n;
	std::cin >> n;
	std::vector<long long> a(n);
	for (long long i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(a.begin(), a.end());
	long long s{0}, t{a[n/2]};
	for (auto x : a)
		s += std::abs(x-t);
	std::cout << s << "\n";
}
