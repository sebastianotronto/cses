#include <iostream>
#include <string>
#include <vector>

struct S {
	std::string w;
	std::string t;

	size_t size() const { return w.size() + 1 + t.size(); }

	char operator[](size_t i) const {
		if (i < w.size()) return w.at(i);
		if (i > w.size()) return t.at(i-w.size()-1);
		return '$';
	}
};

int main() {
	S s;
	std::cin >> s.t >> s.w;
	size_t c{0};
	std::vector<size_t> z(s.size(), 0);
	z[0] = s.w.size();
	for (size_t i = 1, j = 0, k = 0; i < s.size(); i++) {
		if (j < i || z[i-k] == j-i) {
			for (j = std::max(i, j); j < s.size() && s[j] == s[j-i]; j++) ;
			z[k=i] = j-i;
		} else z[i] = std::min(z[i-k], j-i);
		c += z[i] == s.w.size();
	}
	std::cout << c << "\n";
}
