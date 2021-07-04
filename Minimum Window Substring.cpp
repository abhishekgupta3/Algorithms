// Minimum Window Substring: Find the smallest window in S consisting of all the characters of P
// *********************************************************************************************
#include<bits/stdc++.h>
using namespace std;

string smallestWindow (string s, string p, int n, int m) {

    int fp[26] = {0}, fs[26] = {0};

    for (int i = 0; i < m; i++)fp[p[i] - 'a']++;

    int ans = INT_MAX, cnt = 0, j = 0, idx = -1;

    for (int i = 0; i < n; i++) {
        fs[s[i] - 'a']++;

        // matching characters of s with pat
        if (fp[s[i] - 'a'] > 0 and fs[s[i] - 'a'] <= fp[s[i] - 'a']) {
            cnt++;
        }
        // all charcters matched
        if (cnt == m) {
            // shrinking the window, removing all unwanted characters
            while (fp[s[j] - 'a'] == 0 or fs[s[j] - 'a'] > fp[s[j] - 'a']) {
                fs[s[j] - 'a']--;
                j++;
            }

            if (i - j + 1 < ans) {
                ans = i - j + 1;
                idx = j;
            }
        }
    }

    string res = s.substr(idx, ans);
    return res;
}

int main() {
    string s, pat; cin >> s1 >> pat;
    int n = s.length(), m = pat.length();
    cout << smallestWindow(s, pat, n, m);

    return 0;
}
