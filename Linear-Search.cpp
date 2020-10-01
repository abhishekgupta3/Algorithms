/* 
**  CODE FOR LINEAR  SEARCH 
*/
#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = int(a); i < int(n); i++)
using namespace std;
typedef long long ll;

int main()
{
    //Test cases
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, val;
        cin >> n >> val;
        vector<int>arr;
        //Assuming the element dosen't exist
        bool flag = 0;
        int data;
        rep(i, 0, n)
        {
            cin >> data;
            arr.push_back(data);
        }
        rep(i, 0, n)
        {
            if (arr[i] == val)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "Found";
        else
            cout << "Not Found";

        cout << endl;
    }
}
