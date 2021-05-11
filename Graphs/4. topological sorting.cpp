// topological sorting of Directed Acyclic Graph (DAG) using DFS/BFS
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

	void _dfs(int node, bool vis[], stack<int>& st) {
		vis[node] = true;
		for (auto adj : g[node]) {
			if (!vis[adj])_dfs(adj, vis, st);
		}
		st.push(node);
	}
	// topological sorting using DFS
	void dfs() {
		stack<int> st;
		bool vis[V] = {0};

		for (int i = 0; i < V; ++i) {
			if (!vis[i])_dfs(i, vis, st);
		}

		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
	}
	// topological sort using BFS
	void bfs() {
		int* indegree = new int[V] {0};
		for (int i = 0; i < V; i++) {
			for (auto nbrs : g[i]) {
				indegree[nbrs]++;
			}
		}

		queue<int>q;

		for (int i = 0; i < V; i++)if (indegree[i] == 0)q.push(i);
		while (!q.empty()) {
			int node = q.front();
			cout << node << " ";
			q.pop();
			for (auto nbrs : g[node]) {
				indegree[nbrs]--;
				if (indegree[nbrs] == 0)q.push(nbrs);
			}
		}

		delete [] indegree;
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
	g.dfs();
	cout << '\n';
	g.bfs();


	return 0;
}