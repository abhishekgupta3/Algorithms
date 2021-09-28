// Articulation Point and Bridges TC: O(V+E)
#include <iostream>
#include <vector>
using namespace std;

class Graph {
	int V;
	vector<int>* g;
public:

	Graph(int V) {
		this->V = V;
		g = new vector<int>[V];
	}

	void addEdge(int x, int y) {
		g[x].push_back(y);
		g[y].push_back(x);
	}

	int time = 1;

	vector<int>art_pnt;
	vector<pair<int, int>>bridges;

	void dfs(int src, int parent, vector<int>&disc, vector<int>&low) {
		disc[src] = low[src] = time++;
		int no_of_child = 0;

		for (auto nbrs : g[src]) {
			if (disc[nbrs] == 0) {
				no_of_child++;

				dfs(nbrs, src, disc, low);
				low[src] = min(low[src], low[nbrs]);
				// articulation point
				if (parent != 0 && low[nbrs] >= disc[src])art_pnt.push_back(src);
				// bridge
				if (low[nbrs] > disc[src])bridges.push_back({src, nbrs});
			}
			else if (nbrs != parent) {
				// back edge -> cycle found
				low[src] = min(low[src], disc[nbrs]);
			}
		}

		// separate case for root to be an articulation point
		if (parent == 0 and no_of_child >= 2) {
			art_pnt.push_back(src);
		}

		return;
	}

	void articulationPoint() {
		vector<int> disc(V, 0); //discovery time of each node in dfs
		// low[v] -> earliest visited vertex reachable from subtree with root v
		vector<int> low(V);

		dfs(1, 0, disc, low);

		for (auto x : art_pnt)cout << x << " ";
	}
};

int main() {
	
	int n, m, a, b; cin >> n >> m;
	Graph g(n + 5);
	while (m--) {
		cin >> a >> b;
		g.addEdge(a, b);
	}

	g.articulationPoint();

	return 0;
}