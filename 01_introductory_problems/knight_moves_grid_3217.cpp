#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

struct Node {
	int i;
	int j;
	int d;
};

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> a(n, std::vector<int>(n, 1e7));
	std::queue<Node> q;

	q.push(Node{0, 0, 0});
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		if (v.i < 0 || v.j < 0 || v.i >= n || v.j >= n || a[v.i][v.j] <= v.d)
			continue;
		a[v.i][v.j] = v.d;
		q.push(Node{v.i-2, v.j-1, v.d+1});
		q.push(Node{v.i-2, v.j+1, v.d+1});
		q.push(Node{v.i-1, v.j-2, v.d+1});
		q.push(Node{v.i-1, v.j+2, v.d+1});
		q.push(Node{v.i+2, v.j-1, v.d+1});
		q.push(Node{v.i+2, v.j+1, v.d+1});
		q.push(Node{v.i+1, v.j-2, v.d+1});
		q.push(Node{v.i+1, v.j+2, v.d+1});
	}

	for (auto& v : a) {
		for (auto& x : v)
			std::cout << x << " ";
		std::cout << "\n";
	}
}
