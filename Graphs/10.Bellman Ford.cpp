// BELLMAN FORD
// T.C: O(V*E)
// -----------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V; //vertices
	vector<vector<int>> g;
public:
	Graph(int V) {
		this->V = V;
	}
	void addEdge(int x, int y, int w) {
		g.push_back({x, y, w});
	}

	void Bellmanford() {
		int dist[V];
		for (int i = 0; i < V; ++i)	dist[i] = INT_MAX;
		dist[0] = 0;

		for (int i = 0; i < V - 1; i++) {
			// iterating over all edges of graph
			for (auto edge : g) {
				int x = edge[0], y = edge[1], weight = edge[2];
				// Relax operation
				if (dist[x] != INT_MAX and dist[y] > dist[x] + weight)dist[y] = dist[x] + weight;
			}
		}
		// detection of negative weight cycle
		for (auto edge : g) {
			int x = edge[0], y = edge[1], weight = edge[2];
			// Relax operation
			if (dist[x] != INT_MAX and dist[y] > dist[x] + weight) {
				cout << "Negative Weight Cycle Found " << '\n';
				return;
			}
		}


		for (int i = 0; i < V; i++)cout << dist[i] << " ";
		cout << '\n';

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

	g.Bellmanford();

	return 0;
}