#include <iostream>
#include <vector>

int main() {
	size_t n, x, s{1}, l{0};
	std::cin >> n;
	std::vector<size_t> b(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> x;
		b[x-1] = i;
	}
	for (size_t i = 0; i < n; i++) {
		s += b[i] < l;
		l = b[i];
	}
	std::cout << s << "\n";
}


// The code below solves a different problem: it finds the minimum number
// of ascending chains needed to partition the given list of numbers.

#if 0

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	size_t n;
	std::vector<size_t> s;
	std::cin >> n;
	for (size_t i = 0; i < n; i++) {
		size_t x;
		std::cin >> x;
		auto it = std::lower_bound(
		    s.begin(), s.end(), x, std::greater<size_t>());
		if (it != s.end())
			*it = x;
		else
			s.push_back(x);
	}
	std::cout << s.size() << std::endl;
}

#endif
