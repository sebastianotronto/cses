#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n, x;
	std::cin >> n >> x;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(a.begin(), a.end());
	size_t i{0}, j{a.size()-1}, s{0};
	for (; j > i; j--, s++)
		i += a[i] + a[j] <= x;
	if (i == j) s++;
	std::cout << s << "\n";
}
