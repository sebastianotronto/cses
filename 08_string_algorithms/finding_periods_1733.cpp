#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool isp(const std::vector<size_t>& z, size_t k) {
	for (size_t i = 0; i*k < z.size(); i++)
		if (z[i*k] < std::min(k, z.size()-i*k))
			return false;
	return true;
}

int main() {
	std::string s;
	std::cin >> s;
	std::vector<size_t> z(s.size(), 0);
	z[0] = s.size();
	for (size_t i = 1, j = 0, k = 0; i < s.size(); i++) {
		if (j < i || z[i-k] == j-i) {
			for (j = std::max(i, j); j < s.size() && s[j] == s[j-i]; j++) ;
			z[k=i] = j-i;
		} else z[i] = std::min(z[i-k], j-i);
	}

	for (size_t i = 1; i <= s.size(); i++)
		if (isp(z, i))
			std::cout << i << " ";
	std::cout << "\n";
}
