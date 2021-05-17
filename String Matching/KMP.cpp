// KMP
// =========================================
#include <bits/stdc++.h>
using namespace std;

// Longest Proper Prefix which is also a suffix
int* LPS(string s, int n) {
	int *lps = new int[n];
	lps[0] = 0;
	int j = 0, i = 1;
	while (i < n) {
		if (s[i] == s[j])lps[i] = j + 1, i++, j++;
		else {
			if (j == 0)lps[i] = 0, i++;
			else j = lps[j - 1];
		}
	}

	return lps;
}

// T.C: O(n + m)
bool kmp(string txt, string pat, int n, int m) {
	int i = 0, j = 0;
	int *lps = LPS(pat, m);
	while (i < n and j < m) {
		if (txt[i] == pat[j])i++, j++;
		else {
			if (j == 0)i++;
			else j = lps[j - 1];
		}
	}
	// reached end
	if (j == m)return true;

	return false;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string text, pattern;
	cin >> text >> pattern;
	int n = text.length(), m = pattern.length();
	cout << kmp(text, pattern, n, m);

	return 0;
}