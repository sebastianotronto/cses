#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	size_t n;
	std::cin >> n;
	std::vector<int> v;
	for (size_t i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		auto it = std::upper_bound(v.begin(), v.end(), x);
		if (it == v.end()) v.push_back(x);
		else *it = x;
	}
	std::cout << v.size() << "\n";
}
