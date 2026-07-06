#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string s;
	std::cin >> s;
	std::vector<size_t> z(s.size(), 0), c;
	z[0] = s.size();
	for (size_t i = 1, j = 0, k = 0; i < s.size(); i++) {
		if (j < i || z[i-k] == j-i) {
			for (j = std::max(i, j); j < s.size() && s[j] == s[j-i]; j++) ;
			z[k=i] = j-i;
		} else z[i] = std::min(z[i-k], j-i);
		if (z[i] == s.size()-i)
			c.push_back(z[i]);
	}
	std::sort(c.begin(), c.end());
	for (auto x : c)
		std::cout << x << " ";
	std::cout << "\n";
}
