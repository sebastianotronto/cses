#include <iostream>
#include <queue>
#include <string>
#include <string_view>
#include <vector>

struct TrieNode {
	char c;
	size_t d;
	bool isend;
	std::vector<TrieNode> next;

	TrieNode(char x, size_t y) : c{x}, d{y}, isend{false}, next() {}
};

void push(std::string_view s, TrieNode& t) {
	if (s.empty()) {
		t.isend = true;
		return;
	}
	for (auto& u : t.next) {
		if (s[0] == u.c) {
			push(s.substr(1), u);
			return;
		}
	}
	t.next.push_back(TrieNode(s[0], t.d+1));
	push(s.substr(1), t.next.back());
}

const TrieNode* next(const TrieNode* w, char c) {
	for (size_t i = 0; i < w->next.size(); i++)
		if (w->next[i].c == c)
			return &w->next[i];
	return nullptr;
}

int f(std::vector<int>& t, std::string_view s, const TrieNode& d, size_t i) {
	static constexpr long long mod = 1e9+7;

	if (t[i] != -1) return t[i];

	t[i] = 0;
	for (const TrieNode* w = &d; w != nullptr; w = next(w, s[w->d]))
		if (w->isend)
			t[i] = (t[i] + f(t, s.substr(w->d), d, i+w->d)) % mod;
	return t[i];
}

int main() {
	std::string s, u;
	size_t k;
	std::cin >> s >> k;
	TrieNode d('\0', 0);
	for (size_t i = 0; i < k; i++) {
		std::cin >> u;
		push(u, d);
	}

	std::vector<int> t(s.size()+1, -1);
	t[s.size()] = 1;
	std::cout << f(t, s, d, 0) << "\n";
}
