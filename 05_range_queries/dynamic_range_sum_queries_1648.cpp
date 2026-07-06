#include <algorithm>
#include <iostream>
#include <vector>

class SumFenwickTree {
public:
	SumFenwickTree(int n) : a(n+1) {}
	long long sum(int l, int r) const { return psum(r) - psum(l-1); }
	void update(int k, long long u) { add(k, u - sum(k, k));}

private:
	std::vector<long long> a;

	static int lsb(int i) { return i & -i; }

	long long psum(int i) const {
		long long s = 0;
		while (i > 0) {
			s += a[i];
			i -= lsb(i);
		}
		return s;
	}

	void add(int k, long long d) {
		while (k < (int)a.size()) {
			a[k] += d;
			k += lsb(k);
		}
	}
};

int main() {
	size_t n, q;
	std::cin >> n >> q;
	SumFenwickTree t(n);
	for (size_t i = 0; i < n; i++) {
		long long x;
		std::cin >> x;
		t.update(i+1, x);
	}
	for (size_t i = 0; i < q; i++) {
		long long x, k, u;
		std::cin >> x >> k >> u;
		if (x == 1)
			t.update(k, u);
		else
			std::cout << t.sum(k, u) << "\n";
	}
}
