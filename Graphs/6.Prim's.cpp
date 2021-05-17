// MST: PRIMS ALGORITHM
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

class Graph {
	int V; //vertices
	list<pii> *g; //array of list
public:
	Graph(int V) {
		this->V = V;
		g = new list<pii>[V];
	}
	void addEdge(int x, int y, int w) {
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}

	int prims(int src = 0) {
		bool vis[V] = {0};
		int ans = 0;
		priority_queue<pii, vector<pii>, greater<pii>> pq; // (weight,vertex)

		pq.push({0, src});

		while (!pq.empty()) {

			pii p = pq.top();
			pq.pop();
			int cur = p.second, cur_w = p.first;

			if (vis[cur])continue;
			vis[cur] = true;

			ans += cur_w; cout << cur_w;

			for (auto nbrs : g[cur]) {
				// nbrs - (vertex, weight)
				int adj_w = nbrs.second, adj = nbrs.first;
				if (!vis[adj]) {
					pq.push({adj_w, adj});
				}
			}
		}
		return ans;
	}

};


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output78.txt", "w", stdout);
#endif

	int n, m; // n vertices m edges
	cin >> n >> m;

	Graph g(n);

	while (m--) {
		int x, y, w; cin >> x >> y >> w;
		g.addEdge(x, y, w);
	}

	cout << g.prims() << '\n';


	return 0;
}