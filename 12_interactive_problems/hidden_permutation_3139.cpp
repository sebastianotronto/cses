#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void print_sol(const std::vector<size_t>& v) {
	std::cout << "! ";
	for (size_t i = 0; i < v.size(); i++) {
		for (size_t j = 0; j < v.size(); j++) {
			if (v[j] == i) {
				std::cout << (j+1) << " ";
				break;
			}
		}
	}
	std::cout << std::endl;
}

bool cmp(size_t i, size_t j) {
	std::cout << "? " << (i+1) << " " << (j+1) << std::endl;
	std::string s;
	std::cin >> s;
	return s == "YES";
}

size_t binsearch(size_t i, const std::vector<size_t>& v, size_t l, size_t r) {
	if (r == l) return l;
	size_t m = (l+r)/2;
	return cmp(i, v[m]) ? binsearch(i, v, l, m) : binsearch(i, v, m+1, r);
}

int main() {
	size_t n;
	std::vector<size_t> v;
	std::cin >> n;
	v.reserve(n);

	v.push_back(0);
	for (size_t i = 1; i < n; i++) {
		size_t pos = binsearch(i, v, 0, v.size());
		v.insert(std::next(v.begin(), pos), i);
	}

	print_sol(v);
}
