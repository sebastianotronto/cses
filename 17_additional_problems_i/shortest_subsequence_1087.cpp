#include <algorithm>
#include <array>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

// Idea: keep an array a[n][4] where a[i][x] denotes the shortest
// non-subsequence of s[:i] that ends with x. The recursive relation
// is the following:
// - For s[i] != x, a[i][x] = a[i-1][x] (easy to see).
// - For s[i] == x, we have a[i][x] = 1+min(a[i-1][y] over y): if
//   the shortest non-subsequence ending with x becomes a subsequence,
//   then this is realized by adding x to the any of the current 4
//   non-subsequences (including the one already ending in x); otherwise,
//   the subsequence obtained by removing the x is still a valid
//   non-subsequence, and it must be one of the other 3, so we get back
//   the same (it can't end again in x, otherwise it would be a shorter
//   non-subsequence ending in x).
// Then we have to backtrack to find an actual solution.

size_t ind(char c) {
	switch (c) {
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
		default: return -1;
	}
}

char dni(size_t i) {
	static constexpr char a[] = {'A', 'C', 'G', 'T'};
	return a[i];
}

size_t mi(const std::array<size_t, 4>& v) {
	return *std::min_element(v.begin(), v.end());
}

int main() {
	std::string s;
	std::cin >> s;
	std::vector<std::array<size_t, 4>> a(s.size(), {1, 1, 1, 1});

	a[0][ind(s[0])] = 2;
	for (size_t i = 1; i < s.size(); i++)
		for (size_t j = 0; j < 4; j++)
			a[i][j] = ind(s[i]) == j ?  1 + mi(a[i-1]) : a[i-1][j];

	auto l = s.size()+2;
	std::vector<char> sol;
	for (size_t i = s.size(); i > 0; i--) {
		auto m = mi(a[i-1]);
		if (l != m) {
			l = m;
			auto in = std::distance(a[i-1].begin(),
			    std::min_element(a[i-1].begin(), a[i-1].end()));
			sol.push_back(dni(in));
		}
	}

	for (auto x : sol | std::views::reverse)
		std::cout << x;
	std::cout << "\n";
}
