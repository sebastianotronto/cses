#include <algorithm>
#include <iostream>

int main() {
	long long n, prev{0}, sum{0};
	std::cin >> n;
	while (std::cin >> n) {
		sum += std::max<long long>(0, prev - n);
		prev = std::max(prev, n);
	}
	std::cout << sum << std::endl;
}
