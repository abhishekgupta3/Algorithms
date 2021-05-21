// Floyd Warshall: All pair Shortest Path
// T.C: O(n^3) A.S: O(n^2)
// -----------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

void FloydWarshall(vector<vector<int>> g) {
	vector<vector<int>> dist(g);
	int V = g.size();

	for (int k = 0; k < V; k++) {
		// Traverse the adj matrix
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				// Relax opeartion
				if (dist[i][k] != INT_MAX and dist[k][j] != INT_MAX and dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < V; ++j) {
			cout << dist[i][j] << " ";
		}
		cout << '\n';
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<vector<int>> g = {
		{0, INT_MAX, -2, INT_MAX},
		{4, 0, 3, INT_MAX},
		{INT_MAX, INT_MAX, 0, 2},
		{INT_MAX, -1, INT_MAX, 0}
	};

	FloydWarshall(g);

	return 0;
}