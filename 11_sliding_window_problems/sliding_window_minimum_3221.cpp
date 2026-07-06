#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

int main() {
	long long n, k, x, a, b, c;
	std::cin >> n >> k >> x >> a >> b >> c;

	std::vector<long long> v(k);
	std::deque<long long> q;
	for (long long i = 0; i < k; i++) {
		v[i] = x;
		while (!q.empty() && q.back() >= x) q.pop_back();
		q.push_back(x);
		x = (a*x + b) % c;
	}

	long long sol = q.front();
	for (long long i = 0; i < n-k; i++) {
		if (q.front() == v[i%k]) q.pop_front();
		v[i%k] = (a*v[(i-1+k)%k] + b) % c;
		while (!q.empty() && q.back() >= v[i%k]) q.pop_back();
		q.push_back(v[i%k]);
		sol ^= q.front();
	}

	std::cout << sol << "\n";
}
