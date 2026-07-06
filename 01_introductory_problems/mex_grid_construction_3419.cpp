#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

int firstzero(const std::bitset<200>& b) {
	for (int i = 0; i < 200; i++)
		if (!b.test(i))
			return i;
	return -1;
}

int next(int i, int j, std::vector<std::bitset<200>>& col,
    std::vector<std::bitset<200>>& row) {
	int r = firstzero(row[i] | col[j]);
	row[i][r] = col[j][r] = 1;
	return r;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::bitset<200>> col(n), row(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cout << next(i, j, col, row) << " ";
		std::cout << "\n";
	}
}
