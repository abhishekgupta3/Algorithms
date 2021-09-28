// directed graph: cycle/or not
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
	}

	bool _hasCycle(bool vis[], bool recStack[], int node) {
		vis[node] = true;
		recStack[node] = true;

		for (auto nbrs : g[node]) {
			if (!vis[nbrs] and _hasCycle(vis, recStack, nbrs)) {
				return true;
			}
			// back edge
			else if (recStack[nbrs])return true;
		}
		recStack[node] = false;
		return false;
	}

	bool hasCycle() {
		bool vis[V] = {0};
		bool recStack[V] = {0};
		for (int i = 0; i < V; ++i) {
			if (!vis[i]) {
				if (_hasCycle(vis, recStack, i))return true;
			}
		}
		return false;
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

	cout << (g.hasCycle() ? "has Cycle" : "no cycle");

	return 0;
}