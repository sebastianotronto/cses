#include <iostream>
#include <format>

void print(int number, int ndigits) {
	std::cout << std::format("{0:0{1}b}", number, ndigits) << "\n";
}

void print_all(int& start, int digit, int ndigits) {
	if (digit == 0) {
		print(start, ndigits);
	} else {
		print_all(start, digit-1, ndigits);
		start ^= 1 << (digit-1);
		print_all(start, digit-1, ndigits);
	}
}

int main() {
	int n, start{0};
	std::cin >> n;
	print_all(start, n, n);
}
