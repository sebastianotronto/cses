#include <algorithm>
#include <iostream>

bool inran(long long int a, long long int b, long long int m) {
	return m >= std::min(a, b) && m <= std::max(a, b);
}

bool inseg(long long int d, long long int dt, long long int du) {
	return dt >= 0 && dt <= d && du >= 0 && du <= d;
}

bool f(long long int x1, long long int y1, long long int x2, long long int y2,
    long long int x3, long long int y3, long long int x4, long long int y4) {
	long long int xt = x2-x1, yt = y2-y1;
	long long int xu = x4-x3, yu = y4-y3;
	long long int d = xt * (-yu) - yt * (-xu);
	long long int dt = (x3-x1) * (-yu) - (y3-y1) * (-xu);
	long long int du = (xt) * (y3-y1) - (yt) * (x3-x1);

	if (d == 0) {
		// Parallel on different lines
		if (dt != 0 || du != 0) return false;

		// Parallel, same line
		return xt == 0 ? 
		    inran(y1,y2,y3) || inran(y1,y2,y4) || inran(y3,y4,y1) :
		    inran(x1,x2,x3) || inran(x1,x2,x4) || inran(x3,x4,x1);
	} else {
		// Not parallel
		long long int m = d > 0 ? 1 : -1;
		return inseg(m*d, m*dt, m*du);
	}
}

int main() {
	long long int x1, y1, x2, y2, x3, y3, x4, y4;
	int n;
	std::cin >> n;
	while (std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
		std::cout << (f(x1,y1,x2,y2,x3,y3,x4,y4) ? "YES\n" : "NO\n");
}
