#include <iostream>

struct Point {
	long long x;
	long long y;
	Point operator-(const Point& p) const { return Point{x-p.x, y-p.y}; }
	long long operator*(const Point& v) { return x * v.y - y * v.x; }
};

int main() {
	int t;
	Point a, b, c;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
		auto v = (b-a)*(c-a);
		if (v > 0) std::cout << "LEFT\n";
		else if (v < 0) std::cout << "RIGHT\n";
		else std::cout << "TOUCH\n";
	}
}
