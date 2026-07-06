#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void fill(const std::vector<std::vector<char>>& a,
    std::vector<std::vector<long long>>& t, int i, int j) {
	if (a[i][j]==a[i][j+1] && a[i][j]==a[i+1][j] && a[i][j]==a[i+1][j+1])
		t[i][j] = 1+std::min({t[i+1][j], t[i][j+1], t[i+1][j+1]});
}

int main() {
	int n, k;
	std::string s;
	std::cin >> n >> k;
	std::vector<std::vector<char>> a(n, std::vector<char>(n));
	std::vector<std::vector<long long>> t(n, std::vector<long long>(n, 1));
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		for (int j = 0; j < n; j++)
			a[i][j] = s[j];
	}

	for (int d = n-2; d >= 0; d--) {
		for (int i = d; i >= 0; i--) {
			fill(a, t, i, d);
			fill(a, t, d, i);
		}
	}

	std::vector<long long> sol(k, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sol[a[i][j]-'A'] += t[i][j];

	for (auto x : sol)
		std::cout << x << "\n";
}
