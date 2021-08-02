/*####Mo's Algo#####*/
#include <bits/stdc++.h>
using namespace std;
#define int long long int
typedef vector<int> vi;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define sz(a) (int)((a).size())
#define sq(x) ((x) * (x))
const int N = 2e5 + 5;
int n, block = 555;
int cnt[(int)2e6 + 1], ans;
int a[N];
template <typename T>

class Graph{
    unordered_map<T, list<T, list<pair<T, int>>> m;
public:
    void addEdge(T u, T v, int dist, bool bidir = true){
        m[u].push_back(make_pair(v , dist));
        if(bidir){
            m[v].push_back(make_pair(u, dist));
        }
    }
    void printAdj(){
        //Lets try to print the adj list
        //Iterate over all the key value pair in the map
        for(auto j : m){
            cout<<j.first<<"->";
            //Iterate over the list of cities
            for(auto l : j.second){
                cout<<"("<<l.first<<", "<<l.second<<")";
            }
            cout<<endl;
        }
    }
    void dijsktraSSSP(T src){
        unordered_map<T, int> dist;
        //Set all distance to infinity
        for(auto j : m){
            dist[j.first] = INT_MAX;
        }
        //Make a set to find all nodes with minimum distance
        set<pair<int , T>>s;
        //Insert the source node init
        dist[src] = 0;
        s.insert(make_pair(0, src));
        while(!s.empty()){
            //Find the first pair
            auto p = *(s.begin());
            T node = p.second;
            T nodeDist = p.first;
            s.erase(s.begin());
            //Iterate over nbr of current node
            for(auto childPair : m[node]){
                //Update the distance
                if(nodeDist+childPair.second < dist[childPair.first]){
                    //We need to update the set
                    //We will do this by removing the old pair and inserting the new pair


                    //Finding the required node inside the set
                    T dest = childPair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f!=s.end()){
                        s.erse(f);
                    }

                    //Insert the new pair inside the set
                    dist[dest] = nodeDist+childPair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
    }
};

struct pt
{
    int l;
    int r;
    int id;
};
bool comp(pt &x, pt &y)
{
    // Sorting via sqrt decomposition
    if (x.l / block != y.l / block)
        return x.l / block < y.l / block;
    return x.r < y.r;
}
int counter;
int cur_l, cur_r;
void add(int pos)
{
    cnt[a[pos]]++;
    // Condition for change in answer
    ans += (sq(cnt[a[pos]]) - sq(cnt[a[pos]] - 1)) * (a[pos]);
}
void del(int pos)
{
    cnt[a[pos]]--;
    // Condition for change in answer
    ans += (sq(cnt[a[pos]]) - sq(cnt[a[pos]] + 1)) * (a[pos]);
}
int32_t main()
{   int n;          
    cin >>n;
    int Q;
    cin >> Q;
    block = sqrt(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pt> v;
    v.resize(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> v[i].l >> v[i].r;
        v[i].l--, v[i].r--;
        v[i].id = i;
    }
    sort(all(v), comp);
    ans = cur_l = cur_r = 0;
    vi res(Q);
    for (int i = 0; i < Q; i++)
    {
        int L = v[i].l, R = v[i].r;
        while (cur_l < L)
        {
            del(cur_l);
            cur_l++;
        }
        while (cur_l > L)
        {
            add(cur_l - 1);
            cur_l--;
        }
        while (cur_r <= R)
        {
            add(cur_r);
            cur_r++;
        }
        while (cur_r > R + 1)
        {
            del(cur_r - 1);
            cur_r--;
        }
        res[v[i].id] = ans;
    }
    for (auto it : res)
        cout << it << '\n';
    return 0;
}
