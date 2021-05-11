// bipartite
#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V; //vertices
	list<int> *g; //array of list
public:
	Graph(int V) {
		this->V = V;
		g = new list<int>[V];
	}
	void addEdge(int x, int y) {
		g[x].push_back(y);
		g[y].push_back(x);
	}

	bool _bipartite(int node, int parent, int vis[], int color) {
		vis[node] = color;
		for (auto nbrs : g[node]) {
			if (!vis[nbrs] and !_bipartite( nbrs, node, vis, 3 - color)) {
				return false;
			}
			else if (nbrs != parent and color == vis[nbrs])return false;
		}
		return true;
	}

	bool bipartite() {
		int vis[V] = {0}; // 0 not visited,1 color 1 & 2 color 2
		return _bipartite(0, -1, vis, 0);
	}

};


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m; // n vertices m edges
	cin >> n >> m;

	Graph g(n);

	while (m--) {
		int x, y; cin >> x >> y;
		g.addEdge(x, y);
	}

	cout << (g.bipartite() ? "bipartite" : "not bipartite");

	return 0;
}