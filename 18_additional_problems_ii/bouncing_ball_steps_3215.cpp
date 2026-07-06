#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>

typedef long long ll;

std::tuple<ll, ll, ll> f(ll n, ll m, ll k) {
	n--; m--;
	ll am{k % (2*n)}, ad{k / n}, bm{k % (2*m)}, bd{k / m};
	if (am > n) am = n - (am-n);
	if (bm > m) bm = m - (bm-m);
	return {am, bm, ad+bd-k/std::lcm(n, m)};
}

int main() {
	ll t, n, m, k;
	std::cin >> t;
	for (ll i = 0; i < t; i++) {
		std::cin >> n >> m >> k;
		auto [a, b, c] = f(n, m, k);
		std::cout << a+1 << " " << b+1 << " " << c << "\n";
	}
}
