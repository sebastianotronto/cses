#include <algorithm>
#include <iostream>
#include <vector>

static constexpr int inf = 1999999999;

std::vector<int> digits(int n) {
	std::vector<int> d;
	for (int i = n; i != 0; i /= 10)
		d.push_back(i % 10);
	return d;
}

int f(std::vector<int>& a, int n) {
	if (a[n] != inf) return a[n];
	for (auto d : digits(n))
		if (d != 0)
			a[n] = std::min(a[n], 1+f(a, n-d));
	return a[n];
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n+1, inf);
	a[0] = 0;
	std::cout << f(a, n) << "\n";
}
