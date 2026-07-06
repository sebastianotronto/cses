#include <iostream>
#include <limits>
#include <vector>

int minrange(std::vector<int>& a, int x, int y, int i, int p, int l, int r) {
	if (x == l && y == r)
		return a[2*p-2-i];

	if (x >= y)
		return std::numeric_limits<int>::max();

	int lr = (l+r)/2;
	return std::min(
	    minrange(a, std::max(x, l), std::min(y, lr), 2*i+2, p, l, lr),
	    minrange(a, std::max(x, lr), std::min(y, r), 2*i+1, p, lr, r)
	);
}

void compute_mins(std::vector<int>& a, int j, int n) {
	for (int i = 0; i < n; i += 2)
		a[j+n+i/2] = std::min(a[j+i], a[j+i+1]);
}

int main() {
	int n, q, x, y, p;
	std::cin >> n >> q;

	// For simplicity, extend n to a power of 2
	for (p = 1; p < n; p <<= 1) ;

	std::vector<int> a(2*p-1, 0);
	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	// a[p], a[p+1] ... a[p+p/2-1] are min of pairs
	// a[p+p/2], a[p+p/2+1], ... a[p+p/2+p/4] are min of quads
	// etc...
	for (int i = 1, j = 0; i < p; i <<= 1) {
		compute_mins(a, j, p/i);
		j += p/i;
	}

	for (int i = 0; i < q; i++) {
		std::cin >> x >> y;
		std::cout << minrange(a, x-1, y, 0, p, 0, p) << "\n";
	}
}
