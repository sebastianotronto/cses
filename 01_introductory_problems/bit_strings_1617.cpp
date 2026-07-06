#include <iostream>

int main() {
	constexpr long long M = 1e9+7;
	long long n, a{1};
	std::cin >> n;
	while (--n >= 0)
		a = (a * 2) % M;
	std::cout << a << std::endl;
}
