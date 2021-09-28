// MST: KRUSKAL (Greedy ALgorithm)
#include <bits/stdc++.h>
#include "DisjointSet.h"
using namespace std;

class Graph {
	int V; //vertices
	vector<vector<int>> g;
public:
	Graph(int V) {
		this->V = V;
	}
	void addEdge(int x, int y, int w) {
		g.push_back({w, x, y});
	}

	int Kruskal() {
		sort(g.begin(), g.end()); //sorting according to weights
		int mst = 0;
		DSU dsu(V);

		for (auto edge : g) {
			int w = edge[0], x = edge[1], y = edge[2];
			// if there is not an edge then consider the weight
			if (dsu.find(x) != dsu.find(y)) {
				dsu.union_set(x, y);
				mst += w;
			}
		}

		return mst;
	}
};


int main() {

	int n, m; // n vertices m edges
	cin >> n >> m;

	Graph g(n);

	while (m--) {
		int x, y, w; cin >> x >> y >> w;
		g.addEdge(x, y, w);
	}
	cout << g.Kruskal();

	return 0;
}