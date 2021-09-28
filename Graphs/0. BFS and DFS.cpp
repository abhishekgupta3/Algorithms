// GRAPHS: BFS / DFS
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

	void printAdjList() {
		// iterate over all vertices
		for (int i = 0; i < V ; i++) {
			cout << i << "->";
			for (auto nbrs : g[i]) {
				cout << nbrs << " ";
			}
			cout << '\n';
		}
	}
	void bfs(int src = 0) {
		int dist[V]; //Single Source shortest path using BFS
		memset(dist, -1, sizeof dist);

		queue<pair<int, int>> q; // <node,dist>
		q.push({src, 0});
		dist[src] = 0;

		while (!q.empty()) {
			auto node = q.front();
			int vertex = node.first, d = node.second;
			q.pop();
			cout << vertex << " ";

			for (auto nbrs : g[vertex]) {
				if (dist[nbrs] == -1)q.push({nbrs, d + 1}), dist[nbrs] = d + 1;
			}
		}
		cout << '\n';
		for (int i = 0; i < V; ++i)cout << dist[i] << " ";

		return;
	}

	void _dfs(bool vis[], int src) {
		vis[src] = true;
		cout << src << " ";
		for (auto nbrs : g[src]) {
			if (!vis[nbrs])_dfs(vis, nbrs);
		}
	}

	void dfs() {
		bool vis[V] = {0};
		for (int i = 0; i < V; ++i) {
			if (!vis[i])_dfs(vis, i);
		}
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

	g.bfs(0);
	cout << '\n';
	g.dfs();

	return 0;
}