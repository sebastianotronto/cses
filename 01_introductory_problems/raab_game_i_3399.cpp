#include <iostream>
#include <utility>
#include <vector>

class Game {
public:
	bool y;
	std::vector<int> a;
	std::vector<int> b;
	int apts = 0;
	int bpts = 0;

	Game(int n, bool w)
	    : y{w}, a{std::vector<int>(n)}, b{std::vector<int>(n)} {}

	void play(int i, int j) {
		this->a[this->next] = i;
		this->b[this->next] = j;
		this->apts += i > j;
		this->bpts += j > i;
		this->next++;
	}

	friend std::ostream& operator<<(std::ostream& os, const Game g) {
		if (!g.y) {
			os << "NO\n";
		} else {
			os << "YES\n";
			for (auto x : g.a)
				os << x << " ";
			os << "\n";
			for (auto x : g.b)
				os << x << " ";
			os << "\n";
		}
		return os;
	}
private:
	int next = 0;
};

Game play(int n, int a, int b) {
	if (a + b > n)
		return Game(1, false);

	Game g(n, true);
	for (int i = 0; i < n - (a+b); i++)
		g.play(i+1, i+1);
	for (int i = 0; i < a; i++)
		g.play(n-a+i+1, n-(a+b)+i+1);
	for (int i = 0; i < b; i++)
		g.play(n-(a+b)+i+1, n-b+i+1);

	if (g.apts != a || g.bpts != b)
		g.y = false;

	return g;
}

int main() {
	int n, a, b, t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> n >> a >> b;
		std::cout << play(n, a, b);
	}
}
