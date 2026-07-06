#include <bitset>
#include <iostream>
#include <string>

void set_bit(std::bitset<64>& r, int i, int j) {
	if (i >= 0 && i < 8 && j >= 0 && j < 8)
		r |= 1ULL << (unsigned long long)(8*i + j);
}

std::bitset<64> maskall(const std::bitset<64>& b, int i, int j) {
	std::bitset<64> r{b};
	r |= 0x0101010101010101ULL << (unsigned long long)j;
	for (int k = 0; k < 8; k++) {
		set_bit(r, k, k+j-i);
		set_bit(r, k, -k+j+i);
	}
	return r;
}

long long f(std::bitset<64>& b, int i) {
	if (i == 8)
		return 1;
	long long s{0};
	for (int j = 0; j < 8; j++) {
		if (!b[8*i+j]) {
			auto rr = maskall(b, i, j);
			s += f(rr, i+1);
		}
	}
	return s;
}

int main() {
	std::bitset<64> b{0};
	std::string s;
	for (int i = 0; i < 8; i++) {
		std::cin >> s;
		for (int j = 0; j < 8; j++)
			b[8*i+j] = s[j] == '*';
	}
	std::cout << f(b, 0) << "\n";
}
