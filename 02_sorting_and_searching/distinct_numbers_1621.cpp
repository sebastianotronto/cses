#include <iostream>
#include <set>

int main() {
	int n, x;
	std::set<int> s;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		s.insert(x);
	}
	std::cout << s.size() << "\n";
}
