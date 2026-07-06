#include <iostream>

int main() {
	long long n, m, sum{0};
	std::cin >> n;
	while (std::cin >> m)
		sum += m;
	std::cout << n*(n+1)/2 - sum << std::endl;
}
