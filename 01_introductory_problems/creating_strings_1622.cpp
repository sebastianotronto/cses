#include <iostream>
#include <string>
#include <map>
#include <vector>

void gen(std::map<char, int>& a, int count,
    std::string start, std::vector<std::string>& res) {
	if (count == 0)
		res.push_back(start);
	for (auto [k, v] : a) {
		if (v > 0) {
			a[k]--;
			gen(a, count - 1, start + k, res);
			a[k]++;
		}
	}
}

int main() {
	std::string s;
	std::map<char, int> a;
	std::vector<std::string> sol;
	std::cin >> s;
	for (auto c : s)
		a[c]++;
	gen(a, s.size(), "", sol);
	std::cout << sol.size() << "\n";
	for (auto x : sol)
		std::cout << x << "\n";
}
