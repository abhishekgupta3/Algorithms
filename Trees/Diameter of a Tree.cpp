#include <bits/stdc++.h>
using namespace std;

int ans;
void dfs(vector<int> g[], int dp[], int src, bool vis[], int par) {
    vis[src] = 1;

    int a = 0, b = 0;
    for(auto x: g[src]) {
        if(x == par)continue;
        if(!vis[x]) dfs(g, dp, x, vis, src);
        if(dp[x] >= a) b = a, a = dp[x];
        else if(dp[x] > b) b = dp[x];
    }
    ans = max(ans, a + b);
    dp[src] = a + 1;
}

int main() {
    int n; cin >> n;
    vector<int> g[n];

    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    int dp[n]{0};
    bool vis[n]{0};
    dfs(g, dp, 0, vis, -1);
    cout << ans;

    return 0;
}