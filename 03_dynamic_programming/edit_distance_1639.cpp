#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int d(const std::string& a, const std::string& b, size_t i, size_t j,
    std::vector<std::vector<int>>& t) {
	if (t[i][j] != -1) return t[i][j];
	if (i == a.size()) return t[i][j] = b.size()-j;
	if (j == b.size()) return t[i][j] = a.size()-i;
	if (a[i] == b[j]) return t[i][j] = d(a, b, i+1, j+1, t);
	return t[i][j] = 1+std::min(d(a, b, i+1, j+1, t),
	    std::min(d(a, b, i+1, j, t), d(a, b, i, j+1, t)));
}

int main() {
	std::string a, b;
	std::cin >> a >> b;
	std::vector<std::vector<int>>
	    t(a.size()+1, std::vector<int>(b.size()+1, -1));
	std::cout << d(a, b, 0, 0, t) << "\n";
}
