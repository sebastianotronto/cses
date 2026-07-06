#include <iostream>

int main() {
	int n, c{0};
	std::cin >> n;
	while (n > 0)
		c += (n /= 5);
	std::cout << c << std::endl;
}
