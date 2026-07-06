#include <iostream>

int main() {
	long long n;
	std::cin >> n;

	while (n != 1) {
		std::cout << n << " ";
		n = (n % 2) ? n * 3 + 1 : n / 2;
	}
	std::cout << 1 << std::endl;
}
