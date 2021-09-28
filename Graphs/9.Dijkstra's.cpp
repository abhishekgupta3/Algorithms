// Shortest Path: Dijkstra's Algorithm (Greedy)
// -----------------------------------------------

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

class Graph {
	int V; //vertices
	list<pii>* g; // array of list of type pii
public:
	Graph(int V) {
		this->V = V;
		g = new list<pii>[V]; // (node, weight)
	}
	void addEdge(int x, int y, int w) {
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}

	void Dijkstra(int src = 0) {

		int dist[V]; // distance array
		for (int i = 0; i < V; i++)dist[i] = INT_MAX;
		dist[src] = 0;
		set<pii> s; // (distance,node)
		s.insert({0, src});

		while (!s.empty()) {
			auto parent = *(s.begin());
			s.erase(s.begin());

			int node_dist = parent.first, node = parent.second;

			for (auto nbrs : g[node]) {
				int vertex = nbrs.first, weight = nbrs.second;
				// Relax operation
				if (dist[vertex] > dist[node] + weight) {
					// find in set
					auto f = s.find({dist[vertex], vertex});
					if (f != s.end()) s.erase(f);

					dist[vertex] = dist[node] + weight;
					s.insert({dist[vertex], vertex});
				}
			}
		}

		for (auto x : dist)cout << x << " ";
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

	g.Dijkstra();

	return 0;
}