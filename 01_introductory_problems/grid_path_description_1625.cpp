#include <algorithm>
#include <bitset>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

/*
The official solution uses the heuristic: if both adjacent squares
in horizontal direction are visited or wall, and both in vertical direction
are not visited (or the other way round), then we stop because we borked
the square. I did not think of this criterion, so to check if the square
is borked I do a full visit from the bottom-left corner. This is too slow,
so I do this only at depths 10, 20, 30 and 40. This is good enough.
*/

class Tile {
public:
	int i;
	int j;

	bool valid() const { return i >= 0 && i < 7 && j >= 0 && j < 7; }
	bool end() const { return i == 6 && j == 0; }
	bool operator==(const Tile& t) const { return i == t.i && j == t.j; }
	Tile u() const { return Tile{i-1, j}; }
	Tile d() const { return Tile{i+1, j}; }
	Tile l() const { return Tile{i, j-1}; }
	Tile r() const { return Tile{i, j+1}; }
	static Tile err() { return Tile{-1, -1}; }

	Tile move(char c) const {
		if (c == 'U') return u();
		if (c == 'D') return d();
		if (c == 'L') return l();
		if (c == 'R') return r();
		return err();
	}

	std::vector<Tile> neighbors() const {
		return std::vector { u(), d(), l(), r() };
	}
};

class Map {
public:
	Map() : b(), v(49, 4) {
		for (int i = 0; i < 7; i++) {
			v[index(Tile{i, 0})]--;
			v[index(Tile{i, 6})]--;
			v[index(Tile{0, i})]--;
			v[index(Tile{6, i})]--;
		}
	}

	bool visited(Tile t) const {
		return !t.valid() || b.test(index(t));
	}

	void set(Tile t) {
		if (!t.valid()) return;
		b.set(index(t));
		for (auto u : t.neighbors())
			if (u.valid())
				v[index(u)]--;
	}

	void reset(Tile t) {
		if (!t.valid()) return;
		b.reset(index(t));
		for (auto u : t.neighbors())
			if (u.valid())
				v[index(u)]++;
	}

	std::vector<Tile> locked_neighbors(Tile t) const {
		std::vector<Tile> r{};
		for (auto u : t.neighbors())
			if (locked(u))
				r.push_back(u);
		return r;
	}

	int count() const { return b.count(); }

	bool borked() const {
		std::bitset<49> vv{};
		std::queue<Tile> q;
		q.push(Tile{6, 0});
		vv.set(index(Tile{6, 0}));
		int c{1};
		while (!q.empty()) {
			Tile t = q.front();
			q.pop();
			for (auto u : t.neighbors()) {
				if (!visited(u) && !vv.test(index(u))) {
					vv.set(index(u));
					c++;
					q.push(u);
				}
			}
		}

		return c + count() < 49;
	}

private:
	std::bitset<49> b;
	std::vector<int> v;
	static int index(Tile t) { return 7*t.i + t.j; }

	bool locked(Tile t) const {
		return t.valid() && !visited(t) && !t.end() && v[index(t)] < 2;
	}
};

int f(Map& m, const std::string& s, size_t n, Tile t) {
	if (n == 48) return t.end();
	if (m.visited(t) || t.end()) return 0;

	m.set(t);
	if (n % 10 == 0 && m.borked()) {
		m.reset(t);
		return 0;
	}

	auto ln = m.locked_neighbors(t);

	int r{0};
	if (s[n] != '?') {
		Tile nt = t.move(s[n]);
		if (ln.size() == 0 || (ln.size() == 1 && ln[0] == nt))
			r = f(m, s, n+1, nt);
	} else {
		if (ln.size() == 0)
			r = f(m, s, n+1, t.u()) + f(m, s, n+1, t.d())
			  + f(m, s, n+1, t.l()) + f(m, s, n+1, t.r());
		if (ln.size() == 1)
			r = f(m, s, n+1, ln[0]);
	}

	m.reset(t);
	return r;
}

int main() {
	Map m;
	std::string s;
	std::cin >> s;
	std::cout << f(m, s, 0, Tile{0, 0}) << "\n";
}
