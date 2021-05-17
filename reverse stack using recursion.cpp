#include <bits/stdc++.h>
#define rep(i,a,n)  for(int i = int(a); i < int(n); i++)
#define FAST        ios::sync_with_stdio(0); cin.tie(0);
#define PI          3.1415926535897932384626
#define mem(a,b)    memset((a), (b), sizeof(a))
#define vii         vector<pair<int,int>>
#define vll         vector<pair<ll,ll>>
#define all(x)      x.begin(),x.end()
#define pii         pair<int,int>
#define ld          long double
#define pll         pair<ll,ll>
#define yes 		cout<<"YES"
#define no 			cout<<"NO"
#define vi          vector<ll>
#define nl          cout<<"\n"
#define pb          push_back
#define mp          make_pair
#define ll          long long
#define ss          second
#define ff          first
#define endl        "\n"
#define sp          " "
using namespace std;
const int mod = 1000000007;

ll gcd(ll a, ll b) {
	if (!b)return a;
	return gcd(b, a % b);
}

ll lcm(ll a , ll b) {
	return (a * b) / gcd(a, b);
}

//**************************************** CODE STARTS HERE ***************************************

void at_last(stack<int>s , int f) {
	if (s.size() == 0) {s.push(f); return;}
	int temp = s.top();
	s.pop();
	at_last(s, f);
	s.push(temp);
}

void reverse(stack<int> s) {
	if (s.size() == 0)return;
	int f = s.top(); s.pop();
	reverse(s);
	at_last(s, f);

}

int main() {
	FAST;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1; cin >> t;
	while (t--) {
		stack<int> s;
		s.push(1); s.push(2); s.push(3); s.push(4);
		reverse(s); // O(N^2)
		while (s.empty() == false) {
			cout << s.top(); s.pop(); nl;
		}

	}

	return 0;

}