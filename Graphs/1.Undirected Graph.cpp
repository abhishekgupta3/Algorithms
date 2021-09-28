// undirected graph: cycle/or not
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

	bool _hasCycle(bool vis[], int node, int parent) {
		vis[node] = true;

		for (auto nbrs : g[node]) {
			if (!vis[nbrs]) {
				bool cycle = _hasCycle(vis, nbrs, node);
				if (cycle)return true;
			}
			else if (nbrs != parent)return true;
		}
		return false;
	}

	bool hasCycle() {
		bool vis[V] = {0};
		return _hasCycle(vis, 0, -1);
	}

};


int main() {

	int n, m; // n vertices m edges
	cin >> n >> m;

	Graph g(n);

	while (m--) {
		int x, y; cin >> x >> y;
		g.addEdge(x, y);
	}

	cout << (g.hasCycle() ? "has Cycle" : "no cycle") << endl;

	return 0;
}