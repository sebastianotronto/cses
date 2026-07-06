#include <algorithm>
#include <iostream>
#include <vector>

constexpr size_t inf = 1999999999;

class SegmentTree {
public:
	SegmentTree(size_t n) : m{pow2ceil(n)}, v(2*m, inf) {}

	void update(size_t i, size_t x) {
		v[m+i-1] = x;
		for (size_t p = (m+i-1)/2; p > 0; p /= 2)
			v[p] = std::min(v[2*p], v[2*p+1]);
	}

	size_t min(size_t a, size_t b) { return q(a-1, b, 1, 0, m); }

private:
	size_t m;
	std::vector<size_t> v;
	static constexpr size_t pow2ceil(size_t x) {
		size_t c;
		for (c = 1; c < x; c *= 2) ;
		return c;
	}

	size_t q(size_t a, size_t b, size_t i, size_t l, size_t r) {
		if (a == l && b == r) return v[i];
		size_t p{(l+r)/2}, s{inf};
		if (a < p) s = std::min(s, q(a, std::min(b, p), 2*i, l, p));
		if (b > p) s = std::min(s, q(std::max(a, p), b, 2*i+1, p, r));
		return s;
	}
};

int main() {
	size_t n, q;
	std::cin >> n >> q;
	SegmentTree t(n);
	for (size_t i = 0; i < n; i++) {
		size_t x;
		std::cin >> x;
		t.update(i+1, x);
	}
	for (size_t i = 0; i < q; i++) {
		int u, a, b;
		std::cin >> u >> a >> b;
		if (u == 1)
			t.update(a, b);
		else
			std::cout << t.min(a, b) << "\n";
	}
}
