#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define OUT  freopen("output.txt", "w", stdout)
#define IN  freopen("input.txt", "r", stdin)
#define mem(a,b) memset((a),(b),sizeof(a))
#define NumofDigits(n) ((int)log10(n)+1)
#define NumofBits(n) ((int)log2(n)+1)
#define PI 3.14159265358979323846264
#define vii vector<pair<int,int>>
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi  vector<ll>
#define nl  cout<<"\n"
#define pb  push_back
#define mp  make_pair
#define ll  long long 
#define ss  second 
#define ff  first
#define endl "\n"
#define sp  " "
using namespace std;

int main(){
FAST;
int t=1; cin>>t;
while(t--)
{
 
 int n,c;cin>>n>>c;
 
 if(n<=2)cout<<"1";
 else{
 	n-=2;
 	if(n%c==0)cout<<1+n/c;
 	else cout<<2+n/c;
 }
 
 nl;
}

}
