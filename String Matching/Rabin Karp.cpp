// Rabin Karp
// ----------------------------
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define p 31 // prime number

// a*p^3 + b*p^2 + c*p^1 + d*p^0
ll hash_function(string s, int n) {
    ll hash = 0, prime = 1;

    for (int i = n - 1; i >= 0; i--) {
        hash += (s[i] - 'a' + 1) * prime;
        prime = (prime * p);
    }

    return hash;
}

// Worst case O(N*M)
void rabinKarp(string text, string pat, int n, int m) {
    ll pat_hash = hash_function(pat, m);
    ll text_hash = hash_function(text, m);

    for (int i = 0; i + m <= n; ++i) {

        // if text and pattern hash are equal,check for each character
        if (text_hash == pat_hash) {
            bool flag = 0;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pat[j]) {
                    flag = 1; break;
                }
            }
            if (!flag)cout << i << " ";
        }

        // next hash of text using Rolling Hash
        if (i < n - m) text_hash = (p * (text_hash) - (text[i] - 'a' + 1) * pow(p, m) + (text[i + m] - 'a' + 1) * 1);
    }
}

int32_t main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string text, pattern; cin >> text >> pattern;
    int n = text.length(), m = pattern.length();
    rabinKarp(text, pattern, n, m);

    return 0;
}