#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> readn(int n) {
	std::vector<int> v(n);
	for (int i = 0; i < n; i++)
		std::cin >> v[i];
	return v;
}

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;
	auto a = readn(n);
	auto b = readn(m);
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	size_t s{0}, i{0}, j{0};
	while (i < a.size() && j < b.size()) {
		if (b[j] > a[i] + k) i++;
		else if (b[j] < a[i] - k) j++;
		else { s++; i++; j++; }
	}
	std::cout << s << "\n";
}
