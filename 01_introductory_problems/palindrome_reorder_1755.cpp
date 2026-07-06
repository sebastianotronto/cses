#include <iostream>
#include <string>

void printn(char c, int n) {
	for (int i = 0; i < n; i++)
		std::cout << c;
}

int main() {
	std::string s;
	int odd{0}, a['Z'+1] = {0};
	char oddc{0};
	std::cin >> s;
	for (auto c : s)
		a[(size_t)c]++;
	for (char c = 'A'; c <= 'Z'; c++) {
		if (a[(size_t)c] % 2) {
			odd++;
			oddc = c;
		}
	}
	if (odd > 1) {
		std::cout << "NO SOLUTION\n";
	} else {
		for (char c = 'A'; c <= 'Z'; c++)
			if (c != oddc)
				printn(c, a[(size_t)c]/2);
		if (odd)
			printn(oddc, a[(size_t)oddc]);
		for (char c = 'Z'; c >= 'A'; c--)
			if (c != oddc)
				printn(c, a[(size_t)c]/2);
		std::cout << std::endl;
	}
}
