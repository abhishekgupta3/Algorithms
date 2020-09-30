/* 
**  CODE FOR LINEAR  SEARCH 
*/
#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=int (a);i<int (n);i++)
using namespace std;
typedef long long ll ;

int main(){
//testcases
int t=1; //cin>>t; 

while(t--)
{
	ll n,val;cin>>n>>val;
	ll ar[n];
  bool flag=0;
	rep(i,0,n)cin>>ar[i];
	rep(i,0,n){
  if(ar[i]==val){
  flag=1;break;
  }
  }if(flag)cout<<"Found";
  else cout<<"Not Found";
	
	cout<<endl;
}

}
