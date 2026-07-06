#include <iostream>
#include <string>

int main() {
	int m, l{0}, r{1000000000};
	std::string s;
	while (l+1 != r) {
		m = (l+r)/2;
		std::cout << "? " << m << std::endl;
		std::cin >> s;
		if (s == "YES") l = m;
		else r = m;
	}

	std::cout << "! " << r << std::endl;
}
