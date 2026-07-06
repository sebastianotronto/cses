#include <iostream>
#include <vector>

int f(const std::vector<std::vector<int>>& a, std::vector<int>& b, int i) {
	for (auto x : a[i]) 
		b[i] += f(a, b, x) + 1;
	return b[i];
}

int main() {
	int n, x;
	std::cin >> n;
	std::vector<std::vector<int>> a(n);
	for (int i = 1; i < n; i++) {
		std::cin >> x;
		a[x-1].push_back(i);
	}
	std::vector<int> b(n, 0);
	f(a, b, 0);
	for (auto y : b)
		std::cout << y << " ";
	std::cout << std::endl;
}
