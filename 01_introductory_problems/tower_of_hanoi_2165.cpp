#include <iostream>

void do_hanoi(int n, int l, int m, int r) {
	if (n != 0) {
		do_hanoi(n-1, l, r, m);
		std::cout << l << " " << r << "\n";
		do_hanoi(n-1, m, l, r);
	}
}

int main() {
	int n;
	std::cin >> n;

	std::cout << (1 << n) - 1 << "\n";
	do_hanoi(n, 1, 2, 3);
}
