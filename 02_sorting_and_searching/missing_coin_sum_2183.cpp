#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	size_t n, s{1};
	std::cin >> n;
	std::vector<size_t> a(n);
	for (size_t i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(a.begin(), a.end());
	for (auto c : a)
		if (s < c) break;
		else s+= c;
	std::cout << s << std::endl;
}
