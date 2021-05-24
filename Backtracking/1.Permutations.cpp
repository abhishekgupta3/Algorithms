#include <bits/stdc++.h>
using namespace std;

void permute(string s, int i) {
	// base case
	if (i == s.length()) {
		cout << s << " ";
		return;
	}

	for (int j = i; j < s.length(); ++j) {
		swap(s[j], s[i]);
		permute(s, i + 1);
		swap(s[j], s[i]); // backtrack...
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s; cin >> s;
	permute(s, 0);

	return 0;
}