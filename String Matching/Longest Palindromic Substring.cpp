#include <bits/stdc++.h>
using namespace std;

// T.C: O(n^2)
string longestPalindrome(string s, int n) {
    int l, r, cur, idx;
    int ans = 0;
    for (int i = 0; i < n; i++) {

        // odd length
        l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            cur = r - l + 1;
            if (cur > ans)ans = cur, idx = l;
            l--, r++;
        }

        // even length
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            cur = r - l + 1;
            if (cur > ans)ans = cur, idx = l;
            l--, r++;
        }
    }

    return s.substr(idx, ans);
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s; cin >> s;
    int n = s.length();
    cout << "longest Palindrome is " << longestPalindrome(s, n);

}