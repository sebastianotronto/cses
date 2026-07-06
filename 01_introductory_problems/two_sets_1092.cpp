#include <iostream>
#include <vector>

void printarr(const std::vector<int>& a) {
	std::cout << a.size() << std::endl;
	for (auto x : a)
		std::cout << x << " ";
	std::cout << std::endl;
}

int main() {
	int n;
	std::cin >> n;

	switch (n % 4) {
	case 1:
	case 2:
		std::cout << "NO\n";
		break;
	case 0:
		std::cout << "YES\n";
		{
			std::vector<int> a(n/2), b(n/2);
			for (int i = 0; i < n/4; i++) {
				a[2*i] = 4*i+1;
				a[2*i+1] = 4*i+4;
				b[2*i] = 4*i+2;
				b[2*i+1] = 4*i+3;
			}
			printarr(a);
			printarr(b);
		}
		break;
	case 3:
		std::cout << "YES\n";
		if (n == 3) {
			std::cout << "2\n1 2\n1\n3\n";
		} else {
			std::vector<int> a(n/2+1), b(n/2);
			a[0] = 1; a[1] = 2; a[2] = 4; a[3] = 7;
			b[0] = 3; b[1] = 5; b[2] = 6;
			for (int i = 1; i < n/4; i++) {
				a[2*i+2] = 4*i+4;
				a[2*i+3] = 4*i+7;
				b[2*i+1] = 4*i+5;
				b[2*i+2] = 4*i+6;
			}
			printarr(a);
			printarr(b);
		}
		break;
	}
}
