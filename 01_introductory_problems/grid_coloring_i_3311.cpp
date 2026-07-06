#include <iostream>
#include <string>

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		for (int j = 0; j < m; j++) {
			char c = 'A' + 2*((i+j)%2);
			c += c == s[j];
			std::cout << c;
		}
		std::cout << "\n";
	}
}
