#include <iostream>
#include <string>
#include <vector>

class Tile {
public:
	int i;
	int j;
	std::vector<Tile> neighbors() const {
		return {Tile{i-1,j}, Tile{i+1,j}, Tile{i,j-1}, Tile{i,j+1}};
	}
};

class Map {
public:
	int n;
	int m;

	Map(int i, int j) : n{i}, m{j}, c(n*m, 0) {}
	int color(Tile t) const { return inbound(t) ? c[ind(t)] : -1; }
	void setcolor(Tile t, int k) { if (inbound(t)) c[ind(t)] = k; }
	bool wall(Tile t) const { return !inbound(t) || c[ind(t)] == -1; }
	void setwall(Tile t) { if (inbound(t)) setcolor(t, -1); }
private:
	std::vector<int> c;

	size_t ind(Tile t) const { return m*t.i + t.j; }
	bool inbound(Tile t) const {
		return t.i >= 0 && t.i < n && t.j >= 0 && t.j < m;
	}
};

Map readmap() {
	int n, m;
	std::string s;
	std::cin >> n >> m;
	Map map(n, m);
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		for (int j = 0; j < m; j++)
			if (s[j] == '#')
				map.setwall(Tile{i, j});
	}
	return map;
}

void visit(Map& m, Tile t, int c) {
	m.setcolor(t, c);
	for (auto u : t.neighbors())
		if (m.color(u) == 0)
			visit(m, u, c);
}

int main() {
	auto m = readmap();
	int c{0};
	for (int i = 0; i < m.n; i++)
		for (int j = 0; j < m.m; j++)
			if (m.color(Tile{i, j}) == 0)
				visit(m, Tile{i, j}, ++c);
	std::cout << c << "\n";
}
