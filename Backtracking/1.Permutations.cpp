// Permutations of a String

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

	string s; cin >> s;
	permute(s, 0);

	return 0;
}