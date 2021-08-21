#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cstring>
#include <climits>
#include <utility>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#define rep(i,a,n)  for(int i = int(a); i < int(n); ++i)
#define FAST        ios :: sync_with_stdio(0); cin.tie(0);
#define PI          3.1415926535897932384626
#define mem(a,b)    memset((a), (b), sizeof(a))
#define all(x)      x.begin(), x.end()
#define sz(x)       ((int)x.size())
#define vii         vector<pair<int, int>>
#define vll         vector<pair<ll, ll>>
#define vi          vector<int>
#define vl          vector<ll>
#define pii         pair<int, int>
#define pll         pair<ll, ll>
#define mii         map<int, int>
#define mll         map<ll, ll>
#define ld          long double
#define yes         cout << "YES"
#define no          cout << "NO"
#define nl          cout << "\n"
#define eb          emplace_back
#define pb          push_back
#define ll          long long
#define ss          second
#define ff          first
using namespace std;

//**************************************** CODE STARTS HERE ***************************************
 
void solve(){
    ll n, m; cin >> n >> m;
    vl arr(n + 1); rep(i, 1, n + 1) cin >> arr[i]; 
    vl pre(n + 1, 0);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + arr[i];
 
    while(m--) {
        ll a, b; cin >> a >> b;
        cout << pre[b] - pre[a - 1];
        nl;
    }
 
}
 
int main() {
    FAST;
    int t = 1, tt = 1; 
    // cin >> t; 
 
    while (t--) {
        solve();
        cout << '\n';
    }
 
    return 0;
}