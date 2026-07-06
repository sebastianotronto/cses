#include <iostream>
#include <queue>
#include <ranges>
#include <string>
#include <tuple>
#include <vector>

struct Pos {
	size_t i;
	size_t j;

	Pos(size_t a = 0, size_t b = 0) : i{a}, j{b} {}
	bool operator==(const Pos& p) const { return i == p.i && j == p.j; }

	std::vector<Pos> neighbors() const {
		return {Pos(i+1, j), Pos(i-1, j), Pos(i, j+1), Pos(i, j-1)};
	}

	char dir(const Pos& p) const {
		if (p.i == i+1 && p.j == j) return 'D';
		if (p.i == i-1 && p.j == j) return 'U';
		if (p.i == i && p.j == j+1) return 'R';
		if (p.i == i && p.j == j-1) return 'L';
		return 'X';
	}
};
 
class Map {
public:
	Map(size_t i, size_t j) : n{i}, m{j}, v(n, std::vector<bool>(m)) {}
	Pos start() const { return a; }
	Pos finish() const { return b; }
	bool operator[](Pos p) const { return inb(p) && v[p.i][p.j]; }

	friend std::istream& operator>>(std::istream& is, Map& map) {
		std::string s;
		is >> s;
		for (size_t j = 0; j < map.m; j++)
			map.readchar(s[j], map.l, j);
		map.l++;
		return is;
	}
 
	friend std::ostream& operator<<(std::ostream& os, const Map& map) {
		for (size_t i = 0; i < map.n; i++) {
		 	for (size_t j = 0; j < map.m; j++) {
				if (map.a == Pos(i, j)) os << 'A';
				else if (map.b == Pos(i, j)) os << 'B';
				else os << (map.v[i][j] ? '.' : '#');
			}
			os << "\n";
		}
		return os;
	}

	template<typename T>
	using Overlay = std::pair<T, std::vector<std::vector<T>>>;

	template<typename T>
	Overlay<T> overlay(T t) const {
		auto ov = std::vector<std::vector<T>>(n, std::vector(m, t));
		return {t, ov};
	}

	template<typename T>
	T at(const Overlay<T>& ov, Pos p) const {
		return inb(p) ? ov.second[p.i][p.j] : ov.first;
	}

	template<typename T>
	void set(Overlay<T>& ov, Pos p, T val) const {
		if (inb(p)) ov.second[p.i][p.j] = val;
	}
private:
	size_t l{0};
	size_t n;
	size_t m;
	Pos a;
	Pos b;
	std::vector<std::vector<bool>> v;
 
	void readchar(char c, size_t i, size_t j) {
		v[i][j] = c != '#';
		if (c == 'A') a = {i, j};
		if (c == 'B') b = {i, j};
	}
 
	bool inb(Pos p) const { return p.i < n && p.j < m; }
};

int main() {
	size_t n, m;
	std::cin >> n >> m;
	Map map(n, m);
	for (size_t i = 0; i < n; i++)
		std::cin >> map;

	constexpr size_t inf{999999999};
	auto d = map.overlay<size_t>(inf);
	std::queue<std::pair<Pos, size_t>> q;
	q.push({map.start(), 0});
	while (!q.empty()) {
		auto [p, w] = q.front();
		q.pop();
		if (!map[p] || map.at(d, p) != inf) continue;
		map.set(d, p, w);
		for (auto x : p.neighbors()) q.push({x, w+1});
	}

	if (map.at(d, map.finish()) == inf) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n" << map.at(d, map.finish()) << "\n";

		// Backtrack
		Pos p = map.finish(); 
		std::vector<char> path;
		do {
			for (auto x : p.neighbors()) {
				if (map.at(d, x) == map.at(d, p)-1) {
					path.push_back(x.dir(p));
					p = x;
					break;
				}
			}
		} while (p != map.start());
		for (auto c : path | std::views::reverse)
			std::cout << c;
		std::cout << "\n";
	}
}
