#include <iostream>
#include <vector>

// Recurrence relation:
// f(n) = sum over i from 0 to n-1 of f(i) * p(n-i) 
// where p(n) is the number of indivisible towers of height n,
// which is easily seen to be 3^(n-1)+1.
// Then we can expand:
// f(n) = sum_{i=0}^{n-1} f(i)(3^{n-i-1}+1) = g(n) + h(n)
// where we define g(n) = sum f(i)3^{n-i-1} and h(n) = sum f(i).
// Then it's easy to see that:
//   g(n+1) = f(n) + 3g(n)
//   h(n+1) = f(n) + h(n)
// Initial values are h(1) = 1 and g(1) = 1.

constexpr size_t mod{1000000007};
constexpr size_t maxn{1000001};
std::vector<size_t> f(maxn);
std::vector<size_t> g(maxn);
std::vector<size_t> h(maxn);

int main() {
	g[1] = h[1] = 1;
	f[1] = 2;
	for (size_t i = 2; i < maxn; i++) {
		g[i] = (f[i-1] + 3*g[i-1]) % mod;
		h[i] = (f[i-1] + h[i-1]) % mod;
		f[i] = (g[i] + h[i]) % mod;
	}

	size_t t;
	std::cin >> t;
	for (size_t i = 0; i < t; i++) {
		size_t n;
		std::cin >> n;
		std::cout << f[n] << "\n";
	}
}
