#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
	size_t n;
	std::cin >> n;
	std::vector<int> v(n);
	for (size_t i = 0; i < n; i++)
		std::cin >> v[i];

	size_t l{0}, s{0};
	std::map<int, size_t> m;
	for (size_t r = 0; r < n; r++) {
		if (m.contains(v[r]))
			l = std::max(l, m.at(v[r])+1);
		m[v[r]] = r;
		s = std::max(s, r-l+1);
	}
	std::cout << s << "\n";
}
